#include <cstdio>
#include <cmath> 
using namespace std;

int exGCD(int a, int b, int &X, int&Y){
	
	if(b==0){
		X=1;
		Y=0;
		return a;
	}else{
		int gcd=exGCD(b,a%b,X,Y);
		int tem=X;
		X=Y;
		Y=tem-(a/b)*Y;
		return gcd;
	}
}

int main(){
	
	int num1,num2;
	while(scanf("%d%d",&num1,&num2)!=EOF){
		
		int X,Y,ans;
		ans=exGCD(num1,num2,X,Y);
		printf("%d %d %d\n",X,Y,ans);

	}
	
	return 0;
}
