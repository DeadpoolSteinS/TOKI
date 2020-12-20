#include <iostream>

using namespace std;

int main(){
	int F = 1, N, i, G = 0;
	cin >> N;
	for(i = 1; i <= N; i++){
		G = i;
		if(i % 2 == 0)
			G = G / 2;;
		F = F * G;
	}
	cout << F << endl;
	return 0;
}