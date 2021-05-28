#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	ll N, F = 0, kuad = 1;
	scan(N);
	while((N+kuad)/kuad/2 > 0){
		F += ((N+kuad)/kuad/2) * ((N+kuad)/kuad/2);
		kuad *= 2;
	}
	printf("%lld\n", F);
	return 0;
}