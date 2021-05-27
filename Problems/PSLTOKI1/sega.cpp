#include <cstdio>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

bool cek(long long a, long long b, double c){
	if(min(a, b) <= c && max(a, b) >= c)
		return true;
	return false;
}

int main(){
	int N, total = 0;
	scan(N);
	long long X1[N], Y1[N], X2[N], Y2[N], M[N], C[N];
	for(int i = 0; i < N; i++){
		scan(X1[i]); scan(Y1[i]); scan(X2[i]); scan(Y2[i]);
		for(int j = 0; j < i; j++){
			double tipotx, tipoty, syarat;
			syarat = (X2[i]-X1[i]) * (Y2[j]-Y1[j]) - (Y2[i]-Y1[i]) * (X2[j] - X1[j]);
			if(syarat == 0)
				continue;
			tipotx = ((X2[j]-X1[j]) * (Y1[i]*(X2[i]-X1[i])-X1[i]*(Y2[i]-Y1[i])) - (X2[i]-X1[i]) * (Y1[j]*(X2[j]-X1[j])-X1[j]*(Y2[j]-Y1[j]))) / syarat;
			tipoty = (tipotx*(Y2[i]-Y1[i]) + Y1[i]*(X2[i]-X1[i]) - X1[i]*(Y2[i]-Y1[i])) / (X2[i] - X1[i]);
			if(cek(X1[i],X2[i],tipotx) && cek(Y1[i],Y2[i],tipoty) && cek(X1[j],X2[j],tipotx) && cek(Y1[j],Y2[j],tipoty))
				total++;
		}
	}
	printf("%d\n", total);
	return 0;
}