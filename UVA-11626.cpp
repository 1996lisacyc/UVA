#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Point{
	int x, y;
}P[100005],CH[100005*2];
int n;

bool cmp(const Point& a, const Point& b){
	if(a.x != b.x)
        return b.x > a.x;
	else
        return b.y > a.y;
}

int cross(Point o, Point a, Point b) {
    long long int x1=a.x-o.x;
    long long int y1=b.y-o.y;
    long long int x2=b.x-o.x;
    long long int y2=a.y-o.y;
    long long tem=x1*y1-x2*y2;
    if(tem>0) return 1;
    else if(tem<0) return -1;
    else return 0;
}

int Andrew(){

    sort(P, P+n, cmp);
    int m=0;

    for(int i=0; i<n; i++) {
		while(m>=2 && cross(CH[m-2], CH[m-1], P[i])<0) m--;
		CH[m++]=P[i];
	}

	for(int i=n-2, j=m+1; i>-1; i--) {
		while(m>=j && cross(CH[m-2], CH[m-1], P[i])<0) m--;
		CH[m++]=P[i];
	}
    m--;
	printf("%d\n",m);
	for(int i=0; i<m; i++){
        printf("%d %d\n",CH[i].x,CH[i].y);
	}
}
int main() {

    int t;
    string s1;

    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        for(int i=0; i<n; ){
            scanf("%d%d",&P[i].x,&P[i].y);
            cin>>s1;
            if(s1=="N") n--;
            else i++;
        }
        Andrew();
    }
    return 0;
}
