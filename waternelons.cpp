#include <iostream>
using namespace std;
int main(){
    int w;
    // cout<<"Enter the weight"<<endl;
    cin>>w;
    if(w%2==0 && w!=2 && w!= 0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO";
    }
    return 0;
}