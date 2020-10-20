#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll a,b,m,n,d[20000],fa,fb,ans[100],num;
str s;
bool valid(){
    ll c=0;
    num = 0;
    for(ll i=0;i<s.size()-1;i++){
        if(s[i]=='a'){c+=a;}
        else{c+=b;}
        if(d[c+1]!=d[c]){num++;ans[num]=d[c]+1;}
        else{return false;}
    }
    return true;
}
int main(){
    cin>>m;
    for(ll i=1;i<=m;i++){cin>>d[i];}
    cin>>n;
    a = m/n;
    b = a+1;
    fb = m%n;
    fa = n-fb;
    //cout<<fa<<fb<<endl;
    for(ll i=1;i<=fa;i++){s+="a";}
    for(ll i=1;i<=fb;i++){s+="b";}
    sort(d+1,d+1+m);
    if(!valid()){
        while(next_permutation(s.begin(),s.end())){
            if(valid()){break;}
        }
    }
//    cout<<a<<" "<<b<<endl;
//    cout<<fa<<" "<<fb<<endl;
//    cout<<s<<endl;
    for(ll i=1;i<=num;i++){
        cout<<ans[i];
        if(i<num){cout<<" ";}
        else{cout<<endl;}
    }

}
