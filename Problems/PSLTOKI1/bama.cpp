#include <cstdio>
#include <algorithm>
using namespace std;
#define mp make_pair
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, power = 0, i, minim = 0;
	scan(N);
	int penyihir[N];
	for(i = 0; i < N; i++)
		scan(penyihir[i]);
	sort(penyihir, penyihir+N);
	i = N-1;
	while(power < N){
		power += penyihir[i] + 1;
		minim++;
		i--;
	}
	printf("%d\n", minim);
	return 0;
}