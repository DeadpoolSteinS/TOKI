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

const int batas = 1e6;
bool prima[batas];

int main(){
	for(int i = 2; i*i < batas; i++){
		if(!prima[i]){
			for(int j = i*i; j < batas; j+=i){
				if(!prima[j])
					prima[j] = true;
			}
		}			
	}
	int T, maks = 0, indeks = 0;
	scan(T);
	int K[T];
	for(int i = 0; i < T; i++){
		scan(K[i]);
		if(maks < K[i])
			maks = K[i];
	}
	int hasil[maks];
	for(int i = 2; indeks < maks; i++){
		if(!prima[i]){
			hasil[indeks] = i;
			indeks++;
		}
	}
	for(int i = 0; i < T; i++){
		print(hasil[K[i]-1]);
		printf("\n");
	}
	return 0;
}