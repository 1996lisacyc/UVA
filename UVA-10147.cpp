#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
	double x;
	double y;
}node[755];

struct Edge{
	int a;
	int b;
	double len;
}edge[755*755];

int p[755];

bool cmp(const Edge& edge1, const Edge& edge2){
	return 	 edge1.len< edge2.len;
}

int Find(int x){

    if (x==p[x])
        return x;
    return p[x]=Find(p[x]);
}

void Union(int x, int y){

    x=Find(x);
    y=Find(y);

    if (x!=y) {
        p[x]=y;
    }
}

void Kruskal(int n,int E){
	
	int ans=0;
	sort(edge,edge+E,cmp);

    for (int j=0; j<E; j++){

        if(Find(edge[j].a)!=Find(edge[j].b)){
        	Union(edge[j].a, edge[j].b);
        	printf("%d %d\n",edge[j].a,edge[j].b);
        	ans+=edge[j].len;
		}
    }
    
   	if(ans==0) printf("No new highways need\n");
}

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		
		scanf("\n");
		int N,M,x,y,counter=0;
		
		scanf("%d",&N);
		
		for(int i=0; i<N+1; i++){
			p[i]=i;
		}
		
		for(int i=1; i<N+1; i++){
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}	
		
		scanf("%d",&M);
		
		for(int i=0; i<M; i++){
			scanf("%d %d", &x, &y);
			Union(x, y);
		}
		
		for(int i=1; i<N+1; i++){
			for(int j=i+1; j<N+1; j++){
				edge[counter].a=i;
				edge[counter].b=j;
				edge[counter++].len=sqrt(pow(node[i].x-node[j].x, 2)+pow(node[i].y-node[j].y, 2));
			}
		}
		
		Kruskal(N-M,counter);
		if(t) printf("\n");
	}
	return 0;
}
