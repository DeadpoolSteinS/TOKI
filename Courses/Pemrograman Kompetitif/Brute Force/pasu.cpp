#include <cstdio>
#include <algorithm>
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

int M, N, cek, rata;
bool benar = false;
vector <int> suara, indeks;

bool sama(){
	for(int i = 1; i < indeks.size()-1; i++){
		if(suara[indeks[i]] == suara[indeks[i]-1])
			return false;
	}
	return true;
}

void solve(int X, int Y){
	if(X >= N){
		if(Y == M && sama())
			benar = true;
	}
	else{
		indeks.pb(indeks.back()+rata);
		solve(X+1, Y+rata);
		if(benar)
			return;
		indeks.pop_back();

		indeks.pb(indeks.back()+rata+1);
		solve(X+1, Y+rata+1);
		if(benar)
			return;
		indeks.pop_back();
	}
}

int main(){
	scan(M);
	for(int i = 0; i < M; i++){
		scan(cek);
		suara.pb(cek);
	}
	scan(N);
	sort(suara.begin(), suara.end());
	rata = M/N;
	if(M % N == 0){
		for(int i = 1; i < N; i++){
			printf("%d", suara[rata*i]);
			if(i < N-1)
				printf(" ");
		}
		printf("\n");
	}
	else{
		indeks.pb(0);
		solve(0, 0);
		for(int i = 1; i < indeks.size()-1; i++){
			printf("%d", suara[indeks[i]]);
			if(i < indeks.size()-2)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}