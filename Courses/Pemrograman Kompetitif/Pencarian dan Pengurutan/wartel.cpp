#include <iostream>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

const int batas = 1e5+1;
string daftar[batas], nomor[batas];

void solve(string a, int N){
	int i = 0, indeks;
	while(i <= N){
		indeks = (int)(i+N)/2;
		if(a == daftar[indeks]){
			cout << nomor[indeks] << endl;
			return;
		}
		else if(a < daftar[indeks])
			N = indeks-1;
		else
			i = indeks+1;
	}
	cout << "NIHIL\n";
}

int main(){
	int N, Q;
	scan(N); scan(Q);
	string cari;
	for(int i = 0; i < N; i++)
		cin >> daftar[i] >> nomor[i];
	while(Q--){
		cin >> cari;
		solve(cari, N-1);
	}
	return 0;
}