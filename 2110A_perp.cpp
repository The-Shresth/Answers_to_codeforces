#include<bits/stdc++.h>
using namespace std;

//sorting
vector<int> selection_sort(vector<int> arr){  // Pass by value, not reference
	for(int i=0;i<arr.size();i++){
		int min_idx = i;  // Fixed: should be index, not value
		for(int j=i;j<arr.size();j++){
			if(arr[j]<arr[min_idx]){  // Fixed: compare with arr[min_idx]
				min_idx = j;
			}
		}
		swap(arr[i],arr[min_idx]);
	}
	return arr;
}

//parity check
bool parity_check(int num){
	return num % 2 == 0;  // Simplified
}

//making the array fashionable
int number_of_moves(vector<int>& arr, int count) { 
    if(arr.size() < 2) return count;  // Handle small arrays
    
    if ((arr[0] + arr[arr.size()-1]) % 2 == 0) 
        return count;
    
    int i = 1, j = (int)arr.size() - 2;  // Cast to int to avoid type mismatch
    bool front_parity = parity_check(arr[0]);
    bool back_parity = parity_check(arr[arr.size()-1]);
    
    // Find first element with different parity from front
    while(i < (int)arr.size() && parity_check(arr[i]) == front_parity) {
        i++;
    }
    
    // Find first element with different parity from back
    while(j >= 0 && parity_check(arr[j]) == back_parity) {
        j--;
    }
    
    // Check if valid positions found
    if(i >= (int)arr.size() && j < 0) return -1;  // No solution
    if(i >= (int)arr.size()) return (int)arr.size() - 1 - j;
    if(j < 0) return i;
    
    return min(i, (int)arr.size() - 1 - j);  // Fixed: cast to int for type compatibility
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<int> output;
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<int> arr(k);  // Fixed: pre-allocate vector size
		for(int j=0;j<k;j++){
			cin>>arr[j];
		}
		vector<int> sorted_arr = selection_sort(arr);
		output.push_back(number_of_moves(sorted_arr, 0));
	}
	
	for(int val : output){
		cout << val << endl;
	}
	return 0;
}

