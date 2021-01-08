#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, j, M, N;
  cin >> M >> N;
  int ISI[M][N];
  for(i = 0; i < M; i++){
      for(j = 0; j < N; j++){
          cin >> ISI[i][j];
      }
  }
  for(j = 0; j < N; j++){
      for(i = M - 1; i >= 0; i--){
          cout << ISI[i][j];
          if(i != 0){
              cout << " ";
          }
      }
      cout << endl;
  }
  return 0;
}