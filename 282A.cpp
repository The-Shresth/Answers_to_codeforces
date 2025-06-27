#include<iostream>
#include<string>
using namespace std;

string get_input(){
	string input;
	getline(cin, input);
	return input;
}

int change(string s){
	int k =0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='+'){
			k=1;
			break;
		}
		else if(s[i]=='-'){
			k=-1;
			break;
		};
	}
	return k;
}

int main(){
	int n;
	cin>>n;
	cin.ignore();
	int sum = 0;
	for(int i=0; i<n; i++){
		string check = get_input();
		int add = change(check);
		sum = sum + add;
	};
	cout<<sum;
	return 0;
	}
