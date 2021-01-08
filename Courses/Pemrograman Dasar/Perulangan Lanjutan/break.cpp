#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, N, X = 0, ISI;
  cin >> N;
  for(i = 1; i <= N; i++){
      if(i == 42){
          cout << "ERROR" << endl;
          break;
      }
      if(i % 10 != 0)
        cout << i << endl;
  }
  return 0;
}