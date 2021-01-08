#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, j, k, N, M, P;
  cin >> N >> M >> P;
  int A[N][M], B[M][P];
  for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
          cin >> A[i][j];
      }
  }
  for(i = 0; i < M; i++){
      for(j = 0; j < P; j++){
          cin >> B[i][j];
      }
  }
  int AKHIR[N][P];
  for(i = 0; i < N; i++){
      for(j = 0; j < P; j++){
          AKHIR[i][j] = 0;
          for(k = 0; k < M; k++){
              AKHIR[i][j] = A[i][k] * B[k][j] + AKHIR[i][j];
          }
          cout << AKHIR[i][j];
          if(j != P - 1){
              cout << " ";
          }
      }
      cout << endl;
  }
  return 0;
}