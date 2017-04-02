#include <cstdio>

using namespace std;
int ans[92][8][8]={0};
int slash1[16] = {0};
int slash2[16] = {0}; 
int column[8] = {0};
int queens[8] = {0};
int index;

void set(){

    for(int i=0; i<8; i++)
	 for(int j=0; j<8; j++)
	 	if(queens[i]==j) ans[index][i][j]=1;
	 	
    index++;
}

void back(int counter){ 
    if(counter>= 8) set();
    else { 

        for(int i= 0; i< 8; i++) {
            if(!column[i]&&!slash1[counter+i]&&!slash2[counter-i+8]) { 
                queens[counter]=i; 
                column[i]=slash1[counter+i]=slash2[counter-i+8] = 1; 
                back(counter+1); 
                column[i]=slash1[counter+i]=slash2[counter-i+8] = 0;
            } 
        }
    }
}

int main(){
	
	index=0;
    back(0); 
	
	int t;
	scanf("%d\n",&t);
	while(t--){
		
		int tem=0,output=0;
		int arr[8][8];
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				scanf("%d",&arr[i][j]);	
			}
			if(i<7) scanf("\n");
		}
		
		for(int i=0; i<92; i++){
			tem=0;
			for(int j=0; j<8; j++){
				for(int k=0; k<8; k++){
					if(ans[i][j][k]) tem+=arr[j][k];
				}
			}
			output=(output>tem?output:tem);
		}
		printf("%5d\n",output);
	}
	return 0;
}
