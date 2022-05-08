/*Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //kmp algorithm
        vector<int> pref(needle.size()+1);
        int i=0,j=1;
        pref[i]=0;
        while(j<needle.size())
        {
            if(needle[i]==needle[j])
            {
                i++;
                pref[j]=i;
            }
            else
            {
                while(i!=0&&needle[i]!=needle[j])
                {
                    //cout<<i<<" ";
                    i=pref[i-1];
                }
                if(needle[i]==needle[j])
                {
                    i++;
                    pref[j]=i;
                }
                else
                    pref[j]=0;
            }
            j++;
        }
        j=0;
        i=0;
        while(j<haystack.size())
        {
            if(haystack[j]==needle[i])
            {
                i++;
            }
            else
            {
               while(i!=0&&needle[i]!=haystack[j])
                {
                    i=pref[i-1];
                }
                if(needle[i]==haystack[j])
                {
                    i++;
                }
            }
            if(i==needle.size())
                return j-(needle.size()-1);
            j++;
        }
        return -1;
        
    }
};
