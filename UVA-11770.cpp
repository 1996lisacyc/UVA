#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

vector<int> adj[100005];
bool instack[10005];
int visit[10005],parent[10005],record[10005],low[10005];
stack<int> stk;
int counter,c, n, m;

void DFS(int i){

    visit[i]=low[i]=++c;
    stk.push(i);
    instack[i]=1;
    
    for (int j=0; j<adj[i].size(); j++){
    	
    	if(!visit[adj[i][j]])
            DFS(adj[i][j]);

        if(instack[adj[i][j]])
            low[i] = min(low[i], low[adj[i][j]]);
	}
 
    if (visit[i]==low[i]){ 
    	counter++;
    	record[counter]=0;
        int j;
        do{
            j=stk.top();
            stk.pop();
            instack[j]=0;
            parent[j]=counter;
        } while (j!=i);
    }
}
 
int main(){

    int t,Case=1;
    scanf("%d", &t);
    while(t--){
    
    	int x,y,ans=0;
    	c=counter=0;
		memset(adj,0,sizeof(adj));
		memset(visit, 0, sizeof(visit));
		memset(instack,0,sizeof(instack));
		while(!stk.empty()) stk.pop();
		for(int i=0; i<n+1; i++) adj[i].clear();
    	
    	scanf("%d %d",&n,&m);
		for(int i=0; i<m; i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
		}
		
    	for (int i=1; i<n+1; i++){
    		if (!visit[i])
            	DFS(i);
		}
		
    	for(int i=1; i<n+1; i++){
    		for(int j=0; j<adj[i].size(); j++){
    			if(parent[i]!=parent[adj[i][j]])
                    record[parent[adj[i][j]]]++;
			}
		}
 
        for(int i=1; i<counter+1; i++){
        	if(!record[i])
                ans++;
		}
        printf("Case %d: %d\n",Case++, ans);
    }
    return 0;
}
