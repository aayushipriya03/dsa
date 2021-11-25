 int maxSubArray(vector<int>& nums) {
        int rem=nums[0];
         int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            rem=max(nums[i],nums[i]+rem);
            res=max(res,rem);
        }
        return res;
        
    }