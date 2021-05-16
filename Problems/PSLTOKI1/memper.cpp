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

bool bytwo(pair <int, int> a, pair <int, int> b){
	return (a.second < b.second);
}

int main(){
	int N, nilai;
	pair <int, int> loop[100000];
	scan(N);
	for(int i = 0; i < N; i++){
		scan(nilai);
		loop[i] = mp(nilai, i);
	}
	sort(loop, loop+N);
	for(int i = 1; i < N; i++)
		if(loop[i-1].first == loop[i].first)
			loop[i].second = -1;
	sort(loop, loop+N, bytwo);
	for(int i = 0; i < N; i++)
		if(loop[i].second != -1)
			printf("%d\n", loop[i].first);
	return 0;
}