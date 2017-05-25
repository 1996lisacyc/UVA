#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
	double x;
	double y;
}node[505];

struct Edge{
	int a;
	int b;
	double len;
}edge[505*505];

int p[505];

bool cmp(const Edge& edge1, const Edge& edge2){
	return 	 edge1.len< edge2.len;
}

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
    }
}

void Kruskal(int n,int E,int index){
	
	vector<double>ans;
	sort(edge,edge+E,cmp);
	
    for (int i=0,j=0; i<n-1&&j<E; i++){

        while (Find(edge[j].a)==Find(edge[j].b)) j++;
        Union(edge[j].a, edge[j].b);
        ans.push_back(edge[j].len);
        j++;
    }
    
    printf("%.2lf\n",ans[index]);
}

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		
		int S,P,counter=0;
		double ans;
		scanf("%d %d",&S,&P);
		
		for(int i=0; i<P+1; i++){
			p[i]=i;
		}
		
		for(int i=0; i<P; i++){
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}	
		
		for(int i=0; i<P; i++){
			for(int j=i+1; j<P; j++){
				edge[counter].a=i;
				edge[counter].b=j;
				edge[counter++].len=sqrt(pow(node[i].x-node[j].x, 2)+pow(node[i].y-node[j].y, 2));
			}
		}
		
		Kruskal(P,counter,P-S-1);
	}
	return 0;
}
