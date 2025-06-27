#include<bits/stdc++.h>
using namespace std;

//getting array
vector<int> get_array(int size){
	vector<int> arr;
	for(int i=0;i<size;i++){
		int in;
		cin>>in;
		arr.push_back(in);
	}
	return arr;
}

//quick sort
//creating partition
int partition(vector<int>& arr, int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low;j<=high-1;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}

//recursive function for quick sort
vector<int> quick_sort(vector<int>& arr, int low, int high){
	if(low<high){
		int pi = partition(arr, low, high);
		quick_sort(arr,low, pi-1);
		quick_sort(arr,pi+1,high);
	}
	return arr;
}

//finding index of a num
int find_index(vector<int>& arr, int val){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==val) return i;
	}
}

//checking if possible
bool check_arr(vector<int>& arr, int val){ //val=arr[0] of unsorted array
	if(arr[int(arr.size()/2)]==val) return true;
	int val_idx = find_index(arr,val), shift_req; //getting index of val in sorted array
	
	if(val_idx<int(arr.size()/2)) {
		shift_req = int(arr.size()/2)-val_idx;
		int count =0;
		if(arr[val_idx]>0){
			for(int i=val_idx+1;i<arr.size();i++){
				if(arr[i]>0) count++;
				if(count == shift_req) return true;
			}
		}
		else if(arr[val_idx]<0){
			for(int i=val_idx+1;i<arr.size();i++){
				if(arr[i]>0&&arr[i]>abs(arr[val_idx])) count++;
				if(count == shift_req) return true;
			}
		}
	}
	
	else if(val_idx>int(arr.size()/2)) {
		shift_req = (int(arr.size()/2)-val_idx)*-1;
		int count =0;
		if(arr[val_idx]>0){
			for(int i=val_idx-1;i<arr.size();i--){
				if(arr[i]<0&&abs(arr[i])>arr[val_idx]) count++;
				if(count == shift_req) return true;
			}
		}
		else if(arr[val_idx]<0){
			for(int i=val_idx+1;i<arr.size();i++){
				if(arr[i]<0) count++;
				if(count == shift_req) return true;
			}
		}
	}
	
	return false;
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<bool> output;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<int> arr = get_array(k);
		vector<int> sorted_arr = quick_sort(arr,0,k-1);
		output.push_back(check_arr(sorted_arr,arr[0]));
		if(output.back()==false) output.back() = check_arr(sorted_arr,-arr[0]);
	}
	for(bool check : output){
		if(check==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
