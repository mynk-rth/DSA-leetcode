class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int size = s.size();
        for (int i=size-1 ; i>=0 ; i--){
            if (s[i] != ' '){
                len++;
            }
            else if(len != 0 && s[i] == ' '){
                return len;
            }
           
        }
        return len;              // <-- missing
    }
};