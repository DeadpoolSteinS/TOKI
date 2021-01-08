#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
  int i, X = 0, ISI[100];
  i = 0;
  while(scanf("%d", &ISI[i]) != EOF){
      i++;
  }
  int PANJANG = i;
  for(i = 0; i < PANJANG; i++){
      cout << ISI[PANJANG - i - 1] << endl;
  }
  return 0;
}