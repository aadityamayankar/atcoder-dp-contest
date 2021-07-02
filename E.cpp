/*
Task: E
Link: https://atcoder.jp/contests/dp/tasks/dp_e
*/

#include <bits/stdc++.h>
using namespace std;

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

const ll INF = 1e18L + 5;

void minWt(vt<ll> wt,vt<int> val,int n,int total_val,vt<vt<ll>>& dp){
    rng(i,1,n+1){
        rng(j,1,total_val+1){
            if(j-val[i-1]>=0) dp[i][j] = min(wt[i-1]+dp[i-1][j-val[i-1]],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
}

int maxVal(vt<ll> wt,vt<int> val,int n,int cap){
    int total_val = accumulate(all(val),0);
    vt<vt<ll>> dp(n+1,vt<ll>(total_val+1,INF));
    rep(i,n+1) dp[i][0] = 0;
    minWt(wt,val,n,total_val,dp);
    gnr(i,total_val+1,0){
        if(dp[n][i]<=cap) return i;
    }
    return -1;
}

int main(){
    FAST1
    FAST2
    int n;cin>>n;
    ll w;cin>>w;
    vt<ll> wt(n);
    vt<int> val(n);
    rep(i,n) cin>>wt[i]>>val[i];
    cout<<maxVal(wt,val,n,w);
    return 0;
}