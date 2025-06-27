#include<bits/stdc++.h>
using namespace std;

//sorting a row of matrix
vector<int> selection_sort(vector<int>& arr){
	for(int i=0;i<arr.size();i++){
		int min_idx = i;
		for(int j=i+1;j<arr.size();j++){
			if(arr[j]< arr[min_idx]) min_idx = j;
		}
		swap(arr[i],arr[min_idx]);
	}
	return arr;
}

//taking matrix input 
vector<vector<int>> input_sort(int row, int col){
	vector<vector<int>> mat;
	for(int i=0;i<row;i++){
		vector<int> temp;
		for(int j=0;j<col;j++){
			int num;
			cin>>num;
			temp.push_back(num);
		}
		temp = selection_sort(temp);
		mat.push_back(temp);
	}
	return mat;
}

//sorting based on first value of each row
vector<vector<int>> row_sort(vector<vector<int>>& mat, int row){
	vector<vector<int>> new_mat = mat;
	for(int i=0;i<row;i++){
		int min_idx = i;
		for(int j=i+1;j<row;j++){
			if(new_mat[j][0]<new_mat[min_idx][0]) min_idx = j;
		}
		swap(new_mat[i],new_mat[min_idx]);
	}
	return new_mat;
}

bool check(vector<vector<int>>& mat, int row, int col){
	for(int i=0;i<=int(row/2);i++){
		for(int j=0;j<=int((col/2));j++){
			if(mat[i][j]+mat[row-i-1][col-j-1]!= row*col-1) return false;
		}
	}
	return true;
}

//driver code
int main(){
	int n; //number fo testcases
	cin>>n;
	vector<bool> output; //if possible or not
	int row, col; //row and columns
	vector<vector<int>> input, sorted_input;
	vector<int> row_count;
	vector<vector<vector<int>>> all_input, all_sorted;
	for(int i=0;i<n;i++){
		cin>>row>>col;
		row_count.push_back(row);
		input = input_sort(row,col); //getting input
		sorted_input = row_sort(input, row); //sorting row-wise
		all_input.push_back(input);
		all_sorted.push_back(sorted_input);
		output.push_back(check(sorted_input,row,col)); //storing bool val
	}
	
	for(int i=0;i<output.size();i++){
		if(output[i]){
			for(int j=0;j<row_count[i];j++){
				for(int k=0;k<row_count[i];k++){
					if(all_sorted[i][j][0]==all_input[i][k][0]){
						cout<<k+1<<" ";
						break;
					}
				}
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
