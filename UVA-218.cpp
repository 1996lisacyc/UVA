#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point{
	double x, y;
}P[10005],CH[10005];
int n;

double cross(Point o, Point a, Point b) {
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

bool cmp(const Point& a, const Point& b){
	if(a.x != b.x)
        return b.x < a.x;
	else
        return b.y < a.y;
}

int Andrew(){

	sort(P, P+n, cmp);
	double ans=0;
	int m=0;

	for(int i=0; i<n; i++) {
		while(m>=2 && cross(CH[m-2], CH[m-1], P[i])>=0) m--;
		CH[m++]=P[i];
	}

	for(int i=n-1, j=m+1; i>-1; i--) {
		while(m>=j && cross(CH[m-2], CH[m-1], P[i])>=0) m--;
		CH[m++]=P[i];
	}

    for(int i=0; i<m-1; i++){
        ans+=sqrt((CH[i+1].x-CH[i].x)*(CH[i+1].x-CH[i].x)+(CH[i+1].y-CH[i].y)*(CH[i+1].y-CH[i].y));
        printf("(%.1lf,%.1lf)-",CH[i].x,CH[i].y);
    }
    printf("(%.1lf,%.1lf)\n",CH[m-1].x,CH[m-1].y);
    printf("Perimeter length = %.2lf\n",ans);
}

int main() {

	int Case=1;
	while(scanf("%d",&n)&&n){

        for(int i=0; i<n; i++){
            scanf("%lf%lf",&P[i].x,&P[i].y);
        }
		if(Case!=1)	printf("\n");
		printf("Region #%d:\n", Case++);
		Andrew();
	}
    return 0;
}
