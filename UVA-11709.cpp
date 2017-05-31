#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool instack[2005];    
int adj[2005][2005],visit[2005],low[2005],parent[2005];   
int ans=0,p,c;
map <string, int> Map;
stack<int> stk; 

void DFS(int i){

    visit[i]=low[i]=++c;
    stk.push(i);
    instack[i]=1;
    //printf("i=%d\n",i);
 
    for (int j=1; j<p+1; ++j){
    	if (adj[i][j]){

            if (!visit[j])
            	DFS(j);
            	
            if (instack[j])
            	low[i]=min(low[i], low[j]);
        }
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
	
	int t;
	while(scanf("%d %d",&p,&t)){
		
		if(!p&&!t) break;
		scanf("\n");
		memset(adj,0,sizeof(adj));
		memset(visit, 0, sizeof(visit));
    	string s1,s2;
    	ans=c=0;
    	
		for(int i=1; i<p+1; i++){
			getline(cin,s1);
			Map[s1]=i;
		}
		
		for(int i=1; i<t+1; i++){
			getline(cin,s1);
			getline(cin,s2);
			adj[Map[s1]][Map[s2]]=1;
		}
 
    	for (int i=1; i<p+1; ++i){
    		if (!visit[i])
            	DFS(i);
		}
    	printf("%d\n",ans);
	}
	return 0;
}
