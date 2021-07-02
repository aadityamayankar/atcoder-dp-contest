/*
Task: I
Link: https://atcoder.jp/contests/dp/tasks/dp_i
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

double prob_of_heads(vt<ld>coins,int n){
    vt<vt<ld>> dp(n+1,vt<ld>(n+1,0));
    dp[0][0] = 1;
    rng(i,1,n+1){
        rep(j,i+1){
            if(j>0) dp[i][j] += dp[i-1][j-1] * (1.0 - coins[i-1]);
            dp[i][j] += dp[i-1][j] * coins[i-1];
        }
    }
    double res = 0.0;
    rep(i,1+n/2) res += dp[n][i];
    return res;
}

int main(){
    FAST1
    FAST2
    int n;cin>>n;
    vt<ld> coins(n);
    rep(i,n) cin>>coins[i];
    cout<<fixed<<setprecision(10)<<prob_of_heads(coins,n);
    return 0;
}