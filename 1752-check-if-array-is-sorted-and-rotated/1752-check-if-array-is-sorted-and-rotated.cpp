class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int drop=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                drop++;
            }
        }
        if(nums[0]<nums[n-1]){
                drop++;
        }
        if(drop>1){
            return false;
        }
        return true;
        
    }
};