#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N; double med;
	scan(N);
	int nilai[N];
	for(int i = 0; i < N; i++)
		scan(nilai[i]);
	sort(nilai, nilai+N);
	if(N % 2 == 0)
		med = (double)(nilai[N/2] + nilai[N/2-1]) / 2;
	else
		med = nilai[N/2];
	printf("%.1lf\n", med);
	return 0;
}