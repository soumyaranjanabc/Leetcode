class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maximum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maximum = max(maximum,(nums[i]-1)* (nums[j]-1));

            }
        }
        return maximum;
    }
};