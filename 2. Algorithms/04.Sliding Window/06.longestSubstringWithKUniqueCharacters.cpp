#include <bits/stdc++.h>
using namespace std;
int longestSubstringWithKUniqueCharacter(string s,int k)
{
    unordered_map<char,int> map; //to store char and their count in key value pair
    int maxSize = INT_MIN; 
    int i=0,j=0;
    while(j<s.size())
    {
        map[s[j]]++; //increasing the count of character
        if(map.size()<k)
            j++;
        else if(map.size()==k)
        {
            maxSize = max(maxSize,j-i+1); //finding the maximum substring among each window
            j++;
        }
        else if(map.size()>k)
        {
            while(map.size()>k) //until unique elements is less than k
            {
                map[s[i]]--; //decrease the count of element from starting index
                if(map[s[i]]==0) //if count of an element becomes 0
                    map.erase(s[i]); //remove it from the map
                i++;
            }
            j++;
        }
    }
    return maxSize;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<longestSubstringWithKUniqueCharacter(s,n)<<endl;
    return 0;
}