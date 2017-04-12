#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm> 
using namespace std;

struct Item{
	int cost;
	int weight;
}items[30];
int c[1010];
int data[30][1010];
int tem[30];
 
void knapsack(int n, int w,int p){
	
	int counter=0,ans1=0,ans2=0;
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
    		tem[counter++]=i;
            j-=items[i].weight;
			ans1+=items[i].cost;
			ans2++;
        }
	}
	printf("%d\n%d\n",ans1,ans2);
	for(int i=counter-1; i>-1; i--) printf("%d %d\n",items[tem[i]].weight/(3*p), items[tem[i]].cost);
}

int main(){

	int w,t,num,check=0;
	while(scanf("%d%d",&t,&w)!=EOF){
		
		if(check) printf("\n");
		scanf("%d",&num);
		memset(data, 0, sizeof(data));
		memset(c, 0, sizeof(c));
		for(int i=0; i<num; i++){
			scanf("%d%d",&items[i].weight,&items[i].cost);
			items[i].weight=items[i].weight*3*w;
		}
		knapsack(num,t,w); 
		check=1;
	}
	return 0;
}
