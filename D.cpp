/*
Task: D
Link: https://atcoder.jp/contests/dp/tasks/dp_d
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
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);

ll rec(vt<int> wt,vt<ll> val,int cap,int n,vt<vt<ll>>& dp){
    if(n==0 || cap==0) return 0;
    if(dp[n][cap]!=-1) return dp[n][cap];
    if(wt[n-1]<=cap) return dp[n][cap] = max(val[n-1]+rec(wt,val,cap-wt[n-1],n-1,dp),rec(wt,val,cap,n-1,dp));
    return dp[n][cap] = rec(wt,val,cap,n-1,dp);
}

int main(){
    FAST1
    FAST2
    int n,w;cin>>n>>w;
    vt<int> wt(n);
    vt<ll> val(n);
    rep(i,n) cin>>wt[i]>>val[i];
    vt<vt<ll>> dp(n+1,vt<ll>(w+1,-1));
    cout<<rec(wt,val,w,n,dp);
    return 0;
}