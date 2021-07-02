/*
Task: B
Link: https://atcoder.jp/contests/dp/tasks/dp_b
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
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define per(i,a) gnr(i,a,0)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);

int rec(vt<int>& h,int n,int k,vt<int>& dp){
    if(n<=1) return 0;
    int res = INF;
    if(dp[n]!=-1) return dp[n];
    gnr(i,n,n-k){
        if(i>0) res = min(res,abs(h[n-1]-h[i-1])+rec(h,i,k,dp));
    }
    return dp[n] = res;
}

int main(){
    FAST1
    FAST2
    int n,k;cin>>n>>k;
    vt<int> h(n);
    rep(i,n) cin>>h[i];
    vt<int>dp(n+1,-1);
    cout<<rec(h,n,k,dp); 
    return 0;
}