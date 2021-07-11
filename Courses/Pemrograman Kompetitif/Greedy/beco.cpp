#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define ll unsigned long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	ll N, D, kali, total = 0, bebek = 0;
	scan(N); scan(D);
	pair <ll,ll> coklat[N];
	for(int i = 0; i < N; i++){
		scan(coklat[i].first); scan(coklat[i].second);
	}
	sort(coklat, coklat+N);
	for(int i = 0; total < D && i < N; i++){
		kali = (ll)coklat[i].first*coklat[i].second;
		if(total+kali <= D){
			total += kali;
			bebek += coklat[i].second;
		}
		else{
			bebek += (ll)((ll)D-total)/coklat[i].first;
			break;
		}
	}
	printf("%lld\n", bebek);
	return 0;
}