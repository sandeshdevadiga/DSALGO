class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int writept=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[writept]=nums[i];
                ++writept;
            }
        }
        return writept;
        
    }
};