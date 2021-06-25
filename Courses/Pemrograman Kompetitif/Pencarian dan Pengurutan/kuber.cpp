#include <cstdio>
#include <cmath>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, X, kupon, minim = 400000, menang;
	scan(N); scan(X);
	while(N--){
		scan(kupon);
		if(minim > (abs(kupon - X))){
			minim = abs(kupon - X);
			menang = kupon;
		}
		else if(minim == (abs(kupon - X)))
			if(menang > kupon)
				menang = kupon;
	}
	printf("%d\n", menang);
	return 0;
}