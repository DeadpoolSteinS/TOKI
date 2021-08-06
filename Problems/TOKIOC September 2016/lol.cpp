#include <cstdio>
#include <vector>
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
	int N, K, M, harga = 0, cost;
	scan(N); scan(K); scan(M);
	char petak[N];
	vector <int> biaya;
	for(int i = 0; i < N; i++)
		scanf(" %c", &petak[i]);
	for(int i = 0; i < N; i++){
		scan(cost);
		if(petak[i] == '1')
			biaya.push_back(cost);
	}
	sort(biaya.begin(), biaya.end());
	for(int i = biaya.size()-1; i >= 0; i--){
		if(K > 0)
			K--;
		else if(M > 0){
			harga += (int)biaya[i]/2;
			M--;
		}
		else
			harga += biaya[i];
	}
	printf("%d\n", harga);
	return 0;
}