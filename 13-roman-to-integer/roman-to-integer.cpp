class Solution {
public:
    int romanToInt(string s) {

        int ans = 0;
        
        unordered_map<string, int> roman = {
            {"I", 1},
            {"IV",4},
            {"V", 5},
            {"IX",9},
            {"X", 10},
            {"XL",40},
            {"L", 50},
            {"XC",90},
            {"C", 100},
            {"CD",400},
            {"D", 500},
            {"CM",900},
            {"M", 1000}
        };
    
        for ( int len=0; len<s.size(); len++){
            string ch = s.substr(len, 2);
            if ( roman.count(ch) ){
                ans += roman[ch];
                len++;
                }
            else{
                ch = s.substr(len, 1);
                if ( roman.count(ch) ){
                    ans += roman[ch];
                }
                }
            }
        
        return ans;



            
    }
};