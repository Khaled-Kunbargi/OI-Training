/*
============================
vis[i][0] = max(u) such that (u<k and u can reach i)
vis[i][1] = min(u) such that (u<k and u can reach i with backward edges)
============================
3 2 2
1 2
1 0 
ans: 1
==
1 1 1
0 0
ans: 0
==
12 8 4
11 1
10 9 
9 8 
2 9
8 7
4 5
7 3
5 6
ans: 6
==
12 9 4
11 1
10 9 
9 8 
2 9
8 7
4 5
5 6
7 3
9 1
ans: 8
==
5 4 4
4 3
1 3
2 4
4 1
ans: 3 
*/
#include "game.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back

const int N=5e5+10,OO=2e9;
vi adj[N][2];
int vis[N][2];
int n,k;
void init(int cn, int ck){
  n=cn,k=ck;
  for(int i=0;i<k;++i){
    vis[i][0]=vis[i][1]=i;
  }
  for(int i=k;i<n;++i)vis[i][0]=-1,vis[i][1]=OO;
}
void dfs(int x,int j,int val){
  if(j && vis[x][j]<=val) return;
  if(!j && val<=vis[x][j]) return; 
  vis[x][j]=val;
  for(int i:adj[x][j]){
    dfs(i,j,val);
  }
}
int add_teleporter(int u, int v){
  adj[u][0].pb(v);
  adj[v][1].pb(u);
  dfs(v,0,vis[u][0]); 
  dfs(u,1,vis[v][1]);
  return (vis[v][1] <= vis[u][0]);
}
