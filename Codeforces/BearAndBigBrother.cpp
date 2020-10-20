#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll eat;
int main(){
    ll a,b;
    cin>>a>>b;
    while(a<=b){
        eat++;
        a*=3;b*=2;
    }
    cout<<eat<<endl;
}
