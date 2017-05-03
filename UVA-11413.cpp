#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int n,m;
	
	while(scanf("%d%d",&n,&m)!=EOF){
		
		int arr[n],tem=0,tot=0,counter,mid;
		for(int i=0; i<n; i++){
			scanf("%d",&arr[i]);
			tem=max(arr[i],tem);
			tot=tot+arr[i];
		} 

		int r=tot,l=tem;
		while(l<r){
			mid=(l+r)/2;
			tot=0;
			counter=0;
			for(int i=0; i<n; i++){
				tot=tot+arr[i];
				if(tot==mid){
					counter++;
					tot=0;
				}else if(tot>mid){
					counter++;
					tot=arr[i];
				}
			}
			if(tot>0) counter++;
			if(counter<=m){
				r=mid;
			}else{
				l=mid+1;
			} 
		}
		printf("%d\n",l);
	}
	return 0;
}
