#include <algorithm>  
#include <cstdlib>  
#include <cstdio>  
using namespace std;  
  
struct Item{
	int val;
	int weight;
}items[120];
int c[10400];

void knapsack(int n, int w){
 
    for (int i=1; i<n+1; ++i){
    
        int weight=items[i].weight;
        int val=items[i].val;
        for (int j=w; j-weight>=0; --j){
        	c[j]=max(c[j], c[j-weight]+val);
		}
    }
}
  
int main(){    

    int w,n;  
    while (scanf("%d%d",&w,&n)!=EOF){   
    
        if (w>1800) w+=200;
		int tem=w;   
        for(int i=0; i<10400; i++) c[i]=0;
        for(int i=1; i<n+1; i++) scanf("%d%d",&items[i].weight, &items[i].val);
        knapsack(n,w); 

        while (tem>0&&c[tem]==c[tem-1]) --tem;  
        if (tem<=2000&&w>2000) printf("%d\n",c[w-200]);  
        else printf("%d\n",c[w]);  
    }  
    return 0;  
}  

