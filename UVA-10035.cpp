#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	
	long long int num1,num2;
	while(scanf("%lld%lld",&num1,&num2)){
		if(!num1&&!num2) break;
		int counter=0,carry=0,tem1,tem2;
		
		while(num1||num2){
			tem1=num1%10;
			tem2=num2%10;
			if((tem1+tem2+carry)>=10){
				carry=1;
				counter++;
				num1=num1/10;
				num2=num2/10;
			}else{
				carry=0;
				num1=num1/10;
				num2=num2/10;
			}
		}
		
		if(counter== 1){
			printf("1 carry operation.\n");
		}else if(counter>1){
			printf("%d carry operations.\n",counter);
		}else{
			printf("No carry operation.\n");
		}
	}
	return 0;
}
