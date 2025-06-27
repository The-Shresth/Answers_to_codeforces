#include<iostream>
#include<vector>
using namespace std;

vector<int> getArray(int n){
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	return arr;
}

bool check(const vector<int>& a, const vector<int>& b, int size){
	vector<int> store;
	int len_store=0;
	for(int i=0; i<size; i++){
		if(b[i]!= -1){
			store.push_back(a[i]+b[i]);
			len_store++;
		}
	}
	for(int i=0; i<len_store-1; i++){
		if(store[i]!=store[i+1]){
			return false;
		}
	}
	return true;
}

int output(bool check, int k, const vector<int>& a,const vector<int>& b, int size){
	if(check){
		int min = a[0], max = a[0];
		for(int i=0; i<size; i++){
			if(b[i]!=-1){
				return 1;
			}
		}
		
		for(int i=0;i<size;i++){
			if(min>a[i]){
				min = a[i];
			}
			if(a[i]>max){
				max = a[i];
			}
		}
		//cout<<"min is: "<<min<<endl;
		//cout<<"max is: "<< max<<endl;
		int sum = min+k-max+1;
		return sum;
	}
	else{
		return 0;
	}
}

int main(){
	int n;
	cin>>n;
	cin.ignore();
	vector<int> out(n);
	//cout<<"value of n is: "<<n<<endl;
	
	for(int i=0; i<n; i++){
		int len,k;
		cin>>len;
		cin>>k;
		cin.ignore();
		//cout<<"value of len is: "<<len<<endl;
		//cout<<"value of k is: "<<k<<endl;
		vector<int> arr1(len); arr1 = getArray(len);
		vector<int> arr2(len); arr2 = getArray(len);
		bool b = check(arr1,arr2,len);
		out[i] =  output(b, k, arr1, arr2, len);
	}
	
	for(int i=0;i<n;i++){
		cout<<out[i]<<endl;
	}
	return 0;
}
