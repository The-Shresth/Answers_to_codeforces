#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> stack(n);
    unordered_map<int, int> pos;  // Stores position of each book
    for(int i = 0; i < n; i++) {
        cin >> stack[i];
        pos[stack[i]] = i;
    }
    
    vector<int> bag(n);
    for(int i = 0; i < n; i++) {
        cin >> bag[i];
    }
    
    int current_top = 0;
    vector<int> result;
    
    for(int b : bag) {
        if(pos[b] < current_top) {
            // Book already taken
            result.push_back(0);
        } else {
            // Calculate how many books we're taking
            int taken = pos[b] - current_top + 1;
            result.push_back(taken);
            current_top = pos[b] + 1;
        }
    }
    
    for(int val : result) {
        cout << val << " ";
    }
    
    return 0;
}

