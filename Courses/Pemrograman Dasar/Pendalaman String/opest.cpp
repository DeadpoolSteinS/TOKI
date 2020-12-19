#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string S1, S2, S3, S4;
	int K, i, j, A, B;
	cin >> S1 >> S2 >> S3 >> S4;
	A = S1.find(S2);
	S1.erase(A, S2.length());
	B = S1.find(S3);
	S1.insert(B + S3.length(), S4);
	cout << S1 << endl;
	return 0;
}