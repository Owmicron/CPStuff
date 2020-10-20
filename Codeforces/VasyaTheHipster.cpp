#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c,d;
int main(){
    cin>>a>>b;
    c=min(a,b);
    d=(max(a,b)-c)/2;
    cout<<c<<" "<<d<<endl;
}
