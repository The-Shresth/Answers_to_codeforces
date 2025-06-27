#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<string> output(n);
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		double root = sqrt(num);
		if(root == (int)root){
			stringstream ssr;
			ssr<<root;
			string str = ssr.str();
			output[i] = "0 "+str;
		}
		else{
			output[i] = "-1";
		}
	}
	for(int i=0;i<n;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}
