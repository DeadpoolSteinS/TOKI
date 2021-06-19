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

int N, K, catat[9];

void solve(int kedalaman){
	if(kedalaman == K){
		for(int i = 0; i < K; i++){
			print(catat[i]);
			if(i != K-1)
				printf(" ");
		}
		printf("\n");
	}
	else{
		for(int i = catat[kedalaman-1]+1; i <= N; i++){
			catat[kedalaman] = i;
			solve(kedalaman+1);
		}
	}
}

int main(){
	scan(N); scan(K);
	solve(0);
	return 0;
}