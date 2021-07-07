#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define pb push_back

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

vector <int> banyak;

int main(){
	int N, Q, X, Y, total = 0;
	scan(N);
	for(int i = 0; i < N; i++){
		scan(X);
		total += X;
		banyak.pb(total+1);
	}
	scan(Q);
	while(Q--){
		scan(Y);
		X = upper_bound(banyak.begin(), banyak.end(), Y) - banyak.begin();
		printf("%d\n", X+1);
	}
	return 0;
}