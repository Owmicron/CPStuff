#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,c,m;
int main(){
    cin>>a;
    cin>>b;
    cin>>c;
    m=-1;
    m=max(m,a+b*c);
    m=max(m,a*b+c);
    m=max(m,a*(b+c));
    m=max(m,a*b*c);
    m=max(m,a+b+c);
    m=max(m,(a+b)*c);
    cout<<m;
}

