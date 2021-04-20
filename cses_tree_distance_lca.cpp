#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int level[200001];

void dfs(vector<int> adj[],int s,int l,int par){
	//cout<<s<<" ";
	level[s]=l;
	for(auto it:adj[s]){
			if(it!=par){
				dfs(adj,it,l+1,s);
			}
	}
}
void binary_lift(vector<int> adj[],int s,int par,int lift[][18]){
	lift[s][0]=par;
	for(int i=0;i<17;i++){
		lift[s][i+1]=lift[lift[s][i]][i];
	}
	for(auto it:adj[s]){
		if(it!=par){
			binary_lift(adj,it,s,lift);
		}
	}
}
int kth_parent(int lift[][18],int s,int k){
	int i=0;
	int res=s;
	while(k){
		if(k%2==1){
			res=lift[s][i];
			s=res;
		}
		i++;
		k/=2;
	}
	return res;
}
int lca(int u,int v,int lift[][18]){
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	u=kth_parent(lift,u,diff);     // make u and v at same level;
	if(u==v)
		return u;
	for(int i=17;i>=0;i--){                //itrate till last parent of u and v is not equal.
		if(lift[u][i]!=lift[v][i]){
			u=lift[u][i];
			v=lift[v][i];
		}
	}
	return lift[u][0];

}

int main(){
	int n,q;
	cin>>n>>q;
	vector<int> adj[n+1];
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(adj,1,1,1);
	//cout<<"\n";
	int lift[n+1][18];
	binary_lift(adj,1,1,lift);
	
	while(q--){
		int x,y;
		cin>>x>>y;
		int dist1=lca(x,y,lift);
		int res=level[x]+level[y]-(2*level[dist1]);
		cout<<res<<"\n";
	}

}