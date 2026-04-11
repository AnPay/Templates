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
