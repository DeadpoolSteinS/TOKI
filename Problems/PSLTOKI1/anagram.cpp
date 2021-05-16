#include <iostream>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back

int N, banyak, maks = 0, letak = -1;
pair <string, string> kata[10000];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> kata[i].first;
		kata[i].second = kata[i].first;
		sort(kata[i].first.begin(), kata[i].first.end());
	}
	sort(kata, kata+N);
	for(int i = 0; i < N; i++){
		banyak = 0;
		for(int j = i + 1; j < N; j++){
			if(kata[i].first == kata[j].first)
				banyak++;
			else
				break;
		}
		if(maks < banyak){
			maks = banyak;
			letak = i;
		}
		else if(maks == banyak && maks > 0)
			if(kata[i].second < kata[letak].second)
				letak = i;
	}
	if(letak != -1){
		cout << maks+1 << endl;
		for(int i = 0; i <= maks; i++)
			cout << kata[letak+i].second << endl;
	}
	else
		cout << "TIDAK ADA" << endl;	
	return 0;
}