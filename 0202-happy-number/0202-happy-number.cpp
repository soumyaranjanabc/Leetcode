class Solution {
public:
    int sumOfNum(int n){
        int num=0;
        while(n>0){
            int digit=n%10;
            num+=digit*digit;
            n/=10;
        }
        return num;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast = sumOfNum(n);
        while(fast!=1 && slow!=fast){
            slow=sumOfNum(slow);
            fast=sumOfNum(sumOfNum(fast));
        }
        return fast==1;

        

    }
};