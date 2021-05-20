#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int histogram(int value[], int N){
	stack <int> index;
	int i = 0, maks = 0, cek, luas;
	while(i < N){
		if(index.empty() || value[index.top()] <= value[i])
			index.push(i++);
		else{
			cek = index.top();//mengambil index teratas untuk di cek luasnya
			index.pop();//menghilangkan index yang akan dihitung
			(index.empty())? (luas = value[cek] * i): (luas = value[cek] * (i - index.top() - 1));
			maks = max(luas,maks);
		}
	}
	while(index.empty() == false){
		cek = index.top();//mengambil index teratas untuk di cek luasnya
		index.pop();//menghilangkan index yang akan dihitung
		(index.empty())? (luas = value[cek] * i): (luas = value[cek] * (i - index.top() - 1));
		maks = max(luas,maks);
	}
	return maks;
}

int main(){
	int T, B, K, N, L, X1, Y1, X2, Y2;
	scan(T);
	while(T--){
		scan(B); scan(K); scan(N); scan(L);
		int daerah[B][K];
		for(int i = 0; i < B; i++)
			for(int j = 0; j < K; j++)
				daerah[i][j] = 1;
		while(N--){
			scan(X1); scan(Y1); scan(X2); scan(Y2);
			for(int i = X1-1; i < X2; i++)
				for(int j = Y1-1; j < Y2; j++)
					daerah[i][j] = 0;
		}
		int kolom[K] = {}, terluas = 0;
		for(int i = 0; i < B; i++){
			for(int j = 0; j < K; j++)
				(daerah[i][j] == 0)? (kolom[j] = 0): (kolom[j]++);
			terluas = max(histogram(kolom, K), terluas);
		}
		printf((terluas >= L)? "YA\n": "TIDAK\n");
	}
	return 0;
}