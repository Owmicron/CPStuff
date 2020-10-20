#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll t,n,m,score1[100],score2[100],score3[100],in;
str s[100],id;
bool win;
int main(){
    cin>>t;
    for(ll cases=1;cases<=t;cases++){
        ll n,m;
        cin>>n>>m;cin>>id;
        for(ll i=1;i<=n;i++){
            cin>>s[i]>>score1[i]>>score2[i]>>score3[i];
            if(s[i]==id){in=i;}
        }
        ll x=0;
        win=true;
        for(ll i=1;i<=n;i++){
            if(i==in){continue;}
            else{
                if(score3[i]>score3[in]){x++;}
                else if(score3[i]==score3[in]){
                    if(score2[i]>score2[in]){x++;}
                    else if(score2[i]==score2[in]){
                        if(score1[i]>score1[in]){x++;}
                    }
                }

            }
            if(x>=m){win=false;break;}
        }
        if(win){cout<<"YA"<<endl;}
        else{cout<<"TIDAK"<<endl;}

    }
}
