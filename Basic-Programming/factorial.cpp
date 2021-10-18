#include<iostream>
using namespace std;

int fact(int n){
    if(n<1) return -1;
    if(n==0) return 1;

    int temp = fact(n-1);
    return n*temp;

}

// method 2 factorial 
int fact2(int n)
{
    int f = 1 ;
    for (int i=0;i<n;i++)
    {
        f = f*i ;
    }
    return f ; 
}

int main(){
    int n;
    cin>>n;
    int ans = fact(n);
    cout<<ans<<endl;
    return 0;
}
