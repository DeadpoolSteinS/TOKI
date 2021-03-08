#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, K, terkecil = 1e9;;
	cin >> N >> K;
	int data[N];
	for(int i = 0; i < N; i++)
		cin >> data[i];
	sort(data, data + N);
	for(int i = 0; i <= N - K; i++)
		terkecil = min(terkecil, data[i + K - 1] - data[i]);
	cout << terkecil << endl;
	return 0;
}