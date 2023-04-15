#include <bits/stdc++.h>
using namespace std;

{//RECURSION
int solve(vector<int> &cost, int n) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }

    int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));

    return ans;
}

//MEMOISATION
int solve2(vector<int> &cost, int n, vector<int> &dp) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));

    return dp[n];
}

//TABULATION
int solve3(vector<int> &cost, int n) {
    vector<int> dp(n + 1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

//SO
int solve4(vector<int> &cost, int n) {
    int prev1 = cost[1];
    int prev2 = cost[0];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost) {

    int n = cost.size();
    vector<int> dp(n + 1, -1);
    // int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
    // int ans = solve3(cost,n);
    int ans = solve4(cost, n);

    return ans;
}

}

//memoization
int fib(int n){
    if(n <= 1){
        return n;
    }

//    if(dp[n] != -1){
//        return dp[n];
//    }
//
//    dp[n] = fib(n-1,dp) + fib(n-2,dp);
//
//    return dp[n];

    return fib(n-1) + fib(n-2);

    //Tabulisation
//    int n=5;
//    vector<int> dp(n+1);
//
//    dp[0] = 0;
//    dp[1] = 1;
//
//    for(int i=2; i<=n; i++){
//        dp[i] = dp[i-1] + dp[i-2];
//    }
//
//    cout<<dp[n];

    //Space optimization
//    int prev1,prev2;
//    prev1 = 1;
//    prev2 = 0;
//
//    int n=10;
//
//    for(int i=2; i<=n; i++){
//        int curr = prev1 + prev2;
//        prev2 = prev1;
//        prev1 = curr;
//    }
//
//    cout<<prev1;

    cout<<fib(5);
}