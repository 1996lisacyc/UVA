#include <cstdio>  
#include <algorithm>  
using namespace std; 
  
int main(){    

    int n;
    while(scanf("%d",&n)!=EOF){
    	
    	int arr[n],Q,ans1,ans2,l,r,mid,check;
    	
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		sort(arr,arr+n);
		scanf("%d",&Q);
		int data[Q];
		for(int i=0; i<Q; i++) scanf("%d",&data[i]);	
    	
    	for(int i=0; i<Q; i++){
    		
    		ans1=lower_bound(arr,arr+n,data[i])-arr-1;
    		ans2=upper_bound(arr,arr+n,data[i])-arr;
			ans1=(ans1<0?0:arr[ans1]);
			ans2=(ans2>n-1?0:arr[ans2]);
			if(!ans2) printf("%d X\n",ans1);
			else if(!ans1) printf("X %d\n",ans2);
			else printf("%d %d\n",ans1,ans2);
		} 
	}
    return 0;  
}  
