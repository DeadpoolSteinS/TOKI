#include <cstdio>
using namespace std;
#define gc getchar_unlocked
#define ll long long

template <typename T> void scan(T &angka){
	T kali = 1; angka = 0; char input = gc();
	while(input < '0' || input > '9'){if (input == '-') kali = -1; input = gc();}
	while(input >= '0' && input <= '9')angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
	angka *= kali;
}

ll A, B, C, N, hasil;

ll pangkat(ll a, ll b){
	if(b == 0)
		return 1;
	else{
		ll cek = pangkat(a, b/2);
		if(b%2 == 0)
			return (cek * cek % N);
		else
			return ((cek * cek % N) * a % N);
	}
}

int main(){
	scan(A); scan(B); scan(C); scan(N);
	hasil = A;
	for(int i = 0; i < C; i++)
		hasil = pangkat(hasil, B);
	printf("%lld\n", hasil+1);
	return 0;
}