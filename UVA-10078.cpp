#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
}P[10005];
int n;

int cross(Point o, Point a, Point b) {
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

int check(){

    P[n]=P[0];
    P[n+1]=P[1];

    if(cross(P[0], P[1], P[2])>=0){
        for(int i=0; i<n; i++){
            if(cross(P[i],P[i+1],P[i+2])<0)
                return 1;
        }
    }else{
        for(int i=0; i<n; i++){
            if(cross(P[i],P[i+1],P[i+2])>0)
                return 1;
        }
    }
    return 0;
}

int main() {

    while(scanf("%d",&n)&&n){

        for(int i=0; i<n; i++){
            scanf("%d%d",&P[i].x,&P[i].y);
        }

        if(check())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
