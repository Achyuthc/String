/* Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.*/


class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,size=s.size(),cnt=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;i-j>=0&&i+j+1<size;j++)
            {
                if(s[i-j]!=s[i+j+1])
                    break;
                ans++;
            }
        
            for(int j=0;i-j>=0&&i+j<size;j++)
            {
                if(s[i-j]!=s[i+j])
                    break;
                ans++;
            }
            
        }
        return ans;
        
    }
};
