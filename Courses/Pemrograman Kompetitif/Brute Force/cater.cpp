#include <cstdio>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, M, matrix[25][25], indeks, warna, maks;
bool help[25][25];

void solve(int B, int K){
	if(!help[B][K] && matrix[B][K] == warna){
		indeks++;
		help[B][K] = true;
		if(K != M-1)
			solve(B, K+1);
		if(B != N-1)
			solve(B+1, K);
		if(K != 0)
			solve(B, K-1);
		if(B != 0)
			solve(B-1, K);
	}
}

int main(){
	int B, K;
	scan(N); scan(M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scan(matrix[i][j]);
		}
	}
	int i = 0;
	while(i < N){
		int j = 0;
		while(!help[i][j] && j < M){
			warna = matrix[i][j];
			indeks = 0;
			solve(i, j);
			if(maks < indeks)
				maks = indeks;
			j++;
		}
		i++;
	}
	printf("%d\n", maks * (maks-1));
	return 0;
}