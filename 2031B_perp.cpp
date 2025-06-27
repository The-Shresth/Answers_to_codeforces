#include <bits/stdc++.h>
using namespace std;

vector<int> get_array(int size) {
    vector<int> arr(size); // Initialize with correct size
    for(int i = 0; i < size; i++) {
        cin >> arr[i]; // Direct access to pre-allocated elements
    }
    return arr;
}

bool special_sort(vector<int>& arr, int num) {
    if(num > arr.size()) return true;
    
    int idx = -1;
    // Find current position of desired number
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == num) {
            idx = i;
            break;
        }
    }
    
    if(idx == -1) return false; // Number not found
    
    // If already in position, check next number
    if(idx == num - 1) return special_sort(arr, num + 1);
    
    // Swap adjacent elements to move to correct position
    for(int i = idx; i >= num; --i) {
        if(abs(arr[i-1] - arr[i]) != 1) return false;
        swap(arr[i-1], arr[i]);
    }
    
    return special_sort(arr, num + 1);
}

int main() {
    int n;
    cin >> n;
    vector<string> output;
    
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr = get_array(k);
        output.push_back(special_sort(arr, 1) ? "YES" : "NO");
    }
    
    for(const string& s : output) {
        cout << s << endl;
    }
    return 0;
}

