class Solution {
public:
    string smallestPalindrome(string s) {
        int len = s.length();
        if(len<=3)
        {
            return s;
        }
        int half = len/2;
        int count[26]={0};
        for(int i = 0; i < half; i++)
        {
            count[s[i]-97]++;
        }
        for(int i = 1; i < 26; i++)
        {
            count[i] = count[i] + count[i-1]; 
        }
        string out(len, ' ');
        int ind;
        for(int i = 0; i < half; i++)
        {
            ind = count[s[i]-97] -1;
            out[ind] = s[i];
            out[len-ind-1] = s[i];
            count[s[i]-97]--;
        }
        if(len%2 != 0)
            out[half] = s[half];
        return out;
    }
};