#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, pecahan[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	cin >> K;
	for(int i = 0; i < 10; i++){
		if(K >= pecahan[i]){
			cout << pecahan[i] << " " << K / pecahan[i] << endl;
			K = K % pecahan[i];
		}
	}
	return 0;
}