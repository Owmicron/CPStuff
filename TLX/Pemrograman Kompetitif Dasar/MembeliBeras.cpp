#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x;
double w[2000],c[2000];
double ans;
vector<double>v;
int main(){
    cin>>n>>x;
    for(ll i=1;i<=n;i++){cin>>w[i];}
    for(ll i=1;i<=n;i++){cin>>c[i];}
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=w[i];j++){
            double t = c[i]/w[i]*1.0;
            v.push_back(t);
        }
    }
    sort(v.begin(),v.end());
    for(ll i=1;i<=x;i++){
        if(v.empty()){break;}
        else{ans+=v.back();v.pop_back();}
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;
}
