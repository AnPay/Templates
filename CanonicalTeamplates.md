## Binary Search – Lower Bound (First ≥ Target)
```C++
int lowerBound(vector<int>& nums, int target) {
    int l = 0, r = nums.size();  // r = n

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;  // first index >= target
}
```
## Binary Search - Exact Search
```C++
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
```
## Binary Search on Answer Space
```C++
bool feasible(vector<int>& nums, int mid) {
    // define monotonic condition
}

int solve(vector<int>& nums) {
    int l = 1, r = 1e9;  // problem-specific bounds

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (feasible(nums, mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}
```
## Sliding Window – Longest Valid Window
### (Shrink when invalid)
```C++
int longestSubarray(vector<int>& nums) {
    int l = 0, ans = 0;

    for (int r = 0; r < nums.size(); r++) {

        // add nums[r]

        while (/* window invalid */) {
            // remove nums[l]
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}
- Use for:
  - Longest substring without repeating
  - Longest sum ≤ k
```
## Sliding Window – Minimum Window
### Shrink when valid)

```C++
int minWindow(vector<int>& nums) {
    int l = 0, ans = INT_MAX;

    for (int r = 0; r < nums.size(); r++) {

        // add nums[r]

        while (/* window valid */) {
            ans = min(ans, r - l + 1);

            // remove nums[l]
            l++;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}
```

## Monotonic stack- Next Greater Elemnt
```C++
vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
Rule:
  - For next greater → maintain decreasing stack.
```

## Tree DFS - height pattern
```C++
int height(TreeNode* root)
{
  if(!root) return 0;
  int left = height(root->left);
  int right = height(root->right);
  return 1+max(left,right);
}
```

## Tree – Diameter Pattern
```C++
int diameter =0;
int dfs(TreeNode* root)
{
  if(!root) return 0;
  int left = dfs(root->left);
  int right = dfs(root->right);
  diameter = max(diameter,left+right);
  return 1+max(lh,rh);
}
```
## Tree – Max Path Sum Pattern

```C++
int max_sum = INT_MIN;
int dfs(TreeNode* root)
{
  if(!root) return 0;
  int lSum = max(0,dfs(root->left));
  int rSum = max(0,dfs(root->right));
  max_sum = max(max_sum, lSum+rSum+root->val);
  return root->val+max(lSum,rSum);
}
```

## 1D DP – House Robber Template 
```C++
int rob(vector<int> &nums)
{
  int n = nums.size();
  if(n==1) return nums[0];
  vector<int>dp(n,0);
  dp[0]=0;
  dp[1]=max(dp[0],dp[1]);
  for(int i =2;i<n;i++)
  {
      dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
  }
  return dp[n-1]; 
}
State:
- dp[i] = max money from 0..i
```

## Subsets / Combinations (Pick or Skip Forward)
Used when:

- Order does NOT matter
- Each element used at most once
- We move forward only

## Examples:

- Subsets
- Subsets II
- Combinations
- Combination Sum II

```C++

void bt(vector<int>& nums, vector<int>& curr, int start)
{
    res.push_back(curr);

    for(int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);      // choose
        bt(nums, curr, i + 1);        // move forward
        curr.pop_back();              // unchoose
    }
}
```
## Combination Sum (Reuse Allowed)

Used when:
- Same element can be reused
- Order does NOT matter
- Need to satisfy target sum

# Examples:
- Combination Sum
- Coin change style problems
- 
```C++
void bt(vector<int>& nums, int target, vector<int>& curr, int start)
{
    if(target == 0)
    {
        res.push_back(curr);
        return;
    }

    if(target < 0)
        return;

    for(int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);          
        bt(nums, target - nums[i], curr, i);  // reuse allowed
        curr.pop_back();
    }
}
```
## Permutations (Used Array)

Used when:
- Order matters
- Each element used once
Examples:
- Permutations
- Permutations II

```C++
  void bt(vector<int>& nums, vector<int>& curr, vector<bool>& used)
{
    if(curr.size() == nums.size())
    {
        res.push_back(curr);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(used[i]) continue;

        used[i] = true;
        curr.push_back(nums[i]);

        bt(nums, curr, used);

        curr.pop_back();
        used[i] = false;
    }
}
```
