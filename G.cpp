/*
Task: G
Link: https://atcoder.jp/contests/dp/tasks/dp_g
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
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);

int dfs(vt<vt<int>> adj,int root,vt<int>& dp){
    if(dp[root]!=-1) return dp[root];
    int mx = 0;
    rep(i,sz(adj[root])){
        mx = max(mx,1+dfs(adj,adj[root][i],dp));
    }
    return dp[root] = mx;
}

int longestPath(vt<vt<int>> adj,int n){
    vt<int>dp(n,-1);
    int res = INT_MIN;
    rep(i,n){
        res = max(res,dfs(adj,i,dp));
    }
    return res;
}

int main(){
    FAST1
    FAST2
    int n,m;cin>>n>>m;
    vt<vt<int>> adj(n);
    rep(i,m){
        int x,y;cin>>x>>y;
        adj[x-1].pb(y-1);
    }
    cout<<longestPath(adj,n);
    return 0;
}