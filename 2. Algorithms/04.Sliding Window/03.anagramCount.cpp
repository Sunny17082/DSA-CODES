#include <bits/stdc++.h>
using namespace std;
int anagramCount(string ptr, string s)
{
    unordered_map<char,int> map; //to store each character of ptr in key value pair
    for(auto i:ptr)
        map[i]++;
    int k = ptr.size(); //window size is equal to ptr string
    int count = map.size(); //number of keys in map
    int i=0,j=0,ans=0;
    while(j<s.size())
    {
        if(map.find(s[j])!=map.end()) //if the element is found before the end of the map
            map[s[j]]--; //decrement the value of that char
        if(map[s[j]]==0) //if value of a char is 0
            count--; //decrement count of total character
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            if(count==0) //if count is 0 it is an anagram
                ans++;
            if(map.find(s[i])!=map.end()) //to remove first char from the window
                map[s[i]]++; //increment the value if present
            if(map[s[i]]==1) //if a char is present 
                count++; //increment the count of total character
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string ptr,s;
    cin>>ptr>>s;
    cout<<anagramCount(ptr,s)<<endl;
    return 0;
}