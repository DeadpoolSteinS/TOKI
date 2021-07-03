#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, M, maks = 0, satu, dua, tiga;
bool help[25][25], tolong[25][25];
char matrix[25][25], kloning[25][25], warna;

void cek(int B, int K){
	if(!tolong[B][K] && matrix[B][K] == warna){
		tiga++;
		tolong[B][K] = true;
		if(K != M-1)
			cek(B, K+1);
		if(B != N-1)
			cek(B+1, K);
		if(K != 0)
			cek(B, K-1);
		if(B != 0)
			cek(B-1, K);
	}
}

void solve(){
	memset(tolong, false, sizeof(tolong));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(matrix[i][j] != '.' && !tolong[i][j]){
				tiga = 0;
				warna = matrix[i][j];
				cek(i, j);
				if(dua < tiga)
					dua = tiga;
			}
		}
	}
}

void rata(int B, int K){
	swap(matrix[B][K], matrix[B+1][K]);
	if(B > 0 && matrix[B-1][K] != '.')
		rata(B-1, K);
}

void runtuh(){
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M; j++){
			if(matrix[i][j] != '.' && matrix[i+1][j] == '.')
				rata(i, j);
		}
	}
}

void hilang(int B, int K){
	if(matrix[B][K] == warna){
		satu++;
		help[B][K] = true;
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

void balik(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(matrix[i][j] != kloning[i][j])
				matrix[i][j] = kloning[i][j];
		}
	}
}

int main(){
	scan(N); scan(M);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf(" %c", &matrix[i][j]);
			kloning[i][j] = matrix[i][j];
		}
	}//input papan
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!help[i][j]){
				warna = matrix[i][j];
				satu = 0; dua = 0;
				hilang(i, j);
				if(satu == 1){
					balik();
					continue;
				}
				runtuh();
				solve();
				satu = satu * (satu-1) + dua * (dua-1);
				if(maks < satu)
					maks = satu;
				balik();
			}
		}
	}
	printf("%d\n", maks);
	return 0;
}