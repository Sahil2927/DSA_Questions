class Solution {
public:
    int n;
    int t[201][1001];
    int solve(int idx,vector<int>&nums, int target){
        if(target==0) return 1;
        if(idx>=n || target<0){
            return 0;
        }
        // MEMOIZATION LOOKUP: If we already calculated this state, return it instantly.
        if(t[idx][target]!=-1){
            return t[idx][target];
        }
        int take_idx=solve(0,nums,target-nums[idx]);
        int not_take_idx=solve(idx+1,nums,target);

        return t[idx][target]=take_idx+not_take_idx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,target);
    }
};

//Approach-2
class Solution {
public:
    // Only target changes, so we only need a 1D memo array
    int t[1001]; 

    int solve(vector<int>& nums, int target) {
        // Base cases
        if (target == 0) return 1;
        if (target < 0) return 0;
        
        // Memoization check
        if (t[target] != -1) return t[target];
        
        int total_ways = 0;
        
        // Try every single number in the array for the current step
        for (int i = 0; i < nums.size(); i++) {
            total_ways += solve(nums, target - nums[i]);
        }
        
        // Store and return
        return t[target] = total_ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};
