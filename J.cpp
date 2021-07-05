/*
Task: J
Link: https://atcoder.jp/contests/dp/tasks/dp_j
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


ld solve(){
    int n;cin>>n;
    vt<int> nums(n);
    int one = 0, two  = 0, three = 0;
    rep(i,n){
        cin>>nums[i];
        if(nums[i]==1) one++;
        if(nums[i]==2) two++;
        if(nums[i]==3) three++;
    }
    int mxone = one+two+three;
    int mxtwo = two+three;
    int mxthree = three;
    vt<vt<vt<ld>>> dp(n+1,vt<vt<ld>>(n+1,vt<ld>(n+1,(ld)0.0L)));
    for(int k=0;k<mxthree+1;k++){
        for(int j=0;j<mxtwo+1-k;j++){
            for(int i=0;i<mxone+1-j-k;i++){
                if(i+j+k!=0){
                    dp[i][j][k] = (ld)n/(i+j+k);
                    if(i) dp[i][j][k] += (ld)(dp[i-1][j][k] * i)/(i+j+k);
                    if(j) dp[i][j][k] += (ld)(dp[i+1][j-1][k] * j)/(i+j+k);
                    if(k) dp[i][j][k] += (ld)(dp[i][j+1][k-1] * k)/(i+j+k);
                }
            }
        }
    }
    return dp[one][two][three];
}

int main(){
    FAST1
    FAST2
    int t = 1;
    while(t--){
        cout<<setprecision(14)<<solve();
    }
    return 0;
}