#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll k,n[200001],se[200001],zone[200001];
pair <ll,ll>a[200001];
int main(){
    cin>>k;
    ll e=0;
    se[0]=0;
    for(ll i=1;i<=k;i++){
        cin>>n[i];
        se[i]=se[i-1]+n[i];
        ll sum=0;
        for(ll j=se[i-1]+1;j<=se[i];j++){
            e++;
            zone[e]=i;
            cin>>a[j].first;
            a[j].second=e;
            sum+=a[j].first;
        }
        for(ll j=se[i-1]+1;j<=se[i];j++){
            a[j].first=sum-a[j].first;
        }
        sort(a+se[i-1]+1,a+se[i]+1);
    }

//    for(ll i=1;i<=e;i++){
//        cout<<a[i].first<<" "<<a[i].second<<endl;
//    }cout<<endl;
    sort(a+1,a+1+e);
//    for(ll i=1;i<=e;i++){
//        cout<<a[i].first<<" "<<a[i].second<<" "<<zone[a[i].second]<<endl;
//    }

    bool can=false;
    for(ll i=1;i<e;i++){
        if(a[i].first==a[i+1].first){
            if(zone[a[i].second]!=zone[a[i+1].second]){
                can=true;
                cout<<"YES"<<endl;
                cout<<zone[a[i].second]<<" "<<a[i].second-se[zone[a[i].second]-1]<<endl;
                cout<<zone[a[i+1].second]<<" "<<a[i+1].second-se[zone[a[i+1].second]-1]<<endl;
                break;
            }

        }
    }
    if(!can){cout<<"NO"<<endl;}
}
