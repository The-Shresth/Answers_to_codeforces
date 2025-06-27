#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int repeated_num(int x, int k) {
    int dig_count = 0;
    int dig_check = x;
    while(dig_check != 0) {
        dig_count++;
        dig_check /= 10;
    }
    
    int exp = 1;
    for(int i = 0; i < dig_count; i++) {
        exp *= 10;
    }
    
    int num = 0;
    for(int i = 0; i < k; i++) {
        num = num * exp + x;
    }
    return num;
}

bool prime_check(int num) {
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    
    int limit = sqrt(num);
    for(int i = 3; i <= limit; i += 2) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> output(n);
    
    for(int i = 0; i < n; i++) {
        int x, k;
        cin >> x >> k; // Removed all cin.ignore()
        int y = repeated_num(x, k);
        output[i] = prime_check(y) ? "YES" : "NO";
    }
    
    for(const auto& res : output) {
        cout << res << endl;
    }
    return 0;
}

