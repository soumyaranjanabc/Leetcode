class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ngeMap;
        stack<int> st;

        int n2=nums2.size();
        for(int i=n2-1;i>=0;i--){
            int current = nums2[i];
            while(!st.empty()&& st.top()<=current){
                st.pop();

            }
            ngeMap[current] = st.empty() ? -1:st.top();
            st.push(current);
        }
        vector<int> result;
        for(int num:nums1){
            result.push_back(ngeMap[num]);
        }
        return result;
        
    }
};