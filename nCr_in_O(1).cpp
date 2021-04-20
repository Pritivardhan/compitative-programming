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
#define MOD 1000000001
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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	ifact[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		fact[i] = mul(fact[i - 1], i);
		ifact[i] = mul(ifact[i - 1], power(i, MOD - 2));
	}
	int t; cin >> t;
	while (t--) {
		int n, r; cin >> n >> r;
		cout << nCr(n, r) << '\n';
	}
	return 0;
}