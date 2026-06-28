//Approach-1 using Array simulation
//TC=O(N^2)
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int>temp;
//         for(int i=1;i<=n;i++){
//             temp.push_back(i);
//         }
//         int i=0;
//         while(temp.size()>1){//n
//             int idx=(i+k-1)%temp.size();
//             temp.erase(temp.begin()+idx);//n

//             i=idx;
//         }
//         return temp[0];
//     }
// };

//Approach-2 Using Queue
//TC=O(N*K)
// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int>que;
//         for(int i=1;i<=n;i++){
//             que.push(i);
//         }
//         while(que.size()>1){
//             for(int i=1;i<=k-1;i++){
//                 que.push(que.front());
//                 que.pop();
//             }
//             que.pop();
//         }
//         return que.front();
//     }
// };

//Approach-3 (Using Recursion)
//T.C : O(n)
//S.C : O(1), but note that it will take o(n) system stack space
class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n == 1) {
            return 0; //index
        }

        int idx = findWinnerIdx(n-1, k);
        idx = (idx + k) % n; //to find the original index in the original array

        return idx;
    }

    int findTheWinner(int n, int k) {
        
        int result_idx = findWinnerIdx(n, k);


        return result_idx + 1;

    }
};
