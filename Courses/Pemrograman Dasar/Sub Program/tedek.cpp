#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, D, i, j, MAX = 0, T, MIN;
	cin >> N >> D;
	int X[N], Y[N];
	for(i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
	}
	for(i = 0; i < N; i++){
		for(j = i + 1; j < N; j++){
			T = pow(abs(X[j] - X[i]), D) + pow(abs(Y[j] - Y[i]), D);
			if(i == 0 && j == 1)
				MIN = T;
			if(MIN > T)
				MIN = T;
			if(MAX < T)
				MAX = T;
		}
	}
	cout << MIN << " " << MAX << endl;
	return 0;
}