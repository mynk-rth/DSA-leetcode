class Solution {
public:
    int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int total = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            int curr = getValue(s[i]);
            if (i + 1 < n && curr < getValue(s[i + 1])) {
                total -= curr;
            } else {
                total += curr;
            }
        }
        
        return total;
    }
};