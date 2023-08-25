#include <bits/stdc++.h>
using namespace std;
int longestSubstringWithoutRepeatingCharacter(string s)
{
    //here the condition is that every window must have same unique character as the window size
    //to be without repeating
    unordered_map<char,int> map; //to store char and their count in key value pair
    int i=0,j=0;
    int maxSize = INT_MIN;
    while(j<s.size())
    {
        map[s[j]]++; //increasing the count of character
        if(map.size()==j-i+1)
            maxSize = max(maxSize,j-i+1); //finding the maximum substring among each window
        //if the unique character count is below the window size it must contain a repeating character
        else if(map.size()<j-i+1) 
        {
            //remove the character from front until same unique character is achieved as of window
            while(map.size()<j-i+1) 
            {
                map[s[i]]--;
                if(map[s[i]]==0)
                    map.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return maxSize;
}
int main()
{
    string s;
    cin>>s;
    cout<<longestSubstringWithoutRepeatingCharacter(s)<<endl;
    return 0;
}