#include <iostream>
#include <vector>

using namespace std;

// Array input
vector<int> get_arr(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Removing element and shifting array properly
void remove_shift(vector<int>& arr, int index) {
    for (int i = index; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr.pop_back(); // Resize the vector correctly
}

// Getting output
int max_arrs(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] <= arr[i] + 1) {
            remove_shift(arr, i + 1);
            i -= 1; // Adjust index after removal
        }
    }
    return arr.size();
}

// Driver code
int main() {
    int n;
    cin >> n;
    vector<int> output(n);
    for (int j = 0; j < n; j++) {
        int k;
        cin >> k;
        vector<int> a = get_arr(k);  // No need for extra vector declaration
        output[j] = max_arrs(a);
    }
    for(int i=0;i<n;i++){
    	cout<<output[i]<<endl;
	}
    return 0;
}
