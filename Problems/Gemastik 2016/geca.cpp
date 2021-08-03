#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int maks = 5e4+5;
int indeks[maks], pa[3], pb[3], sa[3], sb[3];
string nama[maks];
ll G[maks], C[maks], ans;
vector <int> num;

bool cmp_g(int a, int b){
	return G[a]>G[b];
}

bool cmp_c(int a, int b){
	return C[a]>C[b];
}

void dfs(int i, int gn, int cn, ll gv, ll cv){
	if(gn == 3 && cn == 3){
		if(gv+cv > ans){
			ans = gv+cv;
			for(int i = 0; i < 3; i++){
				pa[i] = sa[i];
				pb[i] = sb[i];
			}
		}
		return;
	}
	if(i == num.size())
		return;
	if(gn+1 <= 3){
		sa[gn] = num[i];
		dfs(i+1, gn+1, cn, gv*G[num[i]], cv);
	}
	if(cn+1 <= 3){
		sb[cn] = num[i];
		dfs(i+1, gn, cn+1, gv, cv*C[num[i]]);
	}
	dfs(i+1, gn, cn, gv, cv);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> nama[i] >> G[i] >> C[i];
			indeks[i] = i;
		}
		num.clear();
		sort(indeks, indeks+N, cmp_g);
		for(int i = 0; i < 6; i++)
			num.pb(indeks[i]);
		sort(indeks, indeks+N, cmp_c);
		for(int i = 0; i < 6; i++)
			num.pb(indeks[i]);
		sort(num.begin(), num.end());
		num.resize(distance(num.begin(), unique(num.begin(), num.end())));
		ans = 0;
		dfs(0, 0, 0, 1, 1);
		printf("%lld\n", ans);
		printf("%s %s %s\n", nama[pa[0]].c_str(), nama[pa[1]].c_str(), nama[pa[2]].c_str());
		printf("%s %s %s\n", nama[pb[0]].c_str(), nama[pb[1]].c_str(), nama[pb[2]].c_str());
	}
	return 0;
}

// Code by iafir
// https://tlx.toki.id/profiles/iafir