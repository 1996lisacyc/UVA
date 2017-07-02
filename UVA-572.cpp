#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char adj[100][100];

void DFS(int n, int m, int i, int j){

    adj[i][j] ='*';
    if (i-1 >= 0 && adj[i-1][j] =='@') DFS(n, m, i-1, j);/*檢查上下左右*/
    if (i+1 <  m && adj[i+1][j] =='@') DFS(n, m, i+1, j);
    if (j-1 >= 0 && adj[i][j-1] =='@') DFS(n, m, i, j-1);
    if (j+1 <  n && adj[i][j+1] =='@') DFS(n, m, i, j+1);
    if (i-1 >= 0 && j-1 >= 0 && adj[i-1][j-1] =='@') DFS(n, m, i-1, j-1);/*檢查四個斜角*/ 
    if (i-1 >= 0 && j+1 <  n && adj[i-1][j+1] =='@') DFS(n, m, i-1, j+1);
    if (i+1 <  m && j-1 >= 0 && adj[i+1][j-1] =='@') DFS(n, m, i+1, j-1);
    if (i+1 <  m && j+1 <  n && adj[i+1][j+1] =='@') DFS(n, m, i+1, j+1);
}
int main(){

	int m,n;
	
	while(scanf("%d%d\n",&m,&n)){
		int ans=0,i,j;
		char c;
		if(!m){break;}
		memset(adj,0,sizeof(adj));
		
		for(i=0; i<m; i++){
			for (j=0; j<n; j++){
				c=getchar();
				adj[i][j]=c;		
			}
			if(i<m-1){scanf("\n");}
		}
		for(i=0; i<m; i++){
			for (j=0; j<n; j++){
				if(adj[i][j]=='@'){
					DFS(n, m, i, j);
                    ++ans;
				}
			}
		}	
		printf("%d\n",ans);
	}
    return 0;
}

