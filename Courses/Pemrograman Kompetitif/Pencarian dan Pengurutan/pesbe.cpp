#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

vector <string> bebek;

int upper(string nama, int N){
	int i = 0, indeks, simpan = 0;
	while(i <= N){
		indeks = (int)(i+N)/2;
		if(nama >= bebek[indeks]){
			simpan = indeks+1;
			if(indeks == N || nama < bebek[indeks+1])
				break;
			i = indeks+1;
		}
		else
			N = indeks-1;
	}
	return simpan;
}

void solve(string nama){
	int indeks = upper(nama, bebek.size()-1);
	cout << indeks+1 << endl;
	bebek.insert(bebek.begin()+indeks, nama);
}

int main(){
	int N, ascii;
	scan(N);
	string nama;
	while(N--){
		cin >> nama;
		solve(nama);
	}
	return 0;
}