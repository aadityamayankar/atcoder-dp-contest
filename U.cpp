/*
Task: U
Link: https://atcoder.jp/contests/dp/tasks/dp_u
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
#define MOD 1000000007
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
#define gnr(i,a,b) for(int i=int(a)-1;i>=int(b);i--)
#define gne(i,a,b) for(int i=int(a);i>int(b);i--)
#define per(i,b) gnr(i,0,b)
#define FASTIO ios::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

vt<vt<ll>> mat;
int n;

ll dp[20][1 << 20];

ll rec(int i,int mask){
    if(i == n || mask == 0) return 0ll;
    if(dp[i][mask] != -1) return dp[i][mask];
    ll cur = 0ll;
    if(mask & (1 << i) != 0){
        rep(j,n){
            if(mask & (1 << j) != 0){
                int _mask = mask;
                mask = mask & ~(1 << j);
                mask = mask & ~(1 << i);
                cur = max(cur,mat[i][j] + rec(i+1,mask));
                mask = _mask;
            }
        }
    }
    return dp[i][mask] = cur;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    mat = vt<vt<ll>> (n,vt<ll>(n));
    rep(i,n) rep(j,n) cin>>mat[i][j];
    ll res = rec(0,(1 << n) - 1);
    cout<<res<<'\n';
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "a", stderr);
    #endif
    FASTIO
    
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<'\n'<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
    return 0;
}