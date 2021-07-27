#include <cstdio>
#include <vector>
using namespace std;
#define gc getchar_unlocked
#define pb push_back
#define mp make_pair
#define f first
#define s second

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int papan[105][105];
vector <pair <pair <int, int>, int>> jalan;

void solve(int a, int b, int c){
	papan[a][b] = -1;
	jalan.pb(mp(mp(a, b), c));
}

int main(){
	int N, M;
	scan(N); scan(M);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scan(papan[i][j]);
		}
	}
	int X, Y;
	scan(X); scan(Y);
	jalan.pb(mp(mp(X, Y), 1));
	while(!jalan.empty()){
		int gerakan = jalan.front().s;
		while(jalan.front().s == gerakan && !jalan.empty()){
			int a = jalan.front().f.f;
			int b = jalan.front().f.s;
			int c = jalan.front().s;
			if(a == 1 || a == N || b == 1 || b == M){
				printf("%d\n", c);
				return 0;
			}
			jalan.erase(jalan.begin());
			if(papan[a+1][b] == 0)
				solve(a+1, b, c+1);
			if(papan[a-1][b] == 0)
				solve(a-1, b, c+1);
			if(papan[a][b+1] == 0)
				solve(a, b+1, c+1);
			if(papan[a][b-1] == 0)
				solve(a, b-1, c+1);

		}
	}
	return 0;
}