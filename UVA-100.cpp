#include<cstdio>
#include<iostream>
using namespace std;

int rec(int n){
	if(n==1){ return 1;	}
	if(n%2){ return 1+rec(3*n+1); }
	else{ return 1+rec(n/2);	}
}

int main(){

	int i,j;
	
	while(scanf("%d%d",&i,&j)!=EOF){
		
		int min=0,max=0,counter=0,tem=0;
		if(i>j){ max=i, min=j;	}
		else { max=j; min=i;	}
		for(int k=min; k<max+1; k++){
			tem=rec(k);
			counter=(counter<tem?tem: counter);
		}
		printf("%d %d %d\n",i,j,counter);
	}
    return 0;
}
