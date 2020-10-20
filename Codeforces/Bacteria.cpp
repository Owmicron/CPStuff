#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll x,ans;
int main(){
    cin>>x;
    while(x>=1){
        if(x%2==1){ans++;}
        x/=2;
    }
    cout<<ans;
}
