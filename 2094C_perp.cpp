#include <bits/stdc++.h>
using namespace std;

vector<int> get_row(int size) {
    vector<int> row;
    for(int i = 0; i < size; i++) {
        int val;
        cin >> val;
        row.push_back(val);
    }
    return row;
}

vector<int> code(vector<vector<int>>& arr, int size) {
    vector<int> secret_code;
    int sum = 0;
    
    // First row
    for(int i = 0; i < size; i++) {
        secret_code.push_back(arr[0][i]);
        sum += arr[0][i];
    }
    
    // Last column (excluding first row)
    for(int i = 1; i < size; i++) {
        secret_code.push_back(arr[i][size-1]);
        sum += arr[i][size-1];
    }
    
    vector<int> final_code;
    int m = 2 * size;
    final_code.push_back((m * (m + 1)) / 2 - sum);
    for(int num : secret_code) {
        final_code.push_back(num);
    }
    return final_code;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> output;
    
    for(int test = 0; test < n; test++) {
        int size;
        cin >> size;
        vector<vector<int>> input;
        
        // Read matrix
        for(int row = 0; row < size; row++) {
            input.push_back(get_row(size));
        }
        
        // Process and store result
        output.push_back(code(input, size));
    }
    
    // Print results
    for(vector<int>& result : output) {
        for(int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

