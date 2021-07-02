/*
Task: A
Link: https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e9+5
#define M 1000000007
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);


int minCost(vt<int>& h,int n,vt<int>& dp){
    rng(i,2,n+1){
        if(i>2) dp[i] = min(abs(h[i-1]-h[i-3])+dp[i-2],abs(h[i-1]-h[i-2])+dp[i-1]);
        else dp[i] = abs(h[i-1]-h[i-2])+dp[i-1];
    }
    return dp[n];
}

int main(){
    FAST1
    FAST2
    int n;cin>>n;
    vt<int> h(n);
    rep(i,n) cin>>h[i];
    vt<int> dp(n+1,0);
    cout<<minCost(h,n,dp);
    return 0;
}
