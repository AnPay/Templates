## Domain Resources

- https://newsletter.maartengrootendorst.com/p/a-visual-guide-to-quantization
- https://huggingface.co/datasets/Ujjwal-Tyagi/ai-ml-foundations-book-collection/tree/main
- https://www.deep-ml.com/collections
- https://apxml.com/courses/prompt-engineering-agentic-workflows

## From now on, every problem must include a written section BEFORE coding:
- Pattern:
- State:
- Transition:
- Edge cases:
- Time complexity:

## How To Force Yourself To Find Invariant

- Before coding, ask:
- What am I maintaining? 
- What must always be true?
- What property makes this approach correct?

## Before coding: Force yourself to list:

- Empty input?
- Single element?
- All equal?
- Strictly increasing/decreasing?
- Negative numbers?
  
## Sliding Window:
- Expand
- Fix
- Shrink


## Stack:
- NGE, NSE
- Increasing/Decreasing stack with pair<elem,idx>


## For any tree problem, ask:
- What should recursion return to parent?
- What should be computed locally?
- Do I need global variable?

## From now on, before coding any problem, do this 60-second ritual:

### Step 1 — Say Pattern Out loud:

- This is sliding window because ___
- Invariant is ___

### Step 2 — Define State / What Returns

- For trees/DP:
  - dfs returns ___
  - dp[i] means ___

### Step 3 — Write Edge Case First
  - empty input?
  - single element?
  - all negative?
  - sorted?

Only then code.

### Step4 :
  - When do I update answer:
