# Softmax

- The softmax is helpful here for three reasons. First, it converts our de-embedding results vector from an arbitrary set of values to a probability distribution. As probabilities, it becomes easier to compare the likelihood of different words being selected and even to compare the likelihood of multi-word sequences if we want to look further into the future.
- Second, it thins the field near the top. If one word scores clearly higher than the others, softmax will exaggerate that difference, making it look almost like an argmax, with the winning value close to one and all the others close to zero. However, if there are several words that all come out close to the top, it will preserve them all as highly probable, rather than artifically crushing close second place results.
- Third, softmax is differentiable, meaning we can calculate how much each element of the results will change, given a small change in any of the input elements. This allows us to use it with backpropagation to train our transformer.


# Cross attention
- Cross-attention works just like self-attention with the exception that the key matrix K and value matrix V are based on the output of the final encoder layer, rather than the output of the previous decoder layer. The query matrix Q is still calculated from the results of the previous decoder layer. This is the channel by which information from the source sequence makes its way into the target sequence and steers its creation in the right direction

# In self-attention, the computation is O(n²). Why is it O(n²), and what problems does this cause in practice?

- “Self-attention has O(n²) complexity because each token attends to every other token in the sequence.
- If the sequence length is n, we compute attention scores using QKᵀ, which results in an n × n matrix. Each entry represents the interaction between a pair of tokens.
- So effectively, we are computing pairwise interactions between all tokens, leading to O(n²) time and memory complexity.
- In practice, this becomes a bottleneck for long sequences because:
  - Memory grows quadratically due to the attention matrix
  - Computation becomes expensive, increasing latency

- This is why scaling transformers to long contexts is challenging and requires optimizations like sparse attention or KV caching.”

  # If self-attention is O(n²), how do modern models like LLaMA handle long sequences efficiently during inference?
  
  - “During inference in models like LLaMA, computation is divided into two phases: prefill and decode.
  - In the prefill phase, the full input sequence is processed, so self-attention still has O(n²) complexity.
  - In the decode phase, tokens are generated one at a time. Instead of recomputing attention over all previous tokens, we use KV caching, where we store the key and value tensors from previous steps.
  - For each new token, we only compute its query and attend to the cached K and V. This reduces the per-token complexity from O(n²) to O(n), since we avoid recomputing attention for previous tokens.
  - Additionally, for long sequences, we can use optimizations like sliding window attention, paged attention for better memory management, and speculative decoding to improve latency.”
 
    # KV cache improves latency, but increases memory usage. How would you design a system to handle KV cache efficiently for long sequences?
    - “KV cache improves latency by avoiding recomputation, but it introduces a memory bottleneck since it grows linearly with sequence length.
    - To handle this efficiently, I would use a combination of techniques:
      - Memory reduction techniques
          - Quantize KV cache (e.g., INT8 or lower precision) to reduce memory footprint
          - This trades off some accuracy for significant memory savings

      - Memory management optimizations
        - Use paged attention, which manages KV cache in blocks to avoid memory fragmentation and improve memory locality
      - Context reduction techniques
        - Use sliding window attention or token eviction to limit attention to recent tokens
        - This bounds KV cache size and reduces compute
      - Hybrid attention patterns
        - Combine local and global attention, where most layers use local context and some layers capture global dependencies
      - Tradeoff
        - These approaches balance memory, latency, and accuracy—reducing KV cache size may impact long-range dependencies, so the system needs to be tuned based on application requirements.”
