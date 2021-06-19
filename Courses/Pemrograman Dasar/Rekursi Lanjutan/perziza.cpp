#include <cstdio>
#include <string>
#include <algorithm>
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

int main(){
	int N, help[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	scan(N);
	do{
		bool benar = 1;
		for(int i = 1; i < N-1; i++){
			if(!(help[i] < help[i-1] ^ help[i] > help[i+1])){
				benar = false;
				break;
			}
		}
		if(benar){
			for(int i = 0; i < N; i++)
				print(help[i]);
			printf("\n");
		}
	}while(next_permutation(help, help+N));
	return 0;
}