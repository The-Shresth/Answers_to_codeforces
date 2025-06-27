#include<bits/stdc++.h>
using namespace std;

//taking matrix input and sorting it row-wise simultaneously
vector<vector<int>> input_sort(int row, int col){
	vector<vector<int>> mat;
	for(int i=0;i<row;i++){
		for(int j=0;j<m;j++){
			int num;
			cin>>num;
			if(mat.empty()) mat.push_back(num);
			elseif(mat.back()>num){
				mat.push_back(mat.back());
				mat.back() = num;
			}
			else{
				mat.push_back(num);
			}
		}
	}
	return mat;
}

vector<vector<int>>
