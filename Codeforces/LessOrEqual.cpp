#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,a[3000000],x;
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    x=a[k];
    //if(a[k]==a[k-1]){x=-1;}
    if(a[k]==a[k+1]){x=-1;}
    if(k==0){
        if(a[1]>1){x=1;}
    }
    if(x<1){x=-1;}
    cout<<x;



}
