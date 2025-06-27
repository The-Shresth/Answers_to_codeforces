#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//array input
vector<vector<int>> get_arr(int size){
	int row=0, col=0,input,first;
	vector<vector<int>> mat;
	cin>>first;
	mat.push_back({first});
	for(int i=1;i<size;i++){
		cin>>input;
		if(input==mat.back().back()){
			mat.back().push_back({input});
		}
		else{
			mat.push_back({input});
		}
	}
	//int output = (mat.size()+1)/2;
	return mat;
}

int max_arrs(vector<vector<int>>& mat){
	int num = 0,check=1;
	while(check<mat.size()){
		if(mat[check][0]<=mat[num][0]+1){
			mat.erase(mat.begin()+check);
		}
		else{
			num+=1;check+=1;
		}
	}
	return mat.size();
}


//driver code
int main(){
	int n;
	cin>>n;
	vector<vector<int>> a;
	vector<int> output(n);
	for(int j=0;j<n;j++){
		int k;
		cin>>k;
		a = get_arr(k);
		output[j] = max_arrs(a);
	}
	for(int i=0;i<n;i++){
    	cout<<output[i]<<endl;
	}
	return 0;
}
