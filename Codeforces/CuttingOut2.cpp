#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,s[300000],pos,f[300000];
pair<ll,ll> p[300000];deque<ll> pro,ans,ansf;
bool masuk[300000],e,zero;
void cetak(ll a, ll b){
    for(ll i=1;i<=b;i++){
        cout<<a;
        if(i<b){cout<<" ";}
        else{
            if(e){cout<<endl;}
            else{cout<<" ";}
        }
    }
}
int main(){
    cin>>n>>k;
    for(ll i=1;i<=n;i++)cin>>s[i];
    sort(s+1,s+1+n);
    for(ll i=1;i<=n;i++){
        f[s[i]]++;
        if(f[s[i]] > 1){
            if(!masuk[s[i]]){
                masuk[s[i]]=true;
                pro.push_back(s[i]);
            }
        }
    }
    while(!pro.empty()){
        pos++;
        p[pos].first=f[pro.front()];
        p[pos].second=pro.front();
        pro.pop_front();
    }
    sort(p+1,p+1+pos);
    for(ll i=pos;i>=1;i--){
        pro.push_back(p[i].second);
    }
    while(k>0){
        if(pro.empty()){
            if(k>0){zero=true;}
            break;
        }
        ll times = f[pro.front()]/2;
        if(times>k){times=k;}
        k-=times;
        ansf.push_back(times);
        ans.push_back(pro.front());
        pro.pop_front();
    }

    if(!zero){
    while(!ans.empty()){
        if(ans.size()==1){e=true;}
        cetak(ans.front(),ansf.front());
        ans.pop_front();ansf.pop_front();
    }
    }
    else{

    }
}

