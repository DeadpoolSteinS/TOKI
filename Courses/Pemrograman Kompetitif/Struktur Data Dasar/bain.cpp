#include <cstdio>
#include <vector>
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
	int N;
	ll hasil = 0;
	vector <int> bisa;
	scan(N);
	int tinggi[N];
	for(int i = 0; i < N; i++)
		scan(tinggi[i]);
	for(int i = N-1; i >= 0; i--){
		while((!bisa.empty()) && (bisa.back() < tinggi[i]))
			bisa.pop_back();
		bisa.push_back(tinggi[i]);
		hasil += bisa.size();
	}
	printf("%lld\n", hasil);
	return 0;
}