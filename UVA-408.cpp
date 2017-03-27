#include <cstdio>
#include <cmath> 
using namespace std;

int gcd(int a, int b){
	
	if(a==0) return b;
	return gcd(b%a,a);
	
}

int main(){
	
	int num1,num2;
	while(scanf("%d%d",&num1,&num2)!=EOF){
		
		int ans=gcd(num1,num2);
		if(ans==1){
			printf("%10d%10d    Good Choice\n\n",num1,num2);
		}else{
			printf("%10d%10d    Bad Choice\n\n",num1,num2);
		}
		
	}
	return 0;
}
