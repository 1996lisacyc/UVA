#include <cstdio>
#include <cmath> 
#include <cstring>
using namespace std;
bool isprime[100000000];

int main(){
	
	memset(isprime,1,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	
	for(int i=2; i<=sqrt(100000000); ++i){
		if(isprime[i]){
			for(int j=i*i; j<100000000; j+=i){
				isprime[j]=false;
			}
		}
	}

	int n,set;
	while(scanf("%d",&n)!=EOF){
		
		set=0;
		if(n<=4){
			printf("%d is not the sum of two primes!\n",n);
			set=1;
		}else if(n%2==0){
			for(int i=(n-1)/2; i>-1; i--){
				if(isprime[i]&&(isprime[n-i])){
					printf("%d is the sum of %d and %d.\n",n,i,n-i); 
					set=1;
					break;
				}
			}
		}else{
			if(!isprime[n-2]){
				printf("%d is not the sum of two primes!\n",n);
				set=1;
			}else{
				printf("%d is the sum of 2 and %d.\n",n,n-2); 
				set=1;
			}
		}
		if(!set) printf("%d is not the sum of two primes!\n",n);
	}
	return 0;
}
