#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int calculate(string s){
	
	int ans=0,tem;
	for(int i=0; i<s.length(); i++){
		if(s[i]!=' '){
			tem=s[i]-'A'+1;
			if((tem<59)&&(tem>32)){
				tem=tem-32;
				ans+=tem;
			}else if((tem>0)&&(tem<27)){
				ans+=tem;
			}
		}
	}
	while(ans>=10){
		ans=ans/10+ans%10;
	}
	return ans;
}

int main(){
	
	string s1,s2;
	while(getline(cin,s1)){
		
		getline(cin,s2);
		double num1,num2,ans;
		num1=calculate(s1);
		num2=calculate(s2);
		ans=(num1>num2?(num2/num1):(num1/num2));
		printf("%.2lf %%\n",ans*100);
	}
	return 0; 
}
