#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,n,d[400],d2[400];
bool valid;
int main(){
    cin>>t;
    for(int cases=1;cases<=t;cases++){
        ll mn,mx,x;
        mx = -1;
        mn = 10000000;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            mn = min(mn,d[i]);
            mx = max(mx,d[i]);
        }
        x = (ll) mn* (ll) mx;

        for(int i=1;i<=n;i++){
            d2[i]=0;
        }
        ll idx = 0;
        for(ll i=2;i<=sqrt(x);i++){
            if(x%i==0){
                idx++;
                if(x/i == i){d2[idx]=i;}
                else{d2[idx]=i;idx++;d2[idx]=x/i;}
            }
        }

        if(idx != n){
            cout<<-1<<endl;
        }
        else{
            sort(d+1,d+1+n);
            sort(d2+1,d2+1+n);

            valid = true;
            for(int i=1;i<=n;i++){
                if(d[i]!=d2[i]){valid=false;break;}
            }
            if(valid)cout<<x<<endl;
            else cout<<-1<<endl;
        }

    }

}
