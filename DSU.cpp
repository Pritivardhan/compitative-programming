#include<bits/stdc++.h>
using namespace std;
int rank_[100001];
int par[100001];
void makeset(int n){
	for(int i=1;i<=n;i++){
		par[i]=i;
		rank_[i]=0;
	}
}
int find_parent(int u){
	if(par[u]==u)
		return u;
	return par[u]=find_parent(par[u]);
}
void union_(int u,int v){

	
	u = find_parent(u);
    v = find_parent(v); 
    if(u!=v){
    if(rank_[u] < rank_[v]) {
        par[u] = v; 
    }
    else if(rank_[u] > rank_[v]) {
        par[v] = u; 
    }
    else {
        par[u] = v;
        rank_[v]++; 
    }
}
} 
int main(){
	
	int n,m;
	
	cin>>n>>m;
	makeset(n);
	while(m--){
		string str;
		int u,v;
		cin>>str>>u>>v;
		if(str=="union"){
			union_(u,v);
		}
		else{
			int x=find_parent(u);
			int y=find_parent(v);
			if(x==y)
				cout<<"YES\n";
			else 
				cout<<"NO\n";
		}
	}
}