#include<iostream>
#include<vector>
using namespace std;

//getting input
vector<int> get_arr(int size){
	vector<int> arr(size);
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	return arr;
}

//getting max for one iteration
int output(int size, vector<int>& arr,int num_val){
	int c,max_sum=0;
	//main loop to iterate through the array
	for(int i=0; i<size; i++){
		int sum =0;
		//putting element i at the end
		for(int j=i; j<size-1;j++){
			c = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = c;
		}
		//adding last num_val elements and finding the max
		for(int k=1;k<=num_val;k++){
			sum = sum+arr[size-k];
			//cout<<"sum is: "<<sum<<endl;
		}
		//checking for max
		if(sum>max_sum){
			max_sum=sum;
		}
		//returning it to original place
		for(int j=size-1; j>=i;j--){
			c = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = c;
		}
	}
	
	return max_sum;
}

//driver code
int main(){
	int n,k;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cin>>k;
		cin.ignore();
		vector<int> a;
		a = get_arr(k);
		for(int j=1;j<=k;j++){
			int out = output(k,a,j);
			cout<<out<<" ";
		}
		cout<<endl;
	}
	return 0;
}
