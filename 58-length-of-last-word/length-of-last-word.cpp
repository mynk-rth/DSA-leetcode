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

// H e l l o   W o r l d 
// 0 1 2 3 4 5 6 7 8 9 10 