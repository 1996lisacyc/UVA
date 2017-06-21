#include <cstdio>
#include <cstring>
using namespace std;

int rec[205][205];

int check(int x1, int y1, int x2, int y2){

    x1+=100,x2+=100, y1+=100, y2+=100;

    for(int i=x1+1; i<x2+1; i++){
        for(int j=y1+1; j<y2+1; j++){
            if(rec[i][j]!=0) return 0;
        }
    }

    for(int i=x1+1; i<x2+1; i++){
        for(int j=y1+1; j<y2+1; j++){
            rec[i][j]=1;
        }
    }
    return 1;
}

int main(){

    int t,Case=1;;
    scanf("%d",&t);
    while(t--){

        int n,ans=0;
        memset(rec,0,sizeof(rec));

        scanf("%d",&n);
        for(int i=0; i<n; i++){

            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(check(x1,y1,x2,y2)){
                ans+=(x2-x1)*(y2-y1);
            }

        }
        printf("Case %d: %d\n", Case++, ans);
    }
    return 0;
}
