#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define mp make_pair

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N;
ll M, price[10], banyak[10], total;
pair <ll,int> indeks[10];
string last;

bool cmp(pair <ll,int> a, pair <ll,int> b){
	return a.first <= b.first;
}

void bagi(ll X){
	for(int i = N; i>X && M; i--){
		ll selisih = price[i] - price[X];
		ll pindah = M / selisih;
		pindah = min(pindah, banyak[X]);
		banyak[i] += pindah;
		banyak[X] -= pindah;
		M -= pindah*selisih;
	}
}

void awal(){
	int panjang = 0;
	for(int i = N; i >= 0 && panjang < 50; i--){
		for(int j = 0; j < banyak[i] && panjang < 50; j++){
			printf("%d", i);
			panjang++;
		}
	}
	printf("\n");
}

void akhir(){
	int panjang = 0;
	for(int i = 0; i <= N && panjang < 50; i++){
		for(int j = 0; j < banyak[i] && panjang < 50; j++){
			char huruf = '0' + i;
			last = huruf + last;
			panjang++;
		}
	}
	cout << last << endl;
}

int main(){
	scan(N);
	for(int i = 0; i <= N; i++){
		scan(price[i]);
		indeks[i] = mp(price[i], i);
	}
	scan(M);
	sort(indeks, indeks+N+1, cmp);
	if(M < indeks[0].first)
		printf("0\n");
	else if(N == 0 || (M < indeks[1].first && indeks[0].second == 0))
		printf("1\n0\n0\n");
	else{
		if(indeks[0].second == 0){
			banyak[indeks[1].second]++;
			M -= indeks[1].first;
			total++;
		}
		banyak[indeks[0].second] = M / indeks[0].first;
		M %= indeks[0].first;
		total += banyak[indeks[0].second];
		bagi(indeks[0].second);
		printf("%lld\n", total);
		awal(); akhir();
	}
	return 0;
}