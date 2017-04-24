#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(){
	
	int n,check=0;
	scanf("%d",&n);
	while(n--){
		
		scanf("\n\n");
		int counter=0;
		string s;
		map<string,int> Map;
		
		if(check) printf("\n");
		
		while(getline(cin,s)&&s!=""){
			counter++;
			if(Map[s]<1) Map[s]=1;
			else Map[s]++;
		}
		
		for(map<string,int>::iterator i=Map.begin(); i!=Map.end(); i++){
			cout<<i->first;
			printf(" %.4f\n",(double)i->second/counter*100);
		}
		
		check=1;
	}
	return 0;
}
