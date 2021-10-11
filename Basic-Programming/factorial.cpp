#include<iostream>
using namespace std;

int fact(int n){
    if(n<1) return -1;
    if(n==0) return 1;

    int temp = fact(n-1);
    return n*temp;

}

int main(){
    int n;
    cin>>n;
    int ans = fact(n);
    cout<<ans<<endl;
    return 0;
}
