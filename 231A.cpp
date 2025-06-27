#include<iostream>
#include<string>
#include<sstream>
#include <bits/stdc++.h>
using namespace std;

string get_input(){
    string input;
    getline(cin, input);
    remove(input.begin(),input.end(), ' ');
    return input;
}

bool check_input(string s){
	bool opinion = true;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 49) {
            count++;
        }
    }
    if(count<2){
    	opinion = false;
	}
    return opinion;
}

int main(){
    int n;
    cin >> n;
    cin.ignore(); // Consume the newline character
    
    int num_ques = 0;
    string check;
    for (int i = 0; i < n; i++){
        check = get_input();
        bool c = check_input(check);
        if(c){
            num_ques++;
        }
        //cout<<"num_ques: "<<num_ques<<endl;
    }
    cout << num_ques;
    return 0;
}

