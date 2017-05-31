#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

vector<int>edge[1005];
int visit[1005],llink[1005],rlink[1005];
bool used[1005];

bool DFS(int now){

    for(int i=0; i<(int)edge[now].size();i++){

        int next=edge[now][i];

        if(!used[next]){
            used[next]=true;
            if(!rlink[next]||DFS(rlink[next])){

                llink[now]=next;
                rlink[next]=now;
                return 1;
            }
        }
    }

    return 0;
}

int Bip(int nl,int nr){

    int ans=0;

    memset(llink,0,(nl+1)*sizeof(int));
    memset(rlink,0,(nr+1)*sizeof(int));

    for(int i=1; i<nl+1; i++){
        memset(used,0,(nr+1)*sizeof(bool));
        if(DFS(i)) ++ans;
    }
    return ans;
}

int main(){

    int t,Case=1;
    scanf("%d",&t);
    while(t--){

        int n,m,tem,ans=0;
        scanf("%d %d",&n,&m);
        memset(used,0,sizeof(used));
        memset(visit,0,sizeof(visit));

        for(int i=0; i<1005; i++) edge[i].clear();

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                scanf("%d",&tem);
                if(tem==1) edge[i].push_back(j);
            }
        }
        ans=Bip(n,m);
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", Case++,ans);
    }
    return 0;
}
