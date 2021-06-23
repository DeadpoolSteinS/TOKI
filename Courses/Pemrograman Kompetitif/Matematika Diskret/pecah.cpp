#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

ll fpb(ll a, ll b){
	ll help;
	if(a < b)
		swap(a, b);
	while(b != 0){
		help = a;
		a = b;
		b = help%b;
	}
	return a;
}

int main(){
	ll A, B, C, D, bilang, nyebut, bagi;
	scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
	nyebut = B*D;
	bilang = A*D + C*B;
	bagi = fpb(nyebut, bilang);
	printf("%lld %lld\n", bilang/bagi, nyebut/bagi);
	return 0;
}