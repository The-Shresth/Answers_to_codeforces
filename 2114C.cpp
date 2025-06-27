#include<iostream>
#include<vector>
using namespace std;

//array input
int get_arr(int size){
	int row=0, col=0,input;
	vector<vector<int>> mat(row, vector<int>(col,0));
	cin>>mat[row][col];
	for(int i=1;i<size;i++){
		cin>>input;
		if(input==mat[row][col]){
			col+=1;
			mat[row][col] = input;
		}
		else{
			row+=1; col=0;
			mat[row][col] = input;
		}
	}
	int output = (row+1)/2;
	return output;
}

//removing element and shifitng array
//void remove_shift(vector<int>& arr, int index){
//	for(int i=index;i<arr.size()-1;i++){
//		arr[i]  =arr[i+1];
//	}
//	arr.pop_back();
//}
//
////getting output
//int max_arrs(vector<int>& arr){
//	int num =0, check=1;
//	while(check<arr.size()){
//		if(arr[check]<=arr[num]+1){
//			remove_shift(arr,check);
//		}
//		else if(check<arr.size()){
//			num+=1;
//			check+=1;
//		}
//	}
//	return arr.size();
//}

//driver code
int main(){
	int n;
	cin>>n;
	vector<int> output(n);
	for(int j=0;j<n;j++){
		int k;
		cin>>k;
		output[j] = get_arr(k);
		//output[j] = max_arrs(a);
	}
	for(int i=0;i<n;i++){
    	cout<<output[i]<<endl;
	}
	return 0;
}
