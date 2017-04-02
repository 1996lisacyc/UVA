#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main(){
	
	int counter[7500];
	int coin[5]={1,5,10,25,50};
	for(int i=0; i<7500; i++) counter[i]=0;
	counter[0]=1;
	for(int i=0; i<5; i++){
		for(int j=0; j+coin[i]<=7489; j++){
			counter[coin[i]+j]+=counter[j];
		}
	}
	
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",counter[n]);
	}
	return 0;
}
