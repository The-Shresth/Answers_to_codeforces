#include<bits/stdc++.h>
using namespace std;

vector<int> get_array(int size){
	vector<int> arr;
	for(int i=0;i<size;i++){
		int input;
		cin>>input;
		arr.push_back(input);
	};
	return arr;
}

bool time_check(vector<int>& arr){
	for(int i=0;i<int(((arr.size()+1)/2));i++){
		if(arr[i]<=2*(arr.size()-i-1)) return false;
	}
	for(int i=arr.size()-1;i>int(((arr.size()+1)/2))-1;i--){
		if(arr[i]<=2*i) return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	vector<bool> output;
	for(int i=0;i<n;i++){
		int size;
		cin>>size;
		vector<int> arr = get_array(size);
		output.push_back(time_check(arr));
	}
	for(bool out:output){
		if(out) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
	return 0;
}
