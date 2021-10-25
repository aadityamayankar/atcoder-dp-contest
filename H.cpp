/*
Task: H
Link: https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <bits/stdc++.h>
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

int dp[1001][1001];

int rec(vt<vt<char>>& grid,int n,int m){
    if(n == 1 && m == 1) return 1;
    if(n == 0 || m == 0 || grid[n-1][m-1] == '#') return 0;
    if(dp[n][m] != -1) return dp[n][m];
    return dp[n][m] = (rec(grid,n-1,m) + rec(grid,n,m-1)) % M;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    int h,w;cin>>h>>w;
    vt<vt<char>> grid(h,vt<char>(w));
    rep(i,h) rep(j,w) cin>>grid[i][j];
    cout<<rec(grid,h,w)<<'\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FAST1
    FAST2
    
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}
