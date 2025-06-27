#include<bits/stdc++.h>
using namespace std;

//sorting
vector<int> selection_sort(vector<int>& arr){
	for(int i=0;i<arr.size();i++){
		int min_idx = i;
		for(int j=i;j<arr.size();j++){
			if(arr[j]<arr[i]){
				min_idx = j;
			}
		}
		swap(arr[i],arr[min_idx]);
	}
	return arr;
}

//deleting first and last element
//vector<int> new_arr(vector<int>& arr){
//	arr.erase(arr.begin());
//	arr.erase(arr.end());
//	return arr;
//}

//parity check
bool parity_check(int num){
	if(num%2==0) return true;
	else return false;
}

//making the array fashiionable
int number_of_moves(vector<int>& arr, int count) { 
    if ((arr[0] + arr[arr.size()-1]) % 2 == 0) // Fixed modulus check
        return count + 0;
    int i = 1, j=arr.size()-2;
    bool front = parity_check(arr[0]), back = parity_check(arr[arr.size()-1]);
    while(front = parity_check(arr[0]))  {
    	front  = parity_check(arr[i]);
    	i++;
	}
	while(back = parity_check(arr[arr.size()-1]))  {
    	back  = parity_check(arr[j]);
    	j--;
	}
	return min(i-1,j+1);
}



//driver code
int main(){
	int n;
	cin>>n;
	vector<int> output;
	for(int i=0;i<n;i++){
		int k,count=0;
		cin>>k;
		vector<int> arr;
		for(int j=0;j<k;j++){
			cin>>arr[j];
		}
		vector<int> out = selection_sort(arr);
		output.push_back(number_of_moves(out,count));
	}
	for(int val:output){
		cout<<val<<endl;
	}
	return 0;
}
