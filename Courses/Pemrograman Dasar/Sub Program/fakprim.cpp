#include <iostream>

using namespace std;

int main(){
  	int i, N, j, X, Y = 0;
  	cin >> N;
    for(j = 2; j <= N; j++){
    	X = 0;
        if(N % j == 0){
        	while(N % j == 0){
        		N = N / j;
        		X++;
        	}
        	Y++;
        	if(Y != 1)
        		cout << " x ";
        	cout << j;
        	if(X > 1)
        		cout << "^" << X;
        }
    }
    cout << endl;
  	return 0;
}