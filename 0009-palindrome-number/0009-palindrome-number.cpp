class Solution {
public:
    bool isPalindrome(int x) {
        // if (x < 0) {
        //     return false;
        // }
        long long reverse=0;
        int original=x;
        while(x>0){
            int m=x%10;
            x=x/10;
            reverse=(reverse*10)+m;
        }
        if(original==reverse){
            return true;
        }

        return false;
        
        
    }
};