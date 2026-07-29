class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int low = 0, high = m;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = totalLeft - i;   // FIXED

            int Aleft  = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft  = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];   // FIXED

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if ((m + n) % 2 == 1) {
                    return (double)max(Aleft, Bleft);
                } else {
                    return ((double)max(Aleft, Bleft) + (double)min(Aright, Bright)) / 2.0;
                }
            } 
            else if (Aleft > Bright) {
                high = i - 1;
            } 
            else {
                low = i + 1;
            }
        }
return 0.0; 
    }
};