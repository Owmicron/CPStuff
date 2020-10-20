#include<bits/stdc++.h>
using namespace std;
long long x,n,sum,mx,b;
int main(){
    cin>>n;
    b=0;
    for(long long i=1;i<=n;i++){
        cin>>x;
        if (x>b){sum++;}
        else{sum=1;}
        b=x;

        if (sum>mx){mx=sum;}
    }

    cout<<mx;

}
