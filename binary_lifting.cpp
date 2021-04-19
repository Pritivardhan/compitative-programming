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
int main(){
	int n,q;
	cin>>n>>q;
	vector<int> adj[n+1];
	adj[1].pb(1);
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		adj[i].pb(x);
		adj[x].pb(i);
	}

	dfs(adj,1,1,1);
	//cout<<"\n";
	int lift[n+1][18];
	binary_lift(adj,1,1,lift);
	/*for(int i=1;i<=n;i++)
		cout<<level[i]<<" ";*/
	//cout<<"\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		if(level[x]<y+1)
			cout<<-1<<"\n";
		else
		cout<<kth_parent(lift,x,y)<<"\n";
	}

}