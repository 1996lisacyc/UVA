#include<cstdio>
#include<iostream>
using namespace std;

int main(){

	int H,M;
	float tem1,tem2,tem3=360.0,ans=0;
	
	while(scanf("%d:%d",&H,&M)!=EOF){
		if(!H&&!M) break;
		tem1=H*30.0+M/60.0*30.0;
		tem2=M*6.0;
		ans=(tem2>tem1?tem2-tem1:tem1-tem2);
		ans=(tem3-ans<ans?tem3-ans:ans);
		printf("%.3f\n",ans);
	}
    return 0;
}

