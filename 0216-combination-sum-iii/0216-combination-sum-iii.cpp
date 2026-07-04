class Solution {
public:
    vector<vector<int>>result;
    void solve(int val,int k,int n,vector<int>&temp){
        if (temp.size() == k && n == 0) {
            result.push_back(temp);
            return;
        }
        if (temp.size() >= k || n < 0) {
            return;
        }
        for(int i=val;i<=9;i++){
            temp.push_back(i);
            solve(i+1,k,n-i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(1,k,n,temp);
        return result;
    }
};