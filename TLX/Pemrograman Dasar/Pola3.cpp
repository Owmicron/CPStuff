#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll num;
void write(){
    cout<<num;
    num++;
    if(num>9){num=0;}
}
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            write();

        }
        cout<<endl;
    }
}
