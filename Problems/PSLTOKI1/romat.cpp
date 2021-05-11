#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	bool nol = true, sempu = true, lapu = true, dutu = true;
	cin >> N >> N;
	int matrix[N][N], matrix0[N][N], matrix90[N][N], matrix180[N][N], matrix270[N][N];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> matrix0[i][j];
			matrix90[j][N-i-1] = matrix0[i][j];
			matrix180[N-i-1][N-j-1] = matrix0[i][j];
			matrix270[N-j-1][i] = matrix0[i][j];
		}
	cin >> N >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> matrix[i][j];
			if(matrix[i][j] != matrix0[i][j] && nol)
				nol = false;
			if(matrix[i][j] != matrix90[i][j] && sempu)
				sempu = false;
			if(matrix[i][j] != matrix180[i][j] && lapu)
				lapu = false;
			if(matrix[i][j] != matrix270[i][j] && dutu)
				dutu = false;
		}
	if(nol)
		cout << "0" << endl;
	else if(sempu)
		cout << "90" << endl;
	else if(lapu)
		cout << "180" << endl;
	else if(dutu)
		cout << "270" << endl;
	else
		cout << "tidak sama" << endl;
	return 0;
}