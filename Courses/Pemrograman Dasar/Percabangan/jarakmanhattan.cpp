#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	int TOTAL = abs(X2 - X1) + abs(Y2 - Y1);
	cout << TOTAL << endl;
	return 0;
}