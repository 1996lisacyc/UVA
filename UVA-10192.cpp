#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	string s1,s2;
	int Case=1,LCS[105][105];
	
	while(getline(cin,s1)){
		if(s1=="#") break;
		else {
			getline(cin,s2);
			memset(LCS,0,sizeof(LCS));

			for (int i=1; i<=s1.length(); i++){
        		for (int j=1; j<=s2.length(); j++){

            		if (s1[i-1] == s2[j-1]){
            			LCS[i][j]=LCS[i-1][j-1]+1;
            		}
            		else{
            			LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            		}
            	}	
           	}
           	printf("Case #%d: you can visit at most %d cities.\n",Case++,LCS[s1.length()][s2.length()]);	
		}
	}
	return 0;
}
