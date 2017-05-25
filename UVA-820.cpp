#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 100000000
using namespace std;

int visit[105],pa[105];
int cap[105][105],flow[105][105];
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
    for (int i = 1; i < n+1; ++i ) {
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

	int Case=1;
	while(scanf("%d",&n)&&n){

		memset(cap,0,sizeof(cap));
		memset(visit,0,sizeof(visit));
		memset(pa,0,sizeof(pa));
		memset(flow,0,sizeof(flow));

		int S,T,C,ans=0,a,b,c;
		scanf("%d %d %d",&S,&T,&C);

		for(int i=0; i<C; i++){
			scanf("%d %d %d",&a,&b,&c);
			cap[b][a]=cap[a][b]+=c;
		}
		ans=FF(S,T);
        printf("Network %d\nThe bandwidth is %d.\n\n", Case++,ans);
	}
	return 0;
}
