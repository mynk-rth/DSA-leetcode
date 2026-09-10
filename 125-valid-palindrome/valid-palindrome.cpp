class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for (char i : s){
               if(isalnum(i)){
                  ans.push_back(tolower(i));
            }
        
        }
        string Reverse = ans;
        reverse(Reverse.begin(), Reverse.end());

        if ( ans == Reverse){
            return true;
        }
        else {
            return false;
        }
    }
};