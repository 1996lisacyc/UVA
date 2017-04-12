#include <cstdio>
#include <cmath> 
#include <cstring>
using namespace std;

int main(){
	
	long long int a,b;
	double eps;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		
		scanf("%lf",&eps);
		long long int c,d;
		long double num1,num2;
		num1=(long double)a/b;
		
		d=1;
		c=(long long int)d*num1;
		while(a*d>=b*c) c++;
		num2=(long double)c/d;
		
		while((num2-num1)>eps){
			d++;
			c=(long long int)d*(num1);
			while(a*d>=b*c) c++;
			num2=(long double)c/d;
		}
		
		printf("%lld %lld\n",c,d);
	}
	return 0;
}
