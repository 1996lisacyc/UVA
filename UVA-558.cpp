#include <cstdio>
#define INF 100000
using namespace std;

int dis[1005];

void relax(int u,int v,int w){

	if(dis[u]+w<dis[v]){
		dis[v]=dis[u]+w;
	}
}

int main(){
	
	int f;
	scanf("%d",&f);
	while(f--){
		
		int N,M;
		scanf("%d%d",&N,&M);
		
		int t1[M],t2[M],t3[M];
		for(int i=0; i<M; i++){
			scanf("%d %d %d",&t1[i],&t2[i],&t3[i]);
		}
		
		for(int i=1; i<N; i++) dis[i]=INF;
		dis[N]=0;
		
		for(int i=0; i<N-1; i++){	
			for(int j=0; j<M; j++){
				relax(t1[j],t2[j],t3[j]);
			}
		}
		int check=1;
		
		for(int j=0; j<M; j++){
			if(dis[t1[j]]+t3[j]<dis[t2[j]]){
				check=0;
				break;
			}
		}
		
		if(check) printf("not possible\n");
		else printf("possible\n");
	}
	return 0;
}
