#include<bits/stdc++.h>
using namespace std;

//getting row
vector<int> get_row(int size){
	vector<int> arr;
	for(int i=0;i<size;i++){
		int in;
		cin>>in;
		arr.push_back(in);
	}
	return arr;
}

//getting the permutation
vector<int> code(vector<vector<int>>& arr, int size){
	vector<int> secret_code;
	int sum = 0;
	for(int i=0;i<size;i++){
		secret_code.push_back(arr[0][i]);
		sum = sum + arr[0][i];
	}
	for(int i=1;i<=size-1;i++){
		secret_code.push_back(arr[i][size-1]);
		sum = sum + arr[i][size-1];
	}
	vector<int> final_code;
	int m = 2*size;
	final_code.push_back(((m*(m+1))/2)-sum);
	for(int num:secret_code){
		final_code.push_back(num);
	}
	return final_code;
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<vector<int>> output;
	int size;
	for(int i=0;i<n;i++){
		cin>>size;
		vector<vector<int>> input;
		for(int i=0;i<size;i++){
			input.push_back(get_row(size));
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
