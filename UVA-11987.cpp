#include <cstdio>
using namespace std;

int p[100005],sum[100005],counter[100005];
//vector<int> v[100005];

int Find(int x){

    if (x==p[x])
        return x;
    return p[x]=Find(p[x]);
}

void Union(int x, int y){

    x=Find(x);
    y=Find(y);

    if (x!=y) {
        p[x]=y;
        sum[y]+=sum[x];
        counter[y]+=counter[x];
    }
}

int main(){

    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){

        for(int i=1; i<n+1; i++){
            p[i]=p[i+n]=i+n;
            counter[i+n]=1;
            sum[i+n]=i;
        }

		while(m--){

            int status,x,y;
            scanf("%d",&status);

            if(status==1){

                scanf("%d %d",&x,&y);
                Union(x,y);

            }else if(status==2){

                scanf("%d %d",&x,&y);
                int tem=x;
                x=Find(x),y=Find(y);
                if(x!=y){
                    p[tem]=y;
                    sum[y]+=tem;
                    sum[x]-=tem;
                    counter[y]++;
                    counter[x]--;
                }

            }else if(status==3){

                scanf("%d",&x);
                int tem=Find(x);
                printf("%d %d\n", counter[tem],sum[tem]);

            }
		}
    }
    return 0;
}
