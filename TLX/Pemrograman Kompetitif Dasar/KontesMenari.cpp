#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str subsoal;
ll n,r,y,j,h[2000],d[20],deep[20],score[5000000],s;
ll satisfy[200000];
str t[20];
bool used[20];
ll scoring(){
    ll ans = d[deep[1]];
    bool yakin=false;//cout<<deep[1];
    for(ll i=2;i<=r;i++){
        //cout<<deep[i];
        if(t[deep[i-1]]=="Y"){yakin=true;ans+=d[deep[i]];}
        else if(t[deep[i-1]]=="P"){ans+=2*d[deep[i]];}
        else if(t[deep[i-1]]=="L"){ans+=d[deep[i]]/2;}
        else{ans+=d[deep[i]];}
        if(yakin){ans+=y;}
    }
    //cout<<" = "<<ans<<endl;
    return ans;
}
void p(ll x){
    if(x<=r){
        for(ll i=1;i<=n;i++){
            if(!used[i]){
                deep[x]=i;
                used[i]=true;
                if(x==r){
                    s++;
                    score[s]=scoring();
                }
                else{
                    p(x+1);
                }
                used[i]=false;
            }
        }
    }
}
int main(){
    getline(cin,subsoal);
    cin>>n>>r>>y>>j;
    for(ll i=1;i<=n;i++){
        cin>>d[i]>>t[i];
    }
    for(ll i=1;i<=j;i++){
        cin>>h[i];
    }
    p(1);
    sort(score+1,score+s+1);
//    cout<<endl;
//    for(ll i=1;i<=s;i++){
//        cout<<score[i]<<endl;
//    }cout<<endl;
    ll cnt=1;bool mentok=false;

    for(ll i=1;i<=100000;i++){
        satisfy[i]=satisfy[i-1];
        if(!mentok){
        while(i>=score[cnt]){
            cnt++;satisfy[i]++;
            if(cnt>s){cnt--;mentok=true;break;}
        }
        }
    }
    for(ll i=1;i<=j;i++){

        cout<<s-satisfy[h[i]]<<endl;
    }

}
