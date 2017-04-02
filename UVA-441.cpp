#include <iostream>
#include <cstdio>

using namespace std;
int n;
int arr[14];
int ans[6];

void possible(int counter, int index){
	
	if(index==6){
		for(int i=0; i<6; i++){
			if(i!=0) printf(" %d",ans[i]);
			else printf("%d",ans[i]);
		} 
		printf("\n");
		return ;
	}
	for(int i=counter; i<n; i++){
		ans[index]=arr[i];
		possible(i+1, index+1);
	}
}

int main(){
	int check=0;
	while(scanf("%d",&n)&&n){
		if(check) printf("\n");
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		possible(0,0);
		check=1;
	}
	return 0; 
}
