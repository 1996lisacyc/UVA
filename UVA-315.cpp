#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> arr[105];
int dfn[105], low[105];
int counter,ans;

void DFS(int cur, int parent){

    int child=0,check=0;
    low[cur]=dfn[cur]=++counter;
	
    for (int i = 0; i < arr[cur].size(); i++) {
    	
        int next=arr[cur][i];
        //printf("next=%d\n",next);
        if (!dfn[next]) {
            //還沒走過 child++ 
            child++; 
            DFS(next, cur);
            low[cur]=min(low[cur], low[next]);

            if (low[next]>=dfn[cur])//next is cur's child
            	check=1;
        }
        else if (next!=parent)
        	low[cur] = min(low[cur], dfn[next]);
    }
    
    if ((parent==-1 && child>1)||(parent!=-1 &&check))
    	ans++;
}

int main(){
	
	int n;
	while(scanf("%d",&n)&&n){
		
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		counter=ans=0;
		int x,y;
		string s1;
		
		for (int i = 0; i <n+1; ++i) {
            arr[i].clear();
        }

        while(getline(cin,s1)){
        	if(s1=="0") break;
        	stringstream s2(s1);
			s2>>x;
			while(s2>>y){
				arr[x].push_back(y);
				arr[y].push_back(x);
			}
		}
		
		DFS(1,-1);
		printf("%d\n",ans);
	}
	return 0;
}
