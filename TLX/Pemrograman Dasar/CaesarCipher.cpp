#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b;
str change(char c, ll k){
    ll x=int(c);
    x+=k;
    if(x>122){x-=26;}
    str t;t=char(x);
    return t;

}
int main(){
    str s;
    cin>>s;
    ll k;cin>>k;
    for(ll i=0;i<s.size();i++){
        cout<<change(s[i],k);
    }
    cout<<endl;
}



