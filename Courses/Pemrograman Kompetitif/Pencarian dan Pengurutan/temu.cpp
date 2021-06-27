#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

bool comp(string a, string b){
	if(a.length() < b.length())
		return 1;
	else if(a.length() == b.length())
		if(a < b)
			return 1;
	return 0;
}

int main(){
	int N;
	scan(N);
	string nama[N];
	for(int i = 0; i < N; i++)
		cin >> nama[i];
	sort(nama, nama+N, comp);
	for(int i = 0; i < N; i++)
		cout << nama[i] << endl;
	return 0;
}