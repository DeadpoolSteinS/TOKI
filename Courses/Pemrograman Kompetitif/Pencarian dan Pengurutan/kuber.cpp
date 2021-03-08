#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, X, dekat = 400001, winner, kurang, kupon;
	cin >> N >> X;
	for(int i = 0; i < N; i++){
		cin >> kupon;
		kurang = abs(kupon - X);
		if(kurang < dekat){
			dekat = kurang;
			winner = kupon;
		}
		else if(kurang == dekat)
			winner = min(winner, kupon);
	}
	cout << winner << endl;
	return 0;
}