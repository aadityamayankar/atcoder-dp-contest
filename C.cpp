/*
Task: C
Link: https://atcoder.jp/contests/dp/tasks/dp_c
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

void maxPoints(vt<vt<int>> mat,int n,vt<int>& dp){
    rng(i,1,n){
        vt<int> temp(3,0);
        rep(j,3){
            rep(k,3){
                if(j!=k) temp[j] = max(temp[j],dp[k]+mat[i][j]);
            }
        }
        dp = temp;
    }
}

int main(){
    FAST1
    FAST2
    int n;cin>>n;
    vt<vt<int>> mat(n,vt<int>(3));
    rep(i,n) rep(j,3) cin>>mat[i][j];
    vt<int> dp(all(mat[0]));
    maxPoints(mat,n,dp);
    cout<<*max_element(all(dp));
    return 0;
}