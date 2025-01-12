class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      
        int writeindex=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[writeindex-1])
            {
                nums[writeindex]=nums[i];     
                writeindex++;
               
            }
        }
        return writeindex;
    }
};