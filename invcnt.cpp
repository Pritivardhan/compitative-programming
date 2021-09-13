#include<bits/stdc++.h>
using namespace std;
int sum(int idx,int fen[]){
	int res=0;
	while(idx>0){
		res+=fen[idx];
		idx-=(idx&(-idx));
	}
	return res;
}
void update(int idx,int fen[],int val,int n){
	while(idx<=n){
		fen[idx]+=val;
		idx+=(idx&(-idx));
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	int ar[n];
	int maxi=0;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		maxi=max(maxi,ar[i]);
	}
	int fen[maxi+1]={0};
	int left_fre[maxi+1]={0};
	int res=0;
	for(int i=0;i<n;i++){
		res+=sum(maxi,fen)-sum(ar[i],fen);
		update(ar[i],fen,+1,maxi);
	}
	cout<<res<<"\n";
	}
}