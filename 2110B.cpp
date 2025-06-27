#include<bits/stdc++.h>
using namespace std;

bool check(string s){
//	for(int i=0;i<s.length()-1;i++){
//		s[i] = s[i+1];
//	}
	//s[s.length()-1] = "\0";
	int bal=0;
	for(int i=1;i<s.length()-1;i++){
		if(bal < 0) return false;
		else if(s[i] == '(')bal+=1;
		else bal-=1;
	}
	if (bal==0)return true;
}

int main(){
	int n;
	cin>>n;
	vector<bool> output(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		output[i] = check(s);
	}
	
	for(int i=0;i<n;i++){
		if(output[i]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
