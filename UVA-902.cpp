#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		
		scanf(" ");
		int counter=0;
		string s,ans;
		getline(cin,s);
		map<string,int> Map;
		
		for(int i=0; i<s.length()-n; i++){
			string tem=s.substr(i,n);
			if(Map[tem]<1) Map[tem]=1;
			else Map[tem]++;
		}
		
		for(map<string,int>::iterator i=Map.begin(); i!=Map.end(); i++){
			if(i->second>counter&&(i->first.length()==n)){
				ans=i->first;
				counter=i->second;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
