#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define mp make_pair

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, S, D, batas = -1, banyak = 0;
	scan(N);
	pair <int, int> teman[N];
	for(int i = 0; i < N; i++){
		scan(S); scan(D);
		teman[i] = mp(S+D-1, S);
	}
	sort(teman, teman+N);
	for(int i = 0; i < N; i++){
		if(teman[i].second > batas){
			banyak++;
			batas = teman[i].first;
		}
	}
	printf("%d\n", banyak);
	return 0;
}