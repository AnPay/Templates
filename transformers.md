🧠 SECTION A — Must-Know (1–25)
1. What is the main idea behind the Transformer?
2. What are the main components of a Transformer?
3. What does one encoder layer consist of?
4. What does one decoder layer consist of?
5. Why is masking used in the decoder?
6. What is Query, Key, and Value?
7. What is scaled dot-product attention?
8. Why do we divide by √dₖ?
9. Why is it called “dot-product” attention?
10. What does softmax do in attention?
11. What is multi-head attention?
12. Why use multiple heads?
13. How is multi-head attention computed?
14. What is the dimensionality trick in multi-head attention?
15. Why do we need positional encoding?
16. What is sinusoidal positional encoding?
17. Why sinusoidal instead of learned?
18. What is the feed-forward network?
19. Why use residual connections?
20. What is Layer Normalization?
21. What loss function is used?
22. What is teacher forcing?
23. What is label smoothing?
24. Why do we use embeddings + linear projection at output?
25. What is the computational complexity advantage of Transformers?
🧠 SECTION B — Medium Level (26–50)
26. In scaled dot-product attention, why does increasing dₖ without scaling lead to unstable training?
27. If you remove softmax and use raw attention scores, what happens?
28. Why not use a single attention head instead of multi-head attention?
29. Why is transpose applied to K and not Q in attention?
30. Why is masking not required in encoder self-attention but required in decoder self-attention?
31. If all tokens attend mostly to themselves, what does it indicate?
32. Why does attention have O(n²) complexity, and which operation causes it?
33. What happens if positional encoding is removed?
34. Why is the feed-forward network applied independently per token?
35. Why are residual connections important for deep Transformers?
36. How does attention model long-range dependencies better than RNNs?
37. What does each row of the softmax(QKᵀ) represent?
38. Why share embedding and output projection weights?
39. What role does encoder-decoder attention play in translation?
40. What happens if attention becomes very peaked?
41. Why is RoPE applied only to Q and K but not V?
42. What is the intuition behind splitting into multiple heads?
43. Why do we cache K and V but not Q during inference?
44. How does memory scale when sequence length doubles?
45. Why compute full attention matrix and then apply masking?
46. What happens if softmax is replaced with sigmoid in attention?
47. Why is normalization (LayerNorm/RMSNorm) critical?
48. What does strong off-diagonal attention indicate?
49. Why does multi-head attention improve expressivity?
50. How does GQA improve inference efficiency?
🧠 HARD LEVEL QUESTIONS (Set 1)
🔥 Attention Math + Behavior
51. If all Q and K vectors are identical, what will the attention matrix look like after softmax? What will be the output?

52. If Q and K are orthogonal for all token pairs, what happens to attention distribution?

3. Consider removing the scaling factor √dₖ.
Instead, you initialize weights with smaller variance.
Will that fully solve the problem? Why or why not?

4. Why is softmax applied row-wise and not column-wise in attention?

5. If we replace:

softmax(QKᵀ)

with:

(QKᵀ) / T

(average instead of softmax), what breaks?

🔥 Multi-Head + Representation
6.

Suppose all attention heads learn identical projections.
What does multi-head attention reduce to?

7.

Why is concatenation used after multi-head attention instead of averaging heads?

8.

Can multi-head attention be simulated by a single head with larger dimension?
If yes, why still use multi-head?

🔥 Positional Encoding / RoPE
9.

Why does RoPE allow better extrapolation to longer sequences compared to learned positional embeddings?

10.

In RoPE, what happens if you apply rotation to V as well? What breaks?

11.

Why does RoPE encode relative position information implicitly?

🔥 KV Cache + Inference (VERY IMPORTANT FOR YOU)
12.

During decoding, why does attention complexity per token reduce from O(T²) to O(T)?

13.

If KV cache is not used, what is the exact redundant computation happening?

14.

In GQA, how does sharing K/V across heads affect attention quality vs efficiency tradeoff?

15.

Why does KV cache size become a bottleneck for long-context LLMs?

🔥 Numerical / Shape Reasoning
16.

Given:

B = 1
T = 1024
h = 32
d_head = 128

Estimate memory required for attention matrix (QKᵀ) in float16.

17.

Why does Flash Attention reduce memory without changing mathematical output?

🔥 Training Stability
18.

Why do Transformers without normalization fail to train beyond a few layers?

19.

Why is label smoothing important specifically for sequence models?

20.

What happens if residual connections are removed entirely?

🔥 Conceptual Traps
21.

Does attention actually “focus” on words like humans do? Or is that an interpretation artifact?

22.

Why is attention not symmetric even though it uses dot products?

23.

If we shuffle tokens after embedding but before attention, what happens (with and without positional encoding)?

24.

Can attention weights alone fully explain model predictions?

25.

Why do early layers show diagonal attention while deeper layers show more complex patterns?
