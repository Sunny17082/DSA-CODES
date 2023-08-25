#include <bits/stdc++.h>
using namespace std;
string minimumWindowSubstring(string s,string t)
{
    if (t.length() > s.length()) 
        return "";
    if (s == t)
        return s;
    unordered_map<char,int> map; //to store character and their count in key value pair
    int i=0,j=0,start=-1,end=-1;
    int minSize = INT_MAX; //to store substring of minimum character
    for(auto i:t)
        map[i]++;
    int count = map.size(); //stores number of unique character
    while(j<s.size())
    {
        //if a key is found in the map decrease its count
        if(map.find(s[j])!=map.end()) 
        {
            map[s[j]]--;
            if(map[s[j]]==0) //if a character count is decreased to zero decrease the total count
                count--;
        }
        if(count==0) //if total count is 0 which means required substring is found
        {
            //while count is 0 we can remove extra characters from the front
            while(count==0)
            {
                //calculating the minimum window size
                if(j-i+1<minSize && count==0)
                {
                    start=i;
                    end=j;
                    minSize=j-i+1;
                }
                if(map.find(s[i])!=map.end())
                {
                    map[s[i]]++;
                    if(map[s[i]]>0)
                        count++;
                }
                i++;
            }
        }
        j++;
    }
    string ans="";
    if (start == -1 && end == -1)
        return ans;
    for(int i=start;i<=end;i++)
        ans+=s[i];
    return ans;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minimumWindowSubstring(s,t)<<endl;
    return 0;
}