#include <cstdio>  
#include <iostream>  
#include <string>
#include <cstring>
#include <algorithm>
using namespace std; 
  
int main(){    

    string s1,s2;
    while(getline(cin,s1)){
    	getline(cin,s2);
    	int len1=s1.length();
    	int len2=s2.length();
    	int arr[len1+1][len2+1];
    	memset(arr,0,sizeof(arr));

    	for(int i=1; i<len1+1; i++){
    		for(int j=1; j<len2+1; j++){
    			if(s1[i-1]==s2[j-1]){
    				arr[i][j]=arr[i-1][j-1]+1;
				} 
    			else {
    				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
		/*for(int i=0; i<=len1; i++){
			for(int j=0; j<=len2; j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",arr[len1][len2]);
	}
    return 0;  
}  
