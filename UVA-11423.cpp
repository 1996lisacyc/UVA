#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define MAX 16777215
using namespace std;

int cach[35],ans[35],s[MAX],v[MAX];
int n,cur;

int lowbit(int b){
    return b&(-b);
}

void modify(int index, int delta){

    for(int i=index; i<MAX; i+=lowbit(i)){
        s[i]+=delta;
    }
}

int getsum(int index){

    int ans=0;
    while(index>0){
        ans+=s[index];
        index-=lowbit(index);
    }
    return ans;
}

int getlen(int L, int R) {
    return getsum(R)-getsum(L-1);
}

void solve(int num){

    if(v[num]){

        int len=getlen(v[num],cur);
        for(int i=0; i<n; i++){
            if(cach[i]>len-1) break;
            ans[i]++;
        }
        modify(v[num], -1);

    }else {

        for(int i=0; i<n; i++){
            ans[i]++;
        }
    }
    v[num]=++cur;
    modify(v[num], 1);
}

int main(){

    while(scanf("%d",&n)!=EOF){

        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));
        string s1;
        int x,y,z;
        cur=0;

        for(int i=0; i<n; i++){
            scanf("%d",&cach[i]);
        }

        while(cin>>s1){
        	
            if(s1=="END") break;
            else if(s1=="RANGE"){

                scanf("%d%d%d",&x,&y,&z);
                for(int i=0; i<z; i++){
                    solve(x+y*i);
                }

            }else if(s1=="ADDR"){

                scanf("%d",&x);
                solve(x);

            }else if(s1=="STAT"){

                for(int i=0; i<n-1; i++) printf("%d ",ans[i]);
                printf("%d\n",ans[n-1]);
                memset(ans,0,sizeof(ans));
            }
        }
    }
    return 0;
}
