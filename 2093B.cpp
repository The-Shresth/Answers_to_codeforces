#include<bits/stdc++.h>
using namespace std;

//calulating cost of the number
float cost_calc(int num){
	int numerator = num; //numerator
	int sum_dig = 0; //denominator
	while(num){
		int dig = num%10;
		sum_dig = sum_dig+dig;
		num = num/10;
	}
	return numerator/sum_dig;
}

//creating number array
vector<int> num_arr(int num){
	vector<int> number;
	while(num!=0){
		number.push_back(num%10);
		num = num/10;
	}
	return number;
}


//returning new number
int new_num(vector<int>& arr){
	int min = arr[0];
	int min_idx;
	for(int i=0;i<arr.size();i++){ //finding minimum num and its index
		if(arr[i]<min){
			min = arr[i];
			min_idx = i;
		}
	}
	
	for(int i=min_idx;i<arr.size()-1;i++){ //shifing digits
		arr[i] = arr[i+1];
	}
	int num = 0;
	for(int val:arr){
		num += val;
	}
	return num;
}

//driver code
int main(){
	int n;
	cin>>n;
	vector<int> output;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		vector<int> initial;
		initial = num_arr(num);
		int max = 0;
		vector<int> final;
		while(num>0){
			int check = cost_calc(num);
			if(check>max){
				max = check;
				final = num_arr(max);
			}
			vector<int> check_arr = num_arr(num);
			num = new_num(check_arr);
		}
		int num_remv_digits = initial.size() - final.size();
		output.push_back(num_remv_digits); //outputting number of digits removed to get max cost
	}
	
	for(int out:output){
		cout<<out<<endl;
	}
	return 0;
}



