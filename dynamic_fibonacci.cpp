// using tabular method ( Dynamic programming )

#include<iostream>
using namespace std;
void print(int f[], int n){
    cout<<"The fibonacci series is: ";
    for(int i=0; i<=n; i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;
}
int fib(int n){
    int F[n];
    if(n<=1)
        return n;
    F[0]=0,F[1]=1;
    for(int i=2; i<=n; i++){
        F[i]=F[i-2]+F[i-1];
    }
    print(F,n);
    return F[n];
}
int main(){
    int n;
    cout<<"Enter number: "<<endl;
    cin>>n;
    int f=fib(n);
    cout<<"The fib of "<<n<<" is: "<<f<<endl;
    return 0;
}
