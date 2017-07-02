#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int adj[25][25];

void DFS(int &n, int i, int j){

    adj[i][j] =0;
    if (i-1 >= 0 && adj[i-1][j] ==1) DFS(n, i-1, j);/*檢查上下左右*/
    if (i+1 <  n && adj[i+1][j] ==1) DFS(n, i+1, j);
    if (j-1 >= 0 && adj[i][j-1] ==1) DFS(n, i, j-1);
    if (j+1 <  n && adj[i][j+1] ==1) DFS(n, i, j+1);
    if (i-1 >= 0 && j-1 >= 0 && adj[i-1][j-1] ==1) DFS(n, i-1, j-1);/*檢查四個斜角*/ 
    if (i-1 >= 0 && j+1 <  n && adj[i-1][j+1] ==1) DFS(n, i-1, j+1);
    if (i+1 <  n && j-1 >= 0 && adj[i+1][j-1] ==1) DFS(n, i+1, j-1);
    if (i+1 <  n && j+1 <  n && adj[i+1][j+1] ==1) DFS(n, i+1, j+1);
}

int main(){

	int n,i,j,counter1=1,counter2=0;
	char c;
	
	while(scanf("%d\n",&n)!=EOF){
		counter2=0;
		for(i=0; i<n; i++){
			for (j=0; j<n; j++){
				c=getchar();
				adj[i][j]=c-'0';		
			}
			if(i<n-1){scanf("\n");}
		}		
		for(i=0; i<n; i++){
			for (j=0; j<n; j++){
				if(adj[i][j]==1){
					DFS(n, i, j);
                    ++counter2;
				}
			}
		}	
		printf("Image number %d contains %d war eagles.\n",counter1++,counter2);  
	}
    return 0;
}

