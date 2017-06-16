#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point{
	long long int x, y;
}P[10005],CH[10005];
int n;

bool cmp(const Point& a, const Point& b){
	if(a.x != b.x)
        return b.x < a.x;
	else
        return b.y < a.y;
}

long long int cross(Point o, Point a, Point b) {
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
int Andrew(){

    sort(P, P+n, cmp);
    int m=0,index=0;;

    for(int i=0; i<n; i++) {
		while(m>=2 && cross(CH[m-2], CH[m-1], P[i])<0) m--;
		CH[m++]=P[i];
	}

	for(int i=n-2, j=m+1; i>-1; i--) {
		while(m>=j && cross(CH[m-2], CH[m-1], P[i])<0) m--;
		CH[m++]=P[i];
	}
	m--;

	for(int i=0; i<m; i++) {
        if((CH[i].x==CH[index].x&&CH[i].y<CH[index].y)||CH[i].x>CH[index].x)
            index=i;
    }
    for(int i=index; i<m; i++){
        printf(" (%lld,%lld)", CH[i].x, CH[i].y);
    }
    for(int i=0; i<index; i++){
        printf(" (%lld,%lld)", CH[i].x, CH[i].y);
    }
    printf("\n");
}
int main() {

    string s1;
    int flag=0;
    char cmd;

    while(scanf("%c",&cmd)){

        if(cmd=='P'){

            flag=1;
            getchar();
            int t;
            scanf("%d", &t);
            for(int i=n; i<n+t; i++){
                scanf("%lld%lld", &P[i].x, &P[i].y);
            }
            n+=t;

        }else if(cmd=='S'){

            if(flag){
                sort(P, P+n, cmp);
                int counter=0;
                for(int i=1; i<n; i++){
                    if(P[counter].x != P[i].x || P[counter].y != P[i].y)
                        P[++counter] = P[i];
                }
                n=counter+1;
                Andrew();
            }
            flag=n=0;
            getchar();
            getline(cin,s1);
            cout<<s1<<" convex hull:"<<endl;

        }else if(cmd=='E'){

            if(flag){
                sort(P, P+n, cmp);
                int counter=0;
                for(int i=1; i<n; i++){
                    if(P[counter].x != P[i].x || P[counter].y != P[i].y)
                        P[++counter] = P[i];
                }
                n=counter+1;
                Andrew();
            }
            break;
        }
    }
    return 0;
}
