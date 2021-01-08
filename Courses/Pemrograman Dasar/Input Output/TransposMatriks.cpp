#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int ANGKA[3][3], i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cin >> ANGKA[i][j];
		}
	}
	for(j = 0; j < 3; j++){
		for(i = 0; i < 3; i++){
			cout << ANGKA[i][j];
			if(i != 2)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}