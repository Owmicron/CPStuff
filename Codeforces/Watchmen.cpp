#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,x[200000],y[200000],fx[200000],fy[200000];
bool usedx[100000000],usedy[1000000000];
str s[200002];
ll calc(ll x){
    return (x*(x-1)/2);
}
ll cnv(str x){
    int f=1;
    ll sum=0;
    for(int i=x.size()-1;i>=0;i--){
        sum+=f*int(x[i]-48);
        f*=10;
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

    sort(s,s+n+1);

    stack<ll> s1;
////    s1.push(3);
////    cout<<s1.top();
////    s1.pop();]

    for(ll i=1;i<=n;i++){
        fx[x[i]]++;
        if(fx[x[i]]>1){
            if (not usedx[x[i]]){
                usedx[x[i]]=true;
                s1.push(x[i]);
            }
        }
    }

    ll ans1=0;
    while(not s1.empty()){
////        cout<<s1.top()<<" ";
////        cout<<fx[s1.top()];
////        cout<<endl<<calc(fx[s1.top()])<<endl;
        ans1+=calc(fx[s1.top()]);
        s1.pop();

    }
    //cout<<ans1;
    stack <ll> s2;
    for(ll i=1;i<=n;i++){
        fy[y[i]]++;
        if(fy[y[i]]>1){
            if (not usedy[y[i]]){
                usedy[y[i]]=true;
                s2.push(y[i]);
            }
        }
    }

    ll ans2=0;
    while(not s2.empty()){
////        cout<<s1.top()<<" ";
////        cout<<fx[s1.top()];
////        cout<<endl<<calc(fx[s1.top()])<<endl;
        ans2+=calc(fy[s2.top()]);
        s2.pop();
    }
//////    cout<<endl<<ans2<<endl;
//////    for(ll i=1;i<=n;i++){
//////        cout<<s[i]<<endl;
//////    }
//////    cout<<endl;
    ll ans3=0;
    ll c=1;
    for(ll i=1;i<=n+1;i++){
        if (s[i] == s[i-1]){
            c++;
        }
        else{
            //cout<<calc(c)<<endl;
            ans3+=calc(c);
            c=1;
        }

    }
    cout<<ans1+ans2-ans3;
}
