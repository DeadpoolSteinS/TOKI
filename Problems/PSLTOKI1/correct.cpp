#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int selisih[3000];

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, minim, letak, huruf;
	cin >> K;
	string kamus[K], cari;
	for(int i = 0; i < K; i++)
		cin >> kamus[i];
	cin >> cari;
	for(int i = 0; i < cari.length(); i++){
		minim = 1e9;
		for(int j = 0; j < K; j++){
			if(i >= kamus[j].length())
				continue;
			huruf = abs(cari[i] - kamus[j][i]);
			selisih[j] += min(huruf, abs(huruf - 26));
			if(minim > selisih[j]){
				minim = selisih[j];
				letak = j;
			}
		}
		for(int j = 0; j <= i; j++)
			cout << kamus[letak][j];
		cout << endl;
	}
	return 0;
}