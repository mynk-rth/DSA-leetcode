class Solution {
public:
    int firstUniqChar(string s) {
        // sort(s.begin(),s.end());

        unordered_map<char,int> frequency;
        
        for (int i=0; i<s.size(); i++){
            frequency[s[i]]++;
        }

        for (int j=0; j<s.size(); j++){
            if(frequency[s[j]]==1){
                return j;
            }
        }


        return -1;
        
    }
};