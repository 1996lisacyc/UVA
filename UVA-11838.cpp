#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

bool instack[2005];    
int adj[2005][2005],visit[2005],low[2005],parent[2005]; 
stack<int> stk;    
int ans=0,t=0,N=0;
 
void DFS(int i){

    visit[i]=low[i]=++t;
    stk.push(i);
    instack[i]=1;
 
    for (int j=1; j<N+1; j++)
        if (adj[i][j]){

            if (!visit[j])
                DFS(j);

            if (instack[j])
                low[i]=min(low[i], low[j]);
        }

    if (visit[i]==low[i]){
    	ans++;
        int j;
        do{
            j=stk.top();
            stk.pop();
            instack[j]=0;
            parent[j]=i;
        } while (j!=i);
    }
}

int main(){
	
	int m;
	while(scanf("%d %d",&N,&m)&&N&&m){
		
		int a,b,c;
		memset(adj,0,sizeof(adj));
		memset(visit, 0, sizeof(visit));
    	t=ans=0;
		for(int i=1; i<m+1; i++){
			scanf("%d %d %d",&a,&b,&c);
			if(c==1){
				adj[a][b]=1;
			}else{
				adj[a][b]=adj[b][a]=1;
			}
		}
 
    	for (int i=1; i<N+1; ++i){
    		if (!visit[i])
            	DFS(i);
		}
        if(ans==1) printf("1\n");
        else printf("0\n");
	}
	return 0;
}
