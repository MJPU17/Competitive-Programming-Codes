#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
	int arr[9];
	while(cin>>arr[0]){
		int t=arr[0],r=0;
		for(int i=1;i<9;i++){
			cin>>arr[i];
			t+=arr[i];
		}
		map<string,int> comb;
		comb["BGC"]=t-arr[0]-arr[4]-arr[8];
		comb["CGB"]=t-arr[2]-arr[4]-arr[6];
		comb["GCB"]=t-arr[1]-arr[5]-arr[6];
		comb["BCG"]=t-arr[0]-arr[5]-arr[7];
		comb["CBG"]=t-arr[2]-arr[3]-arr[7];
		comb["GBC"]=t-arr[1]-arr[3]-arr[8];
		string c="";
		for(pair<string,int> p:comb){
			if(t>p.second){
				t=p.second;
				c=p.first;
				r=0;
			}
			else if(t==p.second)r++;
		}
		if(r<=1)cout<<c+" "<<t<<"\n";
		else cout<<"BCG "<<t<<"\n";
	}
	return 0;
}
