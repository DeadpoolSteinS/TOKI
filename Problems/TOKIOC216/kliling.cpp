#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, A, B, P, Q; 
    long long C, D;//nilai C dan D besar
    double sudut = 0;
    bool ada = false;
    cin >> N >> A >> P >> M >> B >> Q;
    sudut += 360.0 / N * ((N - P + 1) % N);
    sudut += 360.0 / M * (Q - 1);//harus pake 360.0
    C = A * ((N - P + 1) % N);
    D = B * (Q - 1);
    for(int i = 0; i <= N*A + M*B; i++){//batasannya nyontek
    	if(C < D){
    		if(C + A > D){
    			ada = true;
    			break;
    		}
    		C += N * A;
    		sudut += 360.0;
    	}
    	else{
    		if(D + B > C){
    			ada = true;
    			break;
    		}
    		D += M * B;
    		sudut += 360.0;
    	}
    }
    if(ada == true)
    	cout << fixed << setprecision(8) << sudut << endl;
    else
    	cout << "-1" << endl;
    return 0;
}