#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while (!isdigit(input)){if (input == '-') kali = -1; input = gc();}
	while(isdigit(input))angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, baru = 0;
	scan(N);
	int X[N], Y[N];
	vector <int> rumahx, rumahy;
	vector <pair <int, int>> ex, ye;
	for(int i = 0; i < N; i++)
		scan(X[i]);
	for(int i = 0; i < N; i++)
		scan(Y[i]);
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++){
			if(X[i] == X[j]){
				ex.pb(mp(min(Y[i], Y[j]), max(Y[i], Y[j])));
				rumahx.pb(X[i]);
			}
			if(Y[i] == Y[j]){
				ye.pb(mp(min(X[i], X[j]), max(X[i], X[j])));
				rumahy.pb(Y[i]);
			}
		}
	for(int i = 0; i < rumahx.size(); i++)
		for(int j = i+1; j < rumahx.size(); j++)
			if(rumahx[i] == rumahx[j]){
				ex[i] = (mp(min(ex[i].first, ex[j].first), max(ex[i].second, ex[j].second)));
				ex.erase(ex.begin() + j);
				rumahx.erase(rumahx.begin() + j);
				j--;
			}
	for(int i = 0; i < rumahy.size(); i++)
		for(int j = i+1; j < rumahy.size(); j++)
			if(rumahy[i] == rumahy[j]){
				ye[i] = (mp(min(ye[i].first, ye[j].first), max(ye[i].second, ye[j].second)));
				ye.erase(ye.begin() + j);
				rumahy.erase(rumahy.begin() + j);
				j--;
			}
	for(int i = 0; i < rumahx.size(); i++)
		for(int j = 0; j < rumahy.size(); j++)
			if(rumahy[j] > ex[i].first && rumahy[j] < ex[i].second && rumahx[i] > ye[j].first && rumahx[i] < ye[j].second)
				baru++;
	printf("%d\n", baru);
	return 0;
}