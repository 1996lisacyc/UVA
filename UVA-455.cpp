#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string s;
int pi[85];

int KMP(void){
	
	int len=s.length(),cur_pos=-1;
	pi[0]=-1;
	for(int i=1; i<len; ++i) {
		while(~cur_pos && s[i]!=s[cur_pos+1])
			cur_pos = pi[cur_pos];
		if(s[i]==s[cur_pos+1]) ++cur_pos;
		pi[i]=cur_pos;
	}
	return cur_pos;
}

int main(){
	
	int n,ans,check=0;
	scanf("%d",&n);
	while(n--){
		
		scanf("\n");
		cin>>s;
		
		if(check) printf("\n");
		
		int len=s.length(),cur_pos=KMP();
		int state=len-cur_pos-1;
		if(len%state==0)
			printf("%d\n", state);
		else
			printf("%d\n",len);
			
		check=1;
	}
	return 0;
}
