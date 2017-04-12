#include <cstring>
#include <iostream>
using namespace std;

int main(){

	int n;
	while(scanf("%d",&n)!=EOF){
		
		int check=0,arr[n],c[3001];
		for(int i=0; i<3001; i++) c[i]=-1;
		for(int i=0; i<n; i++)scanf("%d",&arr[i]);
		for(int i =0; i<n-1; i++){
			int tem=(arr[i]>arr[i+1]?arr[i]-arr[i+1]:arr[i+1]-arr[i]);
			c[tem]=0;
		}
		for(int i=1; i<n; i++){
			if(c[i]!=0){
				check=1;
				break;
			}
		}
		if(check) printf("Not jolly\n");
		else printf("Jolly\n");
	}
	
	return 0;
}
