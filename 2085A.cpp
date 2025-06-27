#include<bits/stdc++.h>
using namespace std;

bool check(string s, int k){
	if(k==0){
		for(int i=0;i<=int(s.length()/2);i++){
			if(s[i]>s[s.length()-i-1]){
				return false;
			}
			else if(s[i]<s[s.length()-i-1]) return true;
		}
		return false;
	}
	else if(k!=0 && s[0]==s[s.length()-1]){
		for(int i=0;i<s.length()-1;i++){
			if(s[i]!=s[s.length()-1]) return true;
		}
		return false;
	}
	return true;
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<bool> output;
	for(int i=0;i<n;i++){
		int length, k;
		cin>>length>>k;
		cin.ignore();
		string s;
		cin>>s;
		output.push_back(check(s,k));
	}
	
	for(bool b:output){
		if(b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
