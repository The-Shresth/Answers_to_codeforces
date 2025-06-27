#include <bits/stdc++.h>
using namespace std;

float cost_calc(int num) {
    int sum_dig = 0;
    int original = num;
    while(num) {
        sum_dig += num % 10;
        num /= 10;
    }
    return static_cast<float>(original) / sum_dig;
}

vector<int> num_arr(int num) {
    vector<int> digits;
    if(num == 0) digits.push_back(0); // Handle zero case
    while(num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int new_num(vector<int>& digits) {
    if(digits.empty()) return 0;
    
    auto min_it = min_element(digits.begin(), digits.end());
    digits.erase(min_it);
    
    int num = 0;
    for(int d : digits) {
        num = num * 10 + d;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    vector<int> output;
    
    for(int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        float max_cost = 0.0f;
        int optimal_number = num;
        int current = num;
        
        while(current > 0) {
            float current_cost = cost_calc(current);
            if(current_cost > max_cost) {
                max_cost = current_cost;
                optimal_number = current;
            }
            vector<int> arr_new = num_arr(current); // FIXED LINE
            current = new_num(arr_new);
        }
        
        int removed_digits = num_arr(num).size() - num_arr(optimal_number).size();
        output.push_back(removed_digits);
    }
    
    for(int val : output) {
        cout << val << endl;
    }
    return 0;
}


