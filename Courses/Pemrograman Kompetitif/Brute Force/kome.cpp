#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N, R, Y, J, D[11], juri, pilih[11], meyakinkan;
char T[11];
bool pakai[11];
vector <int> poin;

void cek(){
	int K = 0;
	bool yakin = false;
	for(int i = 1; i <= R; i++){
		int L = 0;
		L += D[pilih[i]];
		if(i > 1 && T[pilih[i-1]] == 'P')
			L *= 2;
		else if(i > 1 && T[pilih[i-1]] == 'L')
			L /= 2;
		if(yakin)
			L += Y;
		if(T[pilih[i]] == 'Y')
			yakin = true;
		K += L;
	}
	poin.push_back(K);
}

void permutasi(int X){
	if(X > R)
		cek();
	else{
		for(int i = 1; i <= N; i++){
			if(!pakai[i]){
				pakai[i] = true;
				pilih[X] = i;
				permutasi(X+1);
				pakai[i] = false;
			}
		}
	}
}

int main(){
	char sub[11];
	scanf("%10[^\n]s", sub);
	scan(N); scan(R); scan(Y); scan(J);
	for(int i = 1; i <= N; i++){
		scan(D[i]); scanf(" %c", &T[i]);
	}
	permutasi(1);
	sort(poin.begin(), poin.end());
	for(int i = 1; i <= J; i++){
		scan(juri);
		meyakinkan = poin.size() - (lower_bound(poin.begin(), poin.end(), juri+1) - poin.begin());
		printf("%d\n", meyakinkan);
	}
	return 0;
}