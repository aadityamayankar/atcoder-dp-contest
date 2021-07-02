/*
Task: H
Link: https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1e9+5
#define MOD 1000000007
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

bool isWall(vt<string> grid,int i,int j){
    return grid[i][j]=='#';
}

int pathCount(vt<string> grid,int h,int w){
    if(isWall(grid,0,0) || isWall(grid,h-1,w-1)) return 0;
    vt<vt<int>> dp(h,vt<int>(w,0));
    dp[0][0] = 1;
    rep(i,h){
        rep(j,w){
            if(!isWall(grid,i,j)){
                if(i>0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                if(j>0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    return dp[h-1][w-1];
}

int main(){
    FAST1
    FAST2
    int h,w;cin>>h>>w;
    vt<string> grid(h);
    rep(i,h) cin>>grid[i];
    cout<<pathCount(grid,h,w);
    return 0;
}

