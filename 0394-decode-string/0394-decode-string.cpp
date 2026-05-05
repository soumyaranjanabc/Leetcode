class Solution {
public:
    string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString = "";
    int currentNum = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');
        } else if (c == '[') {
            countStack.push(currentNum);
            stringStack.push(currentString);
            currentNum = 0;
            currentString = "";
        } else if (c == ']') {
            int repeatCount = countStack.top();
            countStack.pop();
            string prevString = stringStack.top();
            stringStack.pop();
            
            string temp = "";
            for (int i = 0; i < repeatCount; ++i) {
                temp += currentString;
            }
            currentString = prevString + temp;
        } else {
            currentString += c;
        }
    }
    return currentString;
        
    }
};