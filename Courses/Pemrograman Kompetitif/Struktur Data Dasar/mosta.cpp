#include <cstdio>
#include <deque>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

int main(){
	int N, total = 0, A, B, taku = 0;
	char perintah[3];
	deque <pair <int,int>> arr;
	scan(N);
	while(N--){
		scanf("%s", perintah);
		if(perintah[2] == 'd'){
			scan(A); scan(B);
			arr.push_back(make_pair(A-taku, B));
			total += B;
			printf("%d\n", total);
		}
		else if(perintah[2] == 'l'){
			scan(B);
			printf("%d\n", arr[arr.size()-1].first + taku);
			total -= B;
			while(B > 0){
				if(B >= arr[arr.size()-1].second){
					B -= arr[arr.size()-1].second;
					arr.pop_back();
				}
				else{
					arr[arr.size()-1].second -= B;
					B = 0;
				}
			}
		}
		else if(perintah[0] == 'a' || perintah[0] == 'd'){
			scan(B);
			if(perintah[0] == 'a')
				taku += B;
			else
				taku -= B;
		}
	}
	return 0;
}