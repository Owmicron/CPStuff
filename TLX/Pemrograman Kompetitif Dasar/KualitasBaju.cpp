#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,d[200000];
double median(){
    if(n%2==0){
        return (d[n/2]+d[(n/2)+1])/2.0;
    }
    else{return d[(n/2)+1];}
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>d[i];
    }
    sort(d+1,d+1+n);
    cout<<fixed<<setprecision(1)<<median()*1.0<<endl;

}
