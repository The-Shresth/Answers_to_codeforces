#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool output(string s, int k){
	int num0 = 0, num1 =0;
	for(int i=0;i<s.length();i++){
		if(s[i] == '0'){
			num0++;
		}
		else{
			num1++;
		}
	}
	
	int max_pairs = (num0/2) + (num1/2);
	int odd_int = (num0%2)+(num1%2);
	
	if(k>max_pairs) return false;
	else if(k = max_pairs) return true;
	else{
		if(k%2==0){
			return false;
		}
		else{
			return true;
		}
	}
}

//driver code
int main(){
	int n, length, k;
	string str;
	cin>>n;
	cin.ignore();
	vector<bool> out(n);
	for(int i=0;i<n;i++){
		cin>>length;
		cin>>k;
		cin>>str;
		out[i] = output(str,k);
	}
	for(int i=0;i<n;i++){
		if(out[i]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
