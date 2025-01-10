#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int maxLength(vector<string>& arr)
{
    vector<bitset<26>> dp{bitset<26>()};
 
    for( auto& e: arr)
    {  bitset<26> temp{0};
        for( auto& c: e)
        {
            temp.set(c-'a');
        }
        if(temp.count()<e.size()){
            continue;
        }
        
        for (int i = dp.size() - 1; i >= 0; --i) 
        {
            if((temp & dp[i]).any())
            {
                continue;        
            }
            dp.push_back(temp|dp[i]);
          
        }

    }
    int max=0;
    for(auto& e: dp)
    {
      max=max>e.count()?max:e.count();
    }

return max;
}
};