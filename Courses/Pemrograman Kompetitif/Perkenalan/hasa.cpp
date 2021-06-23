#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char a[1000], b[1000];
	scanf("%s", a); scanf("%s", b);
	if(strlen(a) != strlen(b)+1){
		printf("Wah, tidak bisa :(\n");
		return 0;
	}
	bool sudah = false;
	for(int i = 0; i < strlen(a); i++){
		if(sudah){
			if(a[i] != b[i-1]){
				printf("Wah, tidak bisa :(\n");
				return 0;
			}
		}
		else if(a[i] != b[i])
			sudah = true;
	}
	printf("Tentu saja bisa!\n");
	return 0;
}