#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 100000000
using namespace std;

int visit[205],pa[205];
int cap[205][205],flow[205][205];
int n=0;

int findFlow(int s, int t) {
    int f = INF;
    for (int i = t, pre; i != s; i = pre) {
        pre = pa[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            f = min(f, cap[pre][i] - flow[pre][i]);
        else
            f = min(f, flow[i][pre]);
    }
    for (int i = t, pre; i != s; i = pre) {
        pre = pa[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else
            flow[i][pre] -= f;
    }
    return f;
}

bool DFS(int k, int t) {
    visit[k] = 1;
    if (k == t) return 1;
    for (int i = 0; i < n+1; ++i ) {
        if (visit[i]) continue;
        if (cap[k][i]-flow[k][i]>0 || flow[i][k]>0) {
            pa[i] = k;
            if (DFS(i, t)) return 1;
        }
    }
    return 0;
}

int FF(int s, int t){

    int ret = 0;
    while (1){
        memset(visit, 0, sizeof(visit));
        if (!DFS(s, t)) break;
        ret += findFlow(s, t);
    }
    return ret;
}

int main(){

	while(scanf("%d",&n)==1){

		memset(cap,0,sizeof(cap));
		memset(visit,0,sizeof(visit));
		memset(pa,0,sizeof(pa));
		memset(flow,0,sizeof(flow));

		int m,a,b,c,ans=0;

        for(int i=1; i<n+1 ; i++){
            scanf("%d",&c);
            cap[i][i]=c;
        }

        scanf("%d",&m);
		for(int i=0; i<m; i++){
			scanf("%d %d %d",&a,&b,&c);
			cap[a][b]+=c;
			if(cap[a][b]>cap[a][a]||cap[a][b]>cap[b][b])
                cap[a][b]=min(cap[a][a],cap[b][b]);
		}

		scanf("%d %d",&a,&b);
		for(int i=0; i<a; i++){
            scanf("%d",&c);
            cap[0][c]=cap[c][c];
		}
		for(int i=0; i<b; i++){
            scanf("%d",&c);
            cap[c][n+1]=cap[c][c];
		}
        n++;
		ans=FF(0,n);
        printf("%d\n",ans);
	}
	return 0;
}
