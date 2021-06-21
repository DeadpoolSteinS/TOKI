#include <cstdio>
#include <string>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

template <typename T> void print(T angka){
	string s; if(angka == 0){pc('0'); return;}
	while(angka){s += (angka % 10) + '0'; angka /= 10;}
	for(int i = s.size()-1; i >= 0; i--) pc(s[i]);
}

int N, M, matrix[25][25], indeks = 0, warna;
bool help[25][25];

void solve(int B, int K){
	if(matrix[B][K] == warna && !help[B][K]){
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
	scan(B); scan(K);
	warna = matrix[B][K];
	solve(B, K);
	print(indeks*(indeks-1)); printf("\n");
	return 0;
}