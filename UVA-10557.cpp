#include <cstdio>
#include <queue>
#include <cstring>
#define INF 1000000
using namespace std;

int main(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		
		if(n==-1) break;
		
		int check=0,value[n+1],way[n+1][n+1],dis[n+1],in[n+1];
		memset(dis,0,sizeof(dis));
		memset(in,0,sizeof(in));
		memset(way,0,sizeof(way));
		queue<int> q;
		in[1]=1;
		dis[1]=100;
		q.push(1);

		for(int i=1; i<n+1; i++){
			scanf("%d %d",&value[i],&way[i][0]);
			for(int j=1; j<way[i][0]+1; j++)
				scanf("%d",&way[i][j]);
		}
		
		while(!q.empty()){
			int cur= q.front();
			in[cur]=0;
			q.pop();

			for(int i=1; i<way[cur][0]+1; i++){
				
				int next=way[cur][i];
				
				if(dis[cur]+value[next]>dis[next]){
					
					dis[next]=dis[cur]+value[next];
					if(in[next]==0){
						q.push(next);
						in[next]=1;
						check++;
					}
				}
			}
			if(check>INF||dis[n]>0) break;
		}

		if (dis[n]>0) printf("winnable\n");
        else printf("hopeless\n");
	}
	return 0;
}
