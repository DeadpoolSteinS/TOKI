#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar//_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

const int LG = 18;
int N = 2, H[200005], sps[200005][LG];

void process(int u){
	H[u] = H[sps[u][0]]+1;
	for(int i = 0; i < LG-1; i++){
		if(sps[u][i])
			sps[u][i+1] = sps[sps[u][i]][i];
		else
			break;
	}
}

int LCA(int u, int v){
	if(H[u] > H[v])
		swap(u, v);
	for(int i = LG-1; H[v]-H[u]; i--){
		if(H[v]-H[u] >= (1 << i))
			v = sps[v][i];
	}
	for(int i = LG-1; i >= 0; i--){
		if(sps[v][i] != sps[u][i]){
			v = sps[v][i];
			u = sps[u][i];
		}
	}
	if(u != v){
		u = sps[u][0];
		v = sps[v][0];
	}
	return u;
}

int main(){
	int Q, opsi, X, Y, Z;
	scan(Q);
	while(Q--){
		scan(opsi);
		if(opsi == 1){
			scan(X);
			sps[N][0] = X;
			process(N++);
		}
		else{
			scan(X); scan(Y); scan(Z);
			int p = LCA(X, Y), q = LCA(p, Z), r = LCA(Z, X);
			printf("%d-%d-%d\n", p, q, r);
			if(p != q)
				printf("%d\n", p);
			else if(r != p)
				printf("%d\n", r);
			else
				printf("%d\n", LCA(Z, Y));
		}
	}
	return 0;
}

// Code by Berted and iafir
// https://tlx.toki.id/profiles/Berted
// https://tlx.toki.id/profiles/iafir
// LCA berguna untuk menemukan nenek moyang yang sama pada dua pihak