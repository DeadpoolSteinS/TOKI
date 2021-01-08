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
      for(j = 1; j <= SET[i]; j++){
          if(ISI[i] % j == 0)
            X++;
      }
      if(X >= 1 && X <= 2){
          cout << "YA" << endl;
      }
      else{
          cout << "BUKAN" << endl;
      }
  }
  return 0;
}