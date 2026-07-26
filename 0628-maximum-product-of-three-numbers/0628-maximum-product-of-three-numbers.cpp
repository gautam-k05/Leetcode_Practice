class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int l1=-1000,l2=-1000,l3=-1000,s1 = 1000,s2=1000;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]>l1)
            {
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            }
            else if(nums[i]>l2)
            {
                    l3 = l2;
                    l2 = nums[i];
            }
            else if(nums[i]>l3)
                l3 = nums[i];

            if(nums[i]<s1)
            {
                s2 = s1;
                s1 = nums[i];
            }
            else if(nums[i]<s2)
                s2 = nums[i];
        }
        int prod;
        if(l1<0)
            prod = l1*l2*l3;
        else if(s1<0 && s2<0 && s1*s2 > l2*l3)
        {
            prod = l1*s1*s2;
        }
        else
        {
            prod = l1*l2*l3;
        }
        return prod;
    }
};