#include <bits/stdc++.h>
using namespace std;

// Input array
vector<int> get_array(int size) {
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Partition for quick sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j <= high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Quick sort
void quick_sort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

// Find index of a value
int find_index(vector<int>& arr, int val) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == val) return i;
    }
    return -1;
}

// Check if possible for arr[0] or -arr[0] to be median
bool check_arr(vector<int> arr, int val) {
    int n = arr.size();
    quick_sort(arr, 0, n-1);
    int median_idx = n/2;
    return arr[median_idx] == val;
}

int main() {
    int n;
    cin >> n;
    vector<string> output;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr = get_array(k);
        // Try with arr[0]
        if(check_arr(arr, arr[0])) output.push_back("YES");
        // Try with -arr[0] if not already YES
        else {
            arr[0] = -arr[0];
            if(check_arr(arr, arr[0])) output.push_back("YES");
            else output.push_back("NO");
        }
    }
    for(const string& s : output) {
        cout << s << endl;
    }
    return 0;
}

