#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,x;
int main(){
    cin>>n>>k;
    ll ans=n;
    while(k>0){
        if(ans%10==0){
            ans/=10;k--;
        }
        else{
            x=(ans%10);
            if(k<x){
                ans-=k;
            }
            else{
                ans-=x;
            }
            k-=x;

        }
    }
    cout<<ans<<endl;
}



