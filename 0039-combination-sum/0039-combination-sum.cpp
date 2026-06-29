class Solution {
public:
    vector<vector<int>>result;
    int n;
    void solve(vector<int>&temp,vector<int>& candidates, int target,int idx,int sum){
        // Base case 1: Found a valid combination
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        
        // Base case 2: Exceeded target or reached end of array
        if (sum > target || idx >= n) {
            return;
        }
        temp.push_back(candidates[idx]);
        solve(temp,candidates,target,idx,sum+candidates[idx]);
        temp.pop_back();
        solve(temp,candidates,target,idx+1,sum);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        n=candidates.size();
        solve(temp,candidates,target,0,0);
        return result;
    }
};

//Approach 2
// class Solution {
// private:
//     void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates, int target, int start) {
//         if (target == 0) {
//             result.push_back(temp);
//             return;
//         }

//         for (int i = start; i < candidates.size(); i++) {
//             if (candidates[i] <= target) {
//                 temp.push_back(candidates[i]);
//                 // Pass 'i' instead of 'i + 1' to allow reusing the same element
//                 backtrack(result, temp, candidates, target - candidates[i], i); 
//                 temp.pop_back(); // Backtrack
//             }
//         }
//     }

// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int> temp;
//         backtrack(result, temp, candidates, target, 0);
//         return result;
//     }
// };
