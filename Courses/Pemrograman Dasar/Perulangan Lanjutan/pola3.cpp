#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, N, j, X = 0;
  cin >> N;
  for(i = 0; i < N; i++){
      for(j = 0; j <= i; j++){
          if(X == 10)
            X = 0;
          cout << X;
          X++;
      }
      cout << endl;
  }
  return 0;
}