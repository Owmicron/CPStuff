#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,f[1000];str s;
int main(){
    cin>>n;
    cin>>s;
    for(ll i=0;i<s.size()-1;i++){
        f[(int(s[i])-65)*26 + (int(s[i+1])-64)]++;
        //cout<<(int(s[i])-65)*26 + (int(s[i+1])-64)<<endl;
    }
    ll mx=-1;
    ll in;
    for(ll i=1;i<=26*26;i++){
        if(f[i]>mx){mx=f[i];in=i;}
    }
    //cout<<in<<endl;
    ll a,b;
    a=in/26;
    if(in%26==0){a--;b=26;}
    else{b=in%26;}
    cout<<char(a+65)<<char(b+64);
}




