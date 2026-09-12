class Solution {
public:
    bool isSubsequence(string s, string t) {

        string ans;
        int z=0;

        for (char ch : s){
            for (int i=z; i<t.size(); i++){
                if ( ch == t[i]){
                    ans.push_back(ch);
                    z = i+1;
                    break;
                }
            }
        }
        return s==ans;       //aaaaaa == aaaa XX
    }
};