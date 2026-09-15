class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for ( int i=s.size()-1 ; i>=0; i--){
            if ( s[i] != ' ' ){
                word = s[i] + word;
            }
            else {
                if (word.empty()){
                    continue;
                }
                else{
                    ans = ans + word + ' ';
                    word = "";
                }
            }
        }
        if (!word.empty()){
            ans = ans + word;
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};