#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,n,b[1000100],d[110000],ans;
str s;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        t=0;
        for(ll j=0;j<s.size();j++){
            if(s[j]=='('){t++;}
            else{t--;}
        }
        if(t<0){b[abs(t)+500000]++;}
        else{b[t]++;}
        d[i]=t;
    }

    for(ll i=1;i<=n;i++){
        ll in;
        if(d[i]<0){in=500000 + abs(d[i]);}
        else{in=d[i];}
        ll counter;
        if(-d[i]<0){counter=500000 + abs(d[i]);}
        else{counter=-d[i];}

        if(in==0){
            if(b[in]>=2){b[in]-=2;ans++;}
        }
        else if((b[in]>0) && (b[counter]>0)){
            ans++;
            b[in]--;
            b[counter]--;
        }
    }
    cout<<ans<<endl;
}



