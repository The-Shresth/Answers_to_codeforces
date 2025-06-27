#include <bits/stdc++.h>
using namespace std;

// Fixed array input function
vector<int> get_array(int size) {
    vector<int> arr(size);  // Initialize with correct size
    for(int i = 0; i < size; i++) {
        cin >> arr[i];  // Direct access to valid indices
    }
    return arr;
}

bool special_sort(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != i+1) {
            // Check if we can swap with next element
            if(i+1 < arr.size() && arr[i] == i+2 && arr[i+1] == i+1) {
                swap(arr[i], arr[i+1]);
                return special_sort(arr);
            }
            else return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> output;
    
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr = get_array(k);
        if(special_sort(arr)) output.push_back("YES");
        else output.push_back("NO");
    }
    
    for(const string& s : output) {
        cout << s << endl;
    }
    return 0;
}

