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
	ll N, total = 0, dua = 1, kel;
	scan(N);
	for(int i = 0; i < N; i++){
		scan(kel);
		if(i == 0 && kel % 2 == 1){
			printf("-1\n");
			return 0;
		}
		total += kel*dua;
		dua *= 2;
	}
	scan(kel);
	if(total % dua != 0)
		printf("-1\n");
	else
		printf("%lld\n", total/dua+kel);
	return 0;
}