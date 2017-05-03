#include <cstdio>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N=20, W=3000;
struct Item{
	double cost,weight;
}items[N];
double c[W + 1];
int arr[110];
 
void knapsack(int n, int w){
	
    for (int i=1; i <=n; ++i){
    	
        double weight=items[i].weight;
        double cost=items[i].cost;
		for (int j =0; j <=w; j++){
        	if(c[j]>c[j-(int)weight]+cost){
        		c[j]=c[j-(int)weight]+cost;
			}
		}
    }
}

int main(){

	int num,Case=1;
	c[0]=0;
	while(scanf("%lf%d\n",&c[1],&num)!=EOF){
		int index=0;
		items[1].weight=1;
		items[1].cost=c[1];

		for(int i=1; i<3000; i++) c[i]=0xfffffff;
		for(int i=0; i<110; i++) arr[i]=0;
		for(int i=2; i<=num+1; i++) scanf("%lf%lf\n",&items[i].weight,&items[i].cost);
		for(;;){
            scanf("%d",&arr[index++]);
            if(getchar()=='\n')break;
        }
		
		printf("Case %d:\n",Case++);
		for(int i=0; i<index; i++){
			int w=arr[i];
			knapsack(num+1,w);
			printf("Buy %d for $%.2lf\n",arr[i],c[arr[i]]);
		}
	}
	return 0;
}
