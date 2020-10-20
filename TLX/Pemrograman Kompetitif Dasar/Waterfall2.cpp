#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll v,h,n,v1,h1,v2,h2,l[500000],r[500000],mx;
pair <ll,ll> stone[500000];
ll memo[502][502];
bool calc[502][502];
bool inrange(ll left,ll right, ll target){
    if((target>=left)&&(target<=right))return true;
    else return false;
}
ll drop(ll y,ll x){
    if(calc[y][x]){
        return memo[y][x];
    }
    else{
        ll ans=0;
        for(ll i=1;i<=n;i++){
            if(y<stone[i].first){
                if(inrange(l[stone[i].second],r[stone[i].second],x)){
                    ans = 1 + drop(stone[i].first - 1, l[stone[i].second]-1) + drop(stone[i].first - 1, r[stone[i].second]+1);
                    break;
                }
            }
        }
        calc[y][x]=true;
        memo[y][x]=ans;
        return ans;
    }
}
int main(){
    cin>>v>>h>>n;
    for(ll i=1;i<=n;i++){
        cin>>v1>>h1>>v2>>h2;
        stone[i].first=v1;
        stone[i].second=i;
        l[i]=h1;
        r[i]=h2;
    }
    sort(stone+1,stone+1+n);
//    for(ll i=1;i<=n;i++){
//        cout<<stone[i].first<<endl;
//        cout<<l[stone[i].second]<<" "<<r[stone[i].second]<<endl<<endl;
//    }
//    cout<<drop(0,3)<<endl;
    mx=-1;
    for(ll i=1;i<=h;i++){
        mx = max(mx, drop(0,i));
    }
    cout<<mx<<endl;
}
