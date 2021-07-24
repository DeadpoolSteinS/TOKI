#include <cstdio>
#include <vector>
using namespace std;
#define gc getchar_unlocked
#define pb push_back
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

const int maks = 26101991;
int N, Q;
ll bk, arr1[101][101], arr2[101];
vector <ll> satu;

ll move(int X){
	if(X == 1)
		return 1;
	else if(arr2[X] != 0)
		return arr2[X];
	else{
		ll res = 0;
		for(int i = 1; i < X; i++){
			res += move(i) * move(X-i);
			res %= maks;
		}
		arr2[X] = res;
		return res;
	}
}

ll langkah(int X, int Y){
	if(X == Y)
		return 0;
	else if(arr1[X][Y] != 0)
		return arr1[X][Y];
	else{
		ll best = 9e18;
		for(int i = 0; i < Y-X; i++)
			best = min(best, langkah(X, X+i) + langkah(X+i+1, Y) + satu[X] * satu[X+i+1] * satu[Y+1]);
		arr1[X][Y] = best;
		return best;
	}
}

int main(){
	scan(N);
	satu.pb(0);
	for(int i = 1; i <= N+1; i++){
		scan(bk);
		satu.pb(bk);
	}
	scan(Q);
	if(Q == 1)
		printf("%lld\n", langkah(1, N));
	else if(Q == 2){
		ll dua = langkah(1, N);
		ll result = 0;
		for(int i = 0; i < N-1; i++){
			if((langkah(1, i+1) + langkah(i+2, N) + satu[1] * satu[i+2] * satu[N+1] == dua)){
				result++;
				if(result == maks)
					result = 0;
			}
		}
		printf("%lld\n", result);
	}
	else if(Q == 3)
		printf("%lld\n", move(N));
	return 0;
}

// Code by Zanite
// https://tlx.toki.id/profiles/Zanite