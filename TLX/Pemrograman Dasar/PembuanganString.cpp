#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b;
bool found(str a,str b){
    ll x=-1;
    x=a.find(b);
    if(x>a.size()){return false;}
    else{return true;}
}
int main(){
    cin>>a>>b;
    while(found(a,b)){
        a.replace(a.find(b),b.size(),"");

    }
    cout<<a<<endl;
}



