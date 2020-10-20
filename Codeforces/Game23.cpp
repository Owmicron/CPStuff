#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m;
int main(){
    cin>>n>>m;
    if(m%n!=0){cout<<-1<<endl;}
    else{
        ll gap = m/n;
        ll ans=0;
        while (gap%2== 0 || gap%3==0){
            if(gap%2==0){gap/=2;ans++;}
            else if(gap%3==0){gap/=3;ans++;}
        }
        if(gap>1){ans=-1;}
        cout<<ans<<endl;
    }
}
