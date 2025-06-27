#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    string str;

    for(int i=0; i<n; i++){
        cin>>words[i];
    };

    for(int i=0; i<n; i++){
        str = words[i];
        size_t len = str.length();
        if (len>10){
            cout<<str[0]<<len-2<<str[len-1]<<endl;
        }
        else{
            cout<<str<<endl;
        };
    };
    return 0;
}
