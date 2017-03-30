#include <cstdio>
#include <iostream>
#include <cmath> 
#define eps 1E-6
using namespace std;

int main(){

	int p,q,r,s,t,u;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		double ans=0.0,right=1.0, left=0.0,x;

		for(int i=0; i<100; i++){
			double mid=(left+right)/2;
			x=mid;
			ans=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
			if(ans>0) left=mid;
			else right=mid;
		}
		double tem=p*exp(-0)+q*sin(0)+r*cos(0)+s*tan(0)+t*pow(0,2)+u;
		double tem2=p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t*pow(1,2)+u;
		if(tem<-eps||tem2>eps)  printf("No solution\n");
		else printf("%.4lf\n",x);
	}
	return 0;
}
