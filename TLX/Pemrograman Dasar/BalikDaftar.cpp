#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a[1000];
int main(){
    ll temp;
    while(cin>>temp){
        n++;
        a[n]=temp;
    }
    for(ll i=n;i>=1;i--){
        cout<<a[i]<<endl;
    }

}
