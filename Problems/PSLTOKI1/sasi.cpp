#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int R, C, banyak;
char kapital[100][100];

bool search(string cari){
	bool h1, h2, v1, v2, d1, d2, d3, d4;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			if(kapital[i][j] == cari[0]){
				h1 = 1; h2 = 1; v1 = 1; v2 = 1; d1 = 1; d2 = 1; d3 = 1; d4 = 1;
				for(int k = 1; k < cari.length(); k++){
					if(kapital[i][j+k] != cari[k] && h1)
						h1 = false;
					if(kapital[i][j-k] != cari[k] && h2)
						h2 = false;
					if(kapital[i+k][j] != cari[k] && v1)
						v1 = false;
					if(kapital[i-k][j] != cari[k] && v2)
						v2 = false;
					if(kapital[i+k][j+k] != cari[k] && d1)
						d1 = false;
					if(kapital[i+k][j-k] != cari[k] && d2)
						d2 = false;
					if(kapital[i-k][j+k] != cari[k] && d3)
						d3 = false;
					if(kapital[i-k][j-k] != cari[k] && d4)
						d4 = false;
				}
				if(h1 || h2 || v1 || v2 || d1 || d2 || d3 || d4)
					return true;
			}
	return false;
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			cin >> kapital[i][j];
	cin >> banyak;
	string cari;
	for(int i = 0; i < banyak; i++){
		cin >> cari;
		if(search(cari))
			cout << cari << " Y" << endl;
		else
			cout << cari << " T" << endl;
	}
	return 0;
}