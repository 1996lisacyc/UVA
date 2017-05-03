#include <cstdio>
using namespace std;

int main(){
	
	int counter=0,n=0,p2=0,p3=0;
	int arr[500];
	for(int i=0; i<500; i++) arr[i]=1;
	
	while(arr[counter]>arr[counter-1]){
		if(arr[p2]*2<arr[p3]*3){
			arr[++counter]=arr[p2++]*2;
		}else if(arr[p2]*2>arr[p3]*3){
			arr[++counter]=arr[p3++]*3;
		}else{
			p2++;
			arr[++counter]=arr[p3++]*3;
		}
		//printf("arr[%d]=%d\n",counter-1,arr[counter-1]);
	}
	
	while(scanf("%d",&n)){
		if(!n) break;
		for(int i=0; i<counter; i++){
			if (arr[i]>=n){
        	  printf("%d\n", arr[i]);
        	  break;
      		}
		}	
	}
	return 0;
}
