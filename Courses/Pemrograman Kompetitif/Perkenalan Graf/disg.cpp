#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

const int maxe = 2e6+1, maxn = 5e5+1;
bool removed[maxe], visited[maxn];
int special[maxn];
vector <int> adj[maxn];
vector <pair <int, int>> edges;

void reset(){
	for(int i = 0; i < maxe; i++)
		removed[i] = false;
	for(int i = 0; i < maxn; i++){
		visited[i] = false;
		special[i] = 0;
		adj[i].clear();
	}
	edges.clear();
}

ll dfs(int src){
	visited[src] = true;
	ll ans = special[src];
	for(auto dst: adj[src]){
		if(!visited[dst])
			ans += dfs(dst);
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	for(int indeks = 0; indeks < T; indeks++){
		reset();
		int N, E, Q, R;
		cin >> N >> E >> Q >> R;
		for(int i = 0; i < E; i++){
			int src, dst;
			cin >> src >> dst;
			src--; dst--;
			edges.pb(mp(src, dst));
			adj[src].pb(dst);
			adj[dst].pb(src);
		}
		for(int i = 0; i < Q; i++){
			int tmp;
			cin >> tmp;
			tmp--;
			special[tmp] = 1;
		}
		ll ans = 0;
		for(int i = 0; i < N; i++){
			if(!visited[i]){
				ll total = dfs(i);
				if(total > 1)
					ans += total*(total-1) >> 1;
			}
		}
		memset(visited, false, sizeof(visited));
		for(int i = 0; i < R; i++){
			int tmp;
			cin >> tmp;
			tmp--;
			removed[tmp] = true;
		}
		for(int i = 0; i < N; i++)
			adj[i].clear();
		for(int i = 0; i < E; i++){
			if(!removed[i]){
				adj[edges[i].first].pb(edges[i].second);
				adj[edges[i].second].pb(edges[i].first);
			}
		}
		for(int i = 0; i < N; i++){
			if(!visited[i]){
				ll total = dfs(i);
				if(total > 1)
					ans -= total*(total-1) >> 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

// Code by codefire52
// https://tlx.toki.id/profiles/codefire52