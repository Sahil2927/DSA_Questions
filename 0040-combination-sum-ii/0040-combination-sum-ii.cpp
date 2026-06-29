class Solution {
public:
    vector<vector<int>>ans;
    int n;

    void solve(vector<int>&temp,vector<int>& candidates, int target,int ind){
        if(target==0){
            ans.push_back(temp);
        }
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            solve(temp,candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(),candidates.end()); 
        solve(temp,candidates,target,0);
        return ans;
    }
};