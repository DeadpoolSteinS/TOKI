#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define pb push_back
#define mp make_pair

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int N;
string kata;
vector <pair <int,int>> pasang[50];
vector <int> banyak[50];

void sama(int X, int indeks){
	for(int i = 0; i < X; i++){
		if(kata[i] == kata[X]){
			banyak[indeks].pb(2);
			if(i != X-1){
				bool ada = false;
				int terbesar = 0;
				for(int j = 0; j < pasang[indeks].size(); j++){
					if(i < pasang[indeks][j].first && X > pasang[indeks][j].second){
						terbesar = max(terbesar, banyak[indeks][j]);
						ada = true;
					}
				}
				if(ada)
					banyak[indeks][banyak[indeks].size()-1] += terbesar;
				else
					banyak[indeks][banyak[indeks].size()-1]++;
			}
			pasang[indeks].pb(mp(i, X));
		}
	}
}

int main(){
	scan(N);
	for(int i = 0; i < N; i++){
		cin >> kata;
		for(int j = 1; j < kata.length(); j++)
			sama(j, i);
		if(banyak[i].size() == 0)
			printf("1\n");
		else{
			sort(banyak[i].begin(), banyak[i].end());
			printf("%d\n", banyak[i][banyak[i].size()-1]);
		}
	}
	return 0;
}