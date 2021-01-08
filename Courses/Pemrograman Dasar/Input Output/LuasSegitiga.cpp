#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double A, B;
	cin >> A >> B;
	double HASIL = A * B / 2;
	cout << fixed << setprecision(2) << HASIL << endl;
	return 0;
}