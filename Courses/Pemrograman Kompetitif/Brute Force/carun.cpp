#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, M, indeks, maks, X, Y;
bool help[25][25];
char matrix[25][25], warna;

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

void runtuh(int B, int K){
	swap(matrix[B][K], matrix[B+1][K]);
	if(B > 0)
		runtuh(B-1, K);
}

void hilang(int B, int K){
	if(matrix[B][K] == warna){
		matrix[B][K] = '.';
		if(K != M-1)
			hilang(B, K+1);
		if(B != N-1)
			hilang(B+1, K);
		if(K != 0)
			hilang(B, K-1);
		if(B != 0)
			hilang(B-1, K);
	}
}

int main(){
	int B, K;
	scan(N); scan(M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf(" %c", &matrix[i][j]);
		}
	}//input papan
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!help[i][j]){
				warna = matrix[i][j];
				indeks = 0;
				solve(i, j);
				if(maks < indeks){
					maks = indeks;
					X = i;
					Y = j;
				}
			}
		}
	}//mencari maksimal
	warna = matrix[X][Y];
	hilang(X, Y);//menghilangkan maksimal
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M; j++){
			if(matrix[i][j] != '.' && matrix[i+1][j] == '.')
				runtuh(i, j);
		}
	}//meruntuhkan
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%c", matrix[i][j]);
			if(j < M-1)
				printf(" ");
		}
		printf("\n");
	}//menampilkan hasil
	return 0;
}