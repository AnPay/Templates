- vLLM
- TensorRT-LLM
- Triton Inference Server
- DeepSpeed Inference
- Ray Serve


- Paged attention

  ## Prepare strong project stories

### You should be ready to explain:

- quantization pipeline
  - “I follow a structured pipeline: I start with model preparation and baseline evaluation, then run calibration to compute activation ranges. I simulate quantization using fake quant nodes and evaluate accuracy. If there’s degradation, I apply optimizations like cross-layer equalization, bias correction, and mixed precision. If needed, I use QAT to recover accuracy. Finally, I export the quantized model aligned with hardware constraints like INT8 execution on NPUs. The entire process is iterative and driven by latency vs accuracy tradeoffs.”
  - “During calibration, we estimate activation ranges using statistics collected over a representative dataset. The simplest method is min-max, but it is highly sensitive to outliers. So instead, we often use techniques like percentile-based clipping or histogram-based methods to better capture the distribution. The key issue is that if the range is too wide due to outliers, most values get compressed into a small portion of the quantization space, leading to poor resolution and high quantization error. On the other hand, aggressive clipping can discard important information, also hurting accuracy. So calibration is essentially about finding the right tradeoff between covering the dynamic range and maintaining resolution.”
  - “In transformer models like LLaMA and T5, the most sensitive components are typically:
      - Attention layers, especially:
        - Query-Key matmul (QKᵀ)
        - Softmax
        - These are sensitive because small quantization errors in Q and K get amplified in the dot product, and softmax is highly non-linear, so even small perturbations can significantly change attention weights.
      - Early layers (closer to input)
        - Errors here propagate through the entire network, so quantization noise accumulates.
      - Output layers / LM head
        - These directly affect token probabilities, so precision loss impacts final predictions.
      - Sometimes FFN layers (especially large ones)
        - Because they have high dynamic range activations, making them harder to quantize without clipping issues.

So in practice, we often keep attention or certain critical layers in higher precision or use per-channel quantization to preserve accuracy.”

# Your quantized model works well in offline evaluation, but on-device latency is still high and inconsistent. How would you debug and fix this?

“If offline accuracy is good but on-device latency is high and inconsistent, I would approach this systematically.

1. High-level approach
   - First, I would profile the on-device execution to identify where the latency is coming from—whether it’s compute, memory, or scheduling related.

2. Possible causes
Operator fallback: Some ops may not be supported on NPU and fall back to CPU/GPU
Unsupported quantization scheme: Certain bitwidths or asymmetric quantization may not be efficiently supported
Memory bottlenecks: Poor memory layout or cache misses (e.g., KV cache inefficiency)
Threading / scheduling issues: Suboptimal parallelism or blocking operations
Data movement overhead: Frequent transfers between CPU, GPU, and NPU

3. Fixes

Ensure all critical ops run on NPU by modifying unsupported ops (model surgery)
Align quantization scheme with hardware constraints (e.g., symmetric INT8)
Optimize memory access patterns and reduce unnecessary data movement
Improve threading and introduce async execution where possible
Fuse operators or simplify graph to reduce kernel launches

4. Validation
After each fix, I would re-profile to confirm improvements and ensure latency is stable.

Tradeoff
Optimizations like op replacement or fusion may slightly impact accuracy or increase engineering complexity, so I would balance latency gains against these costs.”

```Python
import numpy as np

def calculate_scale_zero_point(min_val, max_val, num_bits=8):
    qmin = 0
    qmax = (1 << num_bits) - 1  # 255 for 8-bit

    # Compute scale
    scale = (max_val - min_val) / (qmax - qmin)

    # Avoid division by zero
    if scale == 0:
        return 1.0, 0

    # Compute zero-point
    zero_point = qmin - min_val / scale
    zero_point = int(round(zero_point))

    # Clamp zero_point
    zero_point = max(qmin, min(qmax, zero_point))

    return scale, zero_point


def quantize(x, scale, zero_point, num_bits=8):
    qmin = 0
    qmax = (1 << num_bits) - 1

    # Quantize
    q_x = np.round(x / scale + zero_point)

    # Clamp to valid range
    q_x = np.clip(q_x, qmin, qmax)

    return q_x.astype(np.uint8)


def dequantize(q_x, scale, zero_point):
    return scale * (q_x.astype(np.float32) - zero_point)

x = np.array([-1.0, 0.0, 1.0, 2.0])

scale, zp = calculate_scale_zero_point(x.min(), x.max())

q = quantize(x, scale, zp)
dq = dequantize(q, scale, zp)

print("Original:", x)
print("Quantized:", q)
print("Dequantized:", dq)
```


- KV cache optimization

- edge inference on NPU
```C++
/*
“Execution inside ModelEngine would dispatch attention and MLP ops to NPU, while tokenizer and sampling remain on CPU.”
*/
Class SmallLLMPipeline{
private:
  SimpleTokenizer tokenizer;
  SimpleModelEngine model;
  SimpleKVCache kvcache;
  SimpleSampler sampler;
  int max_gen;
  int eos_token;
  int batch_size;

public:
  SmallLLMPipeline(std::string embedding_bin, int max_gen, int EOS, int batch,int num_layers,
                     int num_heads,
                     int head_dim,
                     int max_seq_len):
    tokenizer(embedding_bin),kv_cache(num_layer, num_head,head_dim,max_seq_len),
    max_gen(max_gen),eos_token(eos),batch_Size(batch){
    std::cout<<"PipelineInitialized\n";
  }

  std::string Generate(std::string prompt, int max_tokens=512)
  {
  //Input Preparation
  std::vector<int>tokens = tokenizer.encode(prompt);
  std::cout<<toekns.size();

  //prefil phase
  /*
  “During prefill we populate KV cache for the full prompt, and during decode we only process one token while reusing cached keys and values.”
*/
  std::vector<float> logits = model.prefill(tokens,kvcache)
  int first_token = sampler.GreddySample(logits);
  std::cout<<"First token"<<first_token<<"\n";
  std::vector<int>generated_tokens;
  generated_tokens.reserve(max_tokens);  //Memory optimization hint
  generated_tokens.push_back(first_token);
  int current_token = first_token;
  //AR mode
  for( int i =0;i<max_tokens;i++)
  {
    std::vector<int> logits = model.decode(current_token,kvcache)
    current_token = sampler.GreddySample(logits);
    generated_tokens.push_back(current_token);
    if(curent_token == EOS)
      break;
    if(generated_token.size()==max_gen)
      break;
  }
  //Output Decoding
  std::string output = tokenizer.decode(generated_toekns);
  return output;
}
};
int main(){
  int max_gen = 512;
  int EOS = 2;
  int batch = 1
  SmallLLMPipeline pipeline - SmallLLMPipeline("path to embedding bin", max_gen, EOS, batch );
  std::string prompt = "Steps to design a LLM pipeline";
  std::string output = pipeline.Generate(prompt,50);
  std::cout<<"Prompt:"<<prompt<<"\n";
  std::cout<<"Output:"<<output<<"\n;
  return 0;
}
```

- Structure each story as:

    - problem
    - constraints
    - approach
    - tradeoffs
    - results
