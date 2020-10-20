#include<bits/stdc++.h>
using namespace std;
long long b[100001];
int main(){
    long long n;
    cin>>n;

    for(long long i=1;i<=n;i++)cin>>b[i];

    b[n+1]=0;

    for(long long i=1;i<=n;i++){
        cout<<b[i]+b[i+1];
        if(i<n){cout<<" ";}
    }

}
