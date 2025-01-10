class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int rem=INT_MAX;
      int res;  
      sort(nums.begin(),nums.end());
       int len=nums.size();
        for(int i=0; i<len;i++)
        {
            int j=i+1;
            int k=len-1;
            
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(rem)> abs(target-sum))
                {  
                    rem=sum-target;
                }  
                if(sum==target)
                {
                    return target;
                }
                else
                { 
                  (sum>target)?k--:j++
                       
                }
                
                
            }
               
            
        }
        return target+rem;
    }
};