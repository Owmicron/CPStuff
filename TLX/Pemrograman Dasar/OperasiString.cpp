#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    a.replace(a.find(b),b.size(),"");
    a.replace(a.find(c)+c.size(),0,d);
    cout<<a<<endl;
}




