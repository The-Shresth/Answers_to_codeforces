#include<bits/stdc++.h>
using namespace std;

//getting array
vector<int> get_arr(int size){
	vector<int> arr;
	for(int i=0;i<size;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	return arr;
}

//updating the array after unit transfer
vector<int> update_arr(vector<int>& arr, int index){
	for(int i=0;i<arr.size();i++){
		if(i==index) arr[i]++;
		else arr[i]--;
	}
	return arr;
}

//checking giver indices
bool giver_check(vector<int>& arr, int index){ //index of value that recieves 
	for(int i=0;i<arr.size();i++){
		if(i!=index){
			if(arr[i]<=0) return false;
		}
	}
	return true;
}



//checking if possible
bool check(vector<int>& a, vector<int>& b){
	vector<int> diff;
	for(int i=0;i<a.size();i++){ //pushing back the diff to know how much extra or deficit 
		diff.push_back(a[i]-b[i]); 
	}
	
	for(int i=0;i<a.size();i++){ //main check loop
		while(diff[i]<0){
			if(giver_check(diff,i)){
				update_arr(diff,i);
			}
			else return false;
		}
	}
	return true;
}

//driver code
int main(){
	int n; //number of testcases
	cin>>n;
	vector<bool> output; //storing bool for output
	for(int i=0;i<n;i++){
		int size; //size of array
		cin>>size;
		vector<int> a = get_arr(size);
		vector<int> b = get_arr(size);
		output.push_back(check(a,b));
	}
	
	for(bool b:output){
		if(b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

