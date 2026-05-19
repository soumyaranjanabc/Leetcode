class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        if (nums.size() == 0) return ans;

        // lower bound
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // check if target exists
        if (lb == nums.size() || nums[lb] != target)
            return ans;

        // upper bound
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        ans[0] = lb;
        ans[1] = ub - 1;

        return ans;
        
    }
};