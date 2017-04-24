#include <cstdio>
#include <cmath> 
#include <cstring>
using namespace std;
bool isprime[1000000];

int main(){
	
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	
	for(int i=2; i<=sqrt(1000000); ++i){
		if(isprime[i]){
			for(int j=i*i; j<1000000; j+=i){
				isprime[j]=false;
			}
		}
	}

	long long int n;
	while(scanf("%lld",&n)){
		if(n<0) break;

		for(int i=0; i<1000000; i++){
			if(isprime[i]&&(n%i==0)){
				while(n%i==0){
					printf("    %d\n",i);
					n=n/i;
				}
				if(n==1) break;
			}
		}
		
		if(n!=1) printf("    %lld\n",n);
		printf("\n");
	}
}
