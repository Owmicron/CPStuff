#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,b[2000];
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    cout<<b[k]<<endl;
}
