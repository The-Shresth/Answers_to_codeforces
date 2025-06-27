#include<bits/stdc++.h>
using namespace std;

string least_permu(string s){
	string str = s;
	int count =0;
	vector<vector<int>> mat;
	for(int i=0;i<str.length();i++){
		int count =0;
		mat.push_back(int(str[i]));
		for(int j=i+1;j<str.length();j++){
			if(c==str[i]){
				count ++;
				str.erase(j,1);
			}
		}
		mat.back().push_back(count);
	}
	
	int max = mat[0][1], min = mat[0][1];
	for(int i=0;i<mat.size();i++){
		if (mat[i][1]>max) max=mat[i][1];
		if (mat[i][1]<min) min = mat[i][1];
	}
	int max_char, min_char;
	for(int i=0;i<mat.size();i++){
		if (mat[i][1]=max) max_char=mat[i][0];
	}
	
	for(int i=0;i<mat.size();i++){
		if (mat[i][1]=min) min_char=mat[i][0];
	}
	
	
	int max_idx, min_idx;
	for(int i=0;i<s.length();i++){
		if (mat[i][1]=max) {
			max_idx = i;
			break;
		}
		
	}
	for(int i=0;i<s.length();i++){
		if (mat[i][1]=min) {
			min_idx = i;
			break;
		}
	}
	
	s[min_idx] = s[max_idx];
	return s;	
}

int main(){
	int n;
	cin>>n;
	vector<string> str;
	for(int num : n){
		string s;
		cin>>s;
		str[num-1] = least_permu(s);
	}
	for (string s : str){
		cout<<s<<endl;
	}
	return 0;
}
