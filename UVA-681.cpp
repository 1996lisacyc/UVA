#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point{
    int x, y;
}P[10005], CH[10005*2];
int n;

bool cmp(const Point& a, const Point& b){
	if(a.y!= b.y)
        return b.y > a.y;
	else
        return b.x > a.x;
}

int cross(Point o, Point a, Point b) {
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

int Andrew(){

    sort(P, P+n, cmp);
    int m=0;

    for(int i=0; i<n; i++) {
		while(m>=2 && cross(CH[m-2], CH[m-1], P[i])<=0) m--;
		CH[m++]=P[i];
	}

	for(int i=n-2, j=m+1; i>=0; i--) {
		while(m>=j && cross(CH[m-2], CH[m-1], P[i])<=0) m--;
		CH[m++]=P[i];
	}

	printf("%d\n", m);
    for(int i=0; i <m; i++){
        printf("%d %d\n", CH[i].x, CH[i].y);
    }
}

int main()
{
    int t, check=0;
    scanf("%d",&t);
    printf("%d\n",t);

    while(t--){

        if(check) printf("-1\n");
        else check=1;

        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&P[i].x,&P[i].y);
        }
        Andrew();
        scanf("%d", &n);
    }
    return 0;
}
