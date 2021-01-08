#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int i, N, j, X;
  cin >> N;
  int ISI[N], SET[N];
  for(i = 0; i < N; i++){
      cin >> ISI[i];
      SET[i] = sqrt(ISI[i]);
  }
  for(i = 0; i < N; i++){
      X = 0;
      for(j = 2; j <= SET[i]; j++){
          if(ISI[i] % j == 0){
              X = 1;
              cout << "BUKAN" << endl;
              break;
          }
      }
      if(ISI[i] == 1){
          X = 1;
          cout << "BUKAN" << endl;
      }
      if(X == 0){
          cout << "YA" << endl;
      }
  }
  return 0;
}