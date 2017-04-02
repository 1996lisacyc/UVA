#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm> 
using namespace std;

struct Item{
	int cost;
	int weight;
}items[25];
int c[1100];
int data[25][1100];
int ans;
int tem[25];
 
void knapsack(int n, int w){
	
	int counter=0;
    for (int i = 0; i < n; ++i){
    	for (int j = w; j >=items[i].weight; --j){
        	if (c[j -items[i].weight] + items[i].cost > c[j]){
                c[j] = c[j -items[i].weight] + items[i].cost;
                data[i][j]=1;
            }
		}
	}
    for (int i = n-1, j = w; i >= 0; --i){
    	if (data[i][j]){  
    		tem[counter++]=items[i].weight;
            j-=items[i].weight;
			ans+=items[i].weight;
        }
	}
	for(int i=counter-1; i>-1; i--) printf("%d ",tem[i]);
}

int main(){

	int w,t;
	while(scanf("%d%d",&w,&t)!=EOF){
		ans=0;
		memset(data, 0, sizeof(data));
		memset(c, 0, sizeof(c));
		for(int i=0; i<t; i++){
			scanf("%d",&items[i].weight);
			items[i].cost=items[i].weight;
		}
		knapsack(t,w); 
		printf("sum:%d\n",ans);
	}
	return 0;
}
