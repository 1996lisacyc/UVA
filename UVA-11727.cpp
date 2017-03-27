#include <cstdio>
#include <algorithm>
using namespace std;
int line[3];

int main() {
 	int n,Case=1;;
    while(scanf("%d",&n)!=EOF) {
    	
    	for(int i=0; i<n; i++){
    		for(int j=0; j<3; j++) scanf("%d",&line[j]);
    		sort(line,line+3);
			printf("Case %d: %d\n",Case++,line[1]);
		} 
   }
 
  return 0;
}
