#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, N, j;
  cin >> N;
  for(i = 0; i < N; i++){
      for(j = N - i - 1; j > 0; j--){
          cout << " ";
      }
      for(j = 0; j < i + 1; j++){
          cout << "*";
      }
      cout << endl;
  }
  return 0;
}