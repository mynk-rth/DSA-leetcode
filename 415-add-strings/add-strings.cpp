class Solution {
public:
    string addStrings(string num1, string num2) {
       
       reverse(num1.begin(),num1.end());
       reverse(num2.begin(),num2.end());

       string ans;

       int max_len = max(num1.size(),num2.size());
       num1.resize(max_len, '0');
       num2.resize(max_len, '0');
       int carry = 0;


       for ( int i=0; i<max_len; i++ ){
        int digit = (num1[i] - '0') + (num2[i] - '0') + carry;

        if (digit>=10){
            digit = digit-10;
            carry = 1;
        }else{
            carry = 0;
        }

        ans.push_back(digit + '0');
       }
       if (carry){
          ans.push_back(1 + '0');
       }

       reverse(ans.begin(),ans.end());
       return ans;

    }
};