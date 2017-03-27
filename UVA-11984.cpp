#include<cstdio>
#include<iostream>
using namespace std;

int main(){

	int n;
	while(scanf("%d",&n)!=EOF){
		
		int i,c,d;
		float ans=0;
		
		for(i=0; i<n; i++){
			scanf("%d%d",&c,&d);
			ans=9.0*c*0.2+32.0;
			ans+=d;
			ans=(ans-32.0)*5.0/9.0;
			printf("Case %d: %.2f\n",i+1,ans);
		}
	}
    return 0;
}

