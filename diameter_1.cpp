// Created by Pjha
#include <bits/stdc++.h>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define dbV(arr) for(auto i:arr) cout << i << " "; cout << '\n';
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repF(i,a,n) for(int i = (a); i <= (n); ++i)
#define repB(i,a,n) for(int i = (a); i >= (n); --i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define umii unordered_map<int,int>
#define umll unordered_map<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define seti set<int>
#define setl set<ll>
#define pb push_back
#define F first
#define S second
#define MOD 998244353
#define all(z) z.begin(),z.end()
using namespace std;
using ll = long long;
int fact[100001];
int ifact[100001];
int mul(int a, int b) {
	ll res = 1LL * a * b;
	return res % MOD;
}
int add(int a, int b) {
	ll res = a + b;
	return res % MOD;
}
int power(int n, int p) {
	int res = 1;
	while (p > 0) {
		if (p & 1) res = mul(res, n);
		n = mul(n, n);
		p >>= 1;
	}
	return res;
}
int nCr(int n, int r) {
	if (r > n) return 0;
	return mul(ifact[n - r], mul(fact[n], ifact[r]));
}
int vis[200002];
int daim(vector<int> adj[],int s,int &len){
	queue<pair<int,int> > q;
	q.push({s,0});
	vis[s]=1;
	int farthest=s;
	 len=0;
	while(!q.empty()){
		int siz=q.size();
		//cout<<siz<<"\n";
		for(int i=1;i<=siz;i++){

			auto temp=q.front();
			q.pop();
			int l=temp.S;
			int n=temp.F;
			//cout<<n<<" "<<l<<"\n";
			if(l>len){
				len=l;
				farthest=n;

			}
			for(auto it:adj[n]){
				if(vis[it]==0){
				q.push({it,l+1});
				vis[it]=1;
			}
			}
		}
	}
	return farthest;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
    cin>>t;
    vector<int> adj[t+1];
    int x=t-1;
    while(x--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    
    memset(vis,0,sizeof(vis));
    int len=0;
   int u=daim(adj,1,len); 
   // cout<<u<<" "<<len<<"\n";
     memset(vis,0,sizeof(vis));
     len=0;

     int v=daim(adj,u,len);
     cout<<len<<"\n";


	return 0;
}