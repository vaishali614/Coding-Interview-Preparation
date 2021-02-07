/** Partition equal subset sum **/
/*
Similar to knapsack problem. If the array contains a subset with sum = (arrSum / 2), then it's possible, otherwise not. Also, if the total sum is odd, it's never possible.
*/

class Solution {
public:
    bool check(vector<int>& nums, int sum){
        int n = nums.size();
        bool dp[sum + 1];
        
        dp[0] = true;
        
        for(int i = 1; i <= sum; i++)
            dp[i] = false;
        
        for(int i = 0 ; i < n; i++){
            for(int j = sum; j >= nums[i]; j--){
                if(dp[j - nums[i]])
                    dp[j] = true;
            }
        }
        
        return dp[sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums){
            sum += val;
        }
        
        if(sum & 1)
            return false;
        
        return check(nums, sum / 2);
    }
};
