/*
4
0 1 1 
0 2 2
0 3 3
ans: 6 3 1 0 
==
7
0 1 3 
1 2 4
2 3 2
3 4 1 
4 5 5
5 6 2
ans: 17 8 0 0 0 0 0
==
2 
0 1 3
ans: 3 0
==
3
0 1 3
1 2 2
ans: 5 2 0 
*/
#include "roads.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<ll>  
#define pi pair<ll,ll>
#define pb push_back
#define sz(x) ((ll)x.size())
#define sp ' '
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define rep(i,x,n) for(ll i=x; i<=n; ++i)
#define For(i,n) rep(i,0,n-1)   
#define ff first 
#define ss second
#define ld long double
#define mp make_pair

const ll mxN=6e5+10,OO=2e9,mod=1e9+7;
ll exp(ll b,ll p){
  ll res=1;
  while(p>0){
    if(p&1)res=res*b%mod;
    b=b*b%mod;
    p/=2;
  }
  return res;
}
const int dx[]{0,0,-1,1}, dy[]{1,-1,0,0};

void cmn(int &a,int b){a = min(a,b);}
void cmx(int &a,int b){a = max(a,b);}

ll dp[mxN];
vector<ll> minimum_closure_costs(int N, vector<int> U,vector<int> V,vector<int> W) {
  ll sum=0;
  For(i,N-1){
    dp[i]=W[i]; sum+=W[i];
    if(i<=1);
    else dp[i]+=min(dp[i-1],dp[i-2]);
    //cout<<dp[i]<<sp;
  } //cout<<endl;
  vi ans{sum}; ans.pb(N==2?0:min(dp[N-2],dp[N-3]));
  For(_,N-2)ans.pb(0);
  return ans;
}
