#include<bits/stdc++.h>
using namespace std;

int num_1(string s, int index, int count, int num1){
	if (index == s.length()) return count;
	
	if(s[index] == '1') return num_1(s,index+1, count+num1-1, num1);
	else return num_1(s,index+1, count+num1+1, num1);

}

int number(string s){
	int num=0;
	for(char c:s){
		if(c=='1') num++;
	}
	return num;
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<int> output;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		cin.ignore();
		string str;
		cin>>str;
		int num1 = number(str);
		output.push_back(num_1(str,0,0,num1));
	}
	for(int val:output){
		cout<<val<<endl;
	}
	return 0;
}
