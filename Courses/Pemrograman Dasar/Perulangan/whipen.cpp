#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, X = 0, ISI;
  i = 0;
  while(scanf("%d", &ISI) != EOF){
      X = X + ISI;
      i++;
  }
  cout << X << endl;
  return 0;
}