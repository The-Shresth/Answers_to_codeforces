#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int repeated_num(int x, int k) {
    int dig_count = 0, temp = x;
    while (temp) {
        dig_count++;
        temp /= 10;
    }

    int exp = 1;
    for (int i = 0; i < dig_count; i++) {
        exp *= 10;
    }

    int num = x;
    for (int i = 0; i < k; i++) {
        num = num * exp + x;
    }
    return num;
}

bool prime_check(int num) {
    if (num <= 1) return false;
    if (num % 2 == 0 && num > 2) return false;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, y, x, k;
    cin >> n;

    vector<string> output(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> k;
        y = repeated_num(x, k);
        output[i] = prime_check(y) ? "YES" : "NO";
    }

    for (const string& res : output) {
        cout << res << endl;
    }

    return 0;
}
