## Array

- Prefix Sum
- Kadane / Max Subarray
- Sliding Window (fixed)
- Sliding Window (variable)
- Hashing + Prefix (subarray sum type)

| Problem             | Pattern               |
| ------------------- | --------------------- |
| Top K Frequent      | Hashmap + Heap        |
| Encode Decode       | String encoding       |
| Longest Consecutive | HashSet               |
| Valid Sudoku        | Constraint hashing    |
| Group Anagrams      | Hashmap canonical key |

## Monotonic Stack

- Next Greater Element
- Daily Temperatures
- Stock Span
- Largest Rectangle in Histogram
- Trapping Rain Water (stack version)

All same family.

| Problem              | Stack Type |
| -------------------- | ---------- |
| Next Greater Element | Decreasing |
| Daily Temperatures   | Increasing |
| Stock Span           | Decreasing |
| Largest Rectangle    | Increasing |

                Backtracking Problem
                        |
             ------------------------
             |                      |
       Order matters?           No order
             |                      |
         Permutations          Reuse allowed?
                                   |
                        ---------------------
                        |                   |
                      Yes                  No
                        |                   |
                Combination Sum       Subsets / Combinations
