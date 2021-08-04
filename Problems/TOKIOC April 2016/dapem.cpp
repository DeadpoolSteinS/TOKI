#include <iostream>
#include <sstream>
using namespace std;
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = getchar();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = getchar();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = getchar();
	angka *= kali;
}

int main(){
	ll N, len, panjang;
	string kata;
	scan(N);
	cin >> kata;
	panjang = kata.length();
	if(N == 1){
		stringstream number(kata);
		number >> len;
		if(kata[0] == '-'){
			if(panjang > 11 || kata[1] == '0' || len > 2147483646){
				printf("WA\n");
				return 0;
			}
			for(int i = 1; i < panjang; i++){
				if(kata[i] < '0' || kata[i] > '9'){
					printf("WA\n");
					return 0;
				}
			}
		}
		else{
			if(panjang > 10 || (kata[0] == '0' && panjang > 1) || len > 2147483646){
				printf("WA\n");
				return 0;
			}
			for(int i = 0; i < panjang; i++){
				if(kata[i] < '0' || kata[i] > '9'){
					printf("WA\n");
					return 0;
				}
			}
		}
		printf("AC\n");
	}
	else if(N == 2){
		if(panjang%2 == 1 || panjang < 4){
			printf("WA\n");
			return 0;
		}
		ll P[panjang], D[panjang];
		P[0] = 1;
		D[0] = kata[0];
		for(int i = 1; i < panjang; i++){
			P[i] = 91 * P[i-1];
			D[i] = D[i-1] + P[i] * kata[i];
		}
		for(int i = 0; i < panjang/2-1; i++){
			if(D[i] * P[panjang-i-1] == D[panjang-1] - D[panjang-i-2] 
			&& (D[panjang/2-1] - D[i]) * P[panjang/2-i-1] == D[panjang-i-2] - D[panjang/2-1]){
				printf("AC\n");
				return 0;
			}
		}
		printf("WA\n");
	}
	return 0;
}

// code by AMnu
// https://tlx.toki.id/profiles/AMnu