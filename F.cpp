/*
Task: F
Link: https://atcoder.jp/contests/dp/tasks/dp_f
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
#define len(x) (int)(x).length()
#define each(x, a) for (auto& x: a)
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define FAST1 ios::sync_with_stdio(0);
#define FAST2 cin.tie(0);

string lcs(string x,string y,int n,int m,vt<vt<int>>& dp){
    rep(i,n+1){
        rep(j,m+1){
            if(i==0 || j==0) dp[i][j] = 0;
            else{
                if(x[i-1]==y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string res = "";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            i--;j--;
            res += x[i];
        }
        else if(dp[i-1][j]>=dp[i][j]) i--;
        else j--;
    }
    return res;
}

int main(){
    FAST1
    FAST2
    string x,y;cin>>x>>y;
    int n = len(x), m = len(y);
    vt<vt<int>> dp(n+1,vt<int>(m+1));
    string res = lcs(x,y,n,m,dp);
    reverse(all(res));
    cout<<res;
    return 0;
}