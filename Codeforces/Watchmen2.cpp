#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x[200002],y[200002],fx[200002],fy[200002];
str s[200002];
ll ans1,ans2,ans3;
ll calc(ll x){
    return (x*(x-1)/2);
}
ll cnv(str x){
    int f=1;
    ll sum=0;
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]!='-'){sum+=f*int(x[i]-48);
        f*=10;}
        else{sum*=-1;}
    }
    return sum;
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        str a,b;
        cin>>a>>b;
        x[i]=cnv(a);
        y[i]=cnv(b);
        s[i]+=a;s[i]+="_";s[i]+=b;
    }
    sort(s+1,s+n+1);
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);

    ll c=1;

    for(ll i=2;i<=n;i++){
        if (x[i] == x[i-1]){
            c++;
        }
        else{
            //cout<<calc(c)<<endl;
            ans1+=calc(c);
            c=1;
        }

    }
     ans1+=calc(c);

    c=1;
    for(ll i=2;i<=n;i++){
        if (y[i] == y[i-1]){
            c++;
        }
        else{
            //cout<<calc(c)<<endl;
            ans2+=calc(c);
            c=1;
        }

    }
     ans2+=calc(c);
    c=1;
    for(ll i=1;i<=n;i++){
        if (s[i] == s[i-1]){
            c++;
        }
        else{
            //cout<<calc(c)<<endl;
            ans3+=calc(c);
            c=1;
        }

    }
     ans3+=calc(c);
    cout<<ans1+ans2-ans3;
}
