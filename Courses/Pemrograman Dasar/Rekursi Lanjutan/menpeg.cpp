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

int main(){
	int dua[11];
	dua[0] = 1;
	for(int i = 1; i <= 10; i++)
		dua[i] = dua[i-1] * 2;
	int N;
	scan(N);
	for(int i = 1; i < dua[N]; i++){
		for(int j = 1; j <= 10; j++){
			if(i % dua[j] == dua[j-1]){
				while(j--)
					printf("*");
				printf("\n");
				break;
			}
		}
	}
	return 0;
}