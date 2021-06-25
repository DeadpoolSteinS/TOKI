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

int papan[101][101], N, M, K;

bool menarik(int a, int b){
	int hasil = 1;
	if(b+1 <= M)
		hasil *= papan[a][b+1];
	if(b-1 >= 1)
		hasil *= papan[a][b-1];
	if(a+1 <= N)
		hasil *= papan[a+1][b];
	if(a-1 >= 1)
		hasil *= papan[a-1][b];
	if(hasil == K)
		return 1;
	else
		return 0;
}

int main(){
	scan(N); scan(M); scan(K);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scan(papan[i][j]);
		}
	}
	for(int j = 1; j <= M; j++){
		for(int i = 1; i <= N; i++){
			if(menarik(i, j)){
				print(i); printf(" "); print(j); printf("\n");
				return 0;
			}
		}
	}
	printf("0 0\n");
	return 0;
}