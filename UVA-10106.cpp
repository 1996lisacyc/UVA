#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int num1[500];
int num2[500];
int ans[500];

void init(void){
	for(int i=0; i<500; i++){
		num1[i]=num2[i]=ans[i]=0;
	}
}

int main(){

	string s1,s2;
	
	while(cin>>s1>>s2){
		
		init();
		int index=0;
		for(int i=s1.length()-1; i>-1; i--){
			num1[i]=s1[index++]-'0';
		}
		index=0;
		for(int i=s2.length()-1; i>-1; i--){
			num2[i]=s2[index++]-'0';
		}

		for(int i=0; i<s1.length(); i++){
			for(int j=0; j<s2.length(); j++){
				
				ans[i+j]=ans[i+j]+num1[i]*num2[j];
				ans[i+j+1]=ans[i+j+1]+ans[i+j]/10;
				ans[i+j]=ans[i+j]%10;
				
			}
		}
		
		index=0;
		for(int i=499; i>-1; i--){
			if(ans[i]!=0){
				index=i;
				break;
			}
		}
		
		for(int i=index; i>-1; i--){
			printf("%d",ans[i]);
		}
		printf("\n");
	}	
}
