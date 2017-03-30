#include <cstdio>
#include <algorithm>
using namespace std;

struct customs{
	int day;
	int money;
	int num;
}shoe[1000];

bool cmp(const customs &a, const customs &b){
	if((double)a.money/(double)a.day>(double)b.money/(double)b.day) return true;
	else if((a.num<b.num)&&((double)a.money/(double)a.day==(double)b.money/(double)b.day)) return true;
	else return false;
}

int main() {
 	int t;
 	scanf("%d",&t);
    
    while(t--){ 
    
    	int n;
		scanf("%d",&n);
		for(int i =0; i<n; i++){
			scanf("%d%d",&shoe[i].day,&shoe[i].money);
			shoe[i].num=i+1;
		}	
		sort(shoe,shoe+n,cmp);
		for(int i=0; i<n; i++){
			printf("%d",shoe[i].num);
			if(i<n-1) printf(" ");
		}
    	printf("\n");
    	
    	if(t)
            printf("\n");/*check if last*/

	}
	
  return 0;
}
