class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int n=nums.size();
        int max_val=n-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        return nums[n-1]==max_val;
    }
};