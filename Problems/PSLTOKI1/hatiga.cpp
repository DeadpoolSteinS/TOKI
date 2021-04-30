#include <bits/stdc++.h>
using namespace std;

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, kubik = 1, min = 0;
	vector <int> hadiah;
	cin >> N;
	while(kubik * 3 <= N)
		kubik *= 3;
	while(N){
		for(int i = 0; i < N/kubik; i++){
			hadiah.push_back(kubik);
			min++;
		}
		N %= kubik;
		kubik /= 3;
	}
	cout << min << endl;
	for(int i = hadiah.size()-1; i >= 0; i--){
		cout << hadiah[i];
		if(i)
			cout << " ";
	}
	cout << endl;
	return 0;
}