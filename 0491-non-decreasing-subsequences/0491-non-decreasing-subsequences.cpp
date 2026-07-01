class Solution {
public:
    vector<vector<int>>result;
    int n;
    void backtrack(vector<int>&temp,vector<int>&nums,int idx){
        if(temp.size()>=2){
            result.push_back(temp);
        }
        unordered_set<int>st;
        for(int i=idx;i<n;i++){
            if((temp.empty() || nums[i]>=temp.back()) && (st.find(nums[i])==st.end())){
                temp.push_back(nums[i]);
                backtrack(temp,nums,i+1);
                temp.pop_back();

                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        n=nums.size();
        backtrack(temp,nums,0);
        return result;
    }
};