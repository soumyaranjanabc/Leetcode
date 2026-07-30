class Solution {
public:
    int minimumPushes(string word) {
        int totalPushes = 0;
        int lettersMapped = 0;
        for (int i = 0; i < word.length(); ++i) {
            int pushMultiplier = (lettersMapped / 8) + 1;
            totalPushes += pushMultiplier;
            lettersMapped++;
        }

        return totalPushes;
        
    }
};