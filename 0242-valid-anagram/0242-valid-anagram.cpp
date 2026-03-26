class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int charCounts[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            charCounts[(unsigned char)s[i]]++;
            charCounts[(unsigned char)t[i]]--;
        }
        for (int count : charCounts) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
