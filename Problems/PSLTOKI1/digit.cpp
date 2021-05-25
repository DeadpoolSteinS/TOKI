#include <cstdio>
#include <vector>
using namespace std;
#define gc getchar_unlocked
#define pb push_back

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

vector <int> angka = {1};
int jum_dig[5001];

int main(){
	for(int i = 1; i <= 5000; i++){
		int digit = 0;
		for(int j = 0; j < angka.size(); j++){
			int k = 2 * angka[j] + digit;
			digit = k/10;
			angka[j] = (k % 10);
		}
		while(digit > 0){
			angka.pb(digit % 10);
			digit /= 10;
		}
		for(int j = 0; j < angka.size(); j++)
			jum_dig[i] += angka[j];
	}
	int T, N;
	scan(T);
	while(T--){
		scan(N);
		printf("%d\n", jum_dig[N]);
	}
	return 0;
}