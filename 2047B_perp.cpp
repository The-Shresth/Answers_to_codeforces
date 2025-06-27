#include <bits/stdc++.h>
using namespace std;

string least_permu(string s) {
    int n = s.size();
    vector<int> freq(256, 0);
    for (char c : s) freq[c]++;

    // Find max and min frequency characters
    int max_freq = 0, min_freq = n + 1;
    char max_char = s[0], min_char = s[0];
    for (char c : s) {
        if (freq[c] > max_freq) {
            max_freq = freq[c];
            max_char = c;
        }
        if (freq[c] < min_freq) {
            min_freq = freq[c];
            min_char = c;
        }
    }

    // Find first index of max_char and min_char
    int max_idx = -1, min_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == max_char && max_idx == -1) max_idx = i;
    }
    // min_idx should be index of a char different from what max_idx was pointing at
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[max_idx]) {
            min_idx = i;
            break;
        }
    }

    // If all chars are same, or only one char, return as is
    if (min_idx == -1) return s;

    s[min_idx] = s[max_idx];
    return s;
}

int main() {
    int t;
    cin >> t;
    vector<string> results;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        results.push_back(least_permu(s));
    }
    for (const string& res : results) {
        cout << res << endl;
    }
    return 0;
}

