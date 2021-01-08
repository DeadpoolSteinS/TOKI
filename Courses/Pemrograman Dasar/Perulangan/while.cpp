#include <iostream>

using namespace std;

int main(){
  int i;
  char ISI[100][100];
  i = 0;
  while(scanf("%s", ISI[i]) != EOF){
    cout << ISI[i] << endl;
    i++;
  }
  return 0;
}