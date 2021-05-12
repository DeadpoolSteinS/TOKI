#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int N, T, bil[8000], cari;

bool find(){
	int i = 0, j = N-1;
	while(i < j){
		if(bil[i] + bil[j] == cari)
			return true;
		else if(bil[i] + bil[j] < cari)
			i++;
		else if(bil[i] + bil[j] > cari)
			j--;
	}
	return false;
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for(int i = 0; i < N; i++)
		cin >> bil[i];
	sort(bil, bil+N);
	while(T--){
		cin >> cari;
		if(find())
			cout << "YA" << endl;
		else
			cout << "TIDAK" << endl;
	}
	return 0;
}