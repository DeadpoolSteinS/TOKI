#include <iostream>
#include <cstring>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int T, N, M;
bool denah[80][80];

void bocor(int x, int y){
	if((x >= 0) && (x < N) && (y >= 0) && (y < M) && (denah[x][y])){
		denah[x][y] = false;
		bocor(x, y+1);
		bocor(x, y-1);
		bocor(x+1, y);
		bocor(x-1, y);
	}
}

void tampil(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(denah[i][j]){
				cout << "YA\n";
				return;
			}
	cout << "TIDAK\n";
}

int main(){
	scan(T);
	while(T--){
		string baris;
		scan(N); scan(M);
		for(int i = 0; i < N; i++){
			getline(cin, baris);
			for(int j = 0; j < baris.length(); j++)
				if(baris[j] != '#')
					denah[i][j] = true;
		}
		for(int i = 0; i < N; i++){
			bocor(i, 0);
			bocor(i, M-1);
		}
		for(int i = 0; i < M; i++){
			bocor(0, i);
			bocor(N-1, i);
		}
		tampil();
	}
	return 0;
}