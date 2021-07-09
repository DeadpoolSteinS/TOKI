#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N;

bool cmp(int a, int b){
	return (a>b);
}

ll kali(int a[], int b[]){
	ll total = 0;
	for(int i = 0; i < N; i++)
		total += (ll)a[i]*b[i];
	return total;
}

int main(){
	scan(N);
	int satu[N], dua[N];
	for(int i = 0; i < N; i++)
		scan(satu[i]);
	for(int i = 0; i < N; i++)
		scan(dua[i]);
	sort(satu, satu+N, cmp);
	sort(dua, dua+N);
	printf("%lld\n", kali(satu, dua));
	return 0;
}