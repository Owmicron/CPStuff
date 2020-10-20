#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,harga[20],red[20],f[20],digit,cheapest,cheapest2;
bool isdifferent;
pair<ll,ll>p[20];
void cetak(ll x, ll xx){
    for(ll i=1;i<=xx;i++){cout<<x;}
}
ll tukar_tambah(ll angka){
	ll cost = harga[red[angka]] - harga[cheapest];
	if (cost<=0){return 0;}
    ll jumlah_tukar = m/cost;
    if(jumlah_tukar>f[cheapest]){jumlah_tukar=f[cheapest];}
    m -= cost * jumlah_tukar;
    f[red[angka]]+=jumlah_tukar;
    f[cheapest]-=jumlah_tukar;

}
ll tukar_tambah2(ll angka){
	ll cost = harga[red[angka]] - harga[cheapest2];
	if (cost<=0){return 0;}
    ll jumlah_tukar = m/cost;
    if(jumlah_tukar>f[cheapest2]){jumlah_tukar=f[cheapest2];}
    m -= cost * jumlah_tukar;
    f[red[angka]]+=jumlah_tukar;
    f[cheapest2]-=jumlah_tukar;
}
int main(){
    //setting up
    cin>>n;
    for(ll i=0;i<=n;i++){cin>>harga[i];p[i].first=harga[i];p[i].second=i;}
    cin>>m;
    sort(p,p+n+1);
    for(ll i=0;i<=n;i++){red[i]=i;}
//    for(ll i=0;i<n;i++){
//        if(p[i].first == p[i+1].first){red[p[i].second] = p[i+1].second;}
//    }
    for(ll i=n;i>=0;i--){
        for(ll j=i-1;j>=0;j--){
            if(red[j]!=j){continue;}
            if(harga[j] == harga[i]){
                if(red[j]==j){red[j]=red[i];}
            }
        }
    }
//    cout<<endl;
//    for(ll i=0;i<=n;i++){
//        cout<<i<<" "<<red[i]<<endl;
//    }
//    cout<<endl;
//    for(ll i=0;i<=n;i++){
//        cout<<p[i].first<<" "<<p[i].second<<" "<<red[p[i].second]<<endl;
//    }
    if(p[red[0]].first > m){cout<<0<<endl;}
    else if((red[p[0].second] == 0)&&(p[red[1]].first > m)){cout<<1<<endl<<0<<endl<<0<<endl;}
    else if(n==0){cout<<1<<endl<<0<<endl<<0<<endl;}
    else{
        if(red[p[0].second]==0){
            digit=1;
            f[red[p[1].second]]++;
            m-= p[1].first;
            digit+=m/p[0].first;
            f[red[p[0].second]]+=digit-1;
            m-=(digit-1) * p[0].first;
            cheapest = red[p[0].second];cheapest2 = red[p[1].second];
            isdifferent=true;
        }
        else{
            digit = m/p[0].first;
            m-= digit * p[0].first;
            f[red[p[0].second]]=digit;
            cheapest = red[p[0].second];
        }
        cout<<digit<<endl;
        for(ll i=n;i>=cheapest+1;i--){
                tukar_tambah(red[i]);
                if(m==0){break;}
        }
        if((m>0)&&(isdifferent)){
            for(ll i=n;i>=cheapest2+1;i--){
                tukar_tambah2(red[i]);
                if(m==0){break;}
            }
        }
        if(digit<=50){
            for(ll i=n;i>=0;i--){cetak(i,f[i]);}cout<<endl;
            for(ll i=n;i>=0;i--){cetak(i,f[i]);}cout<<endl;
        }
        else{
            ll used=0;
            for(ll i=n;i>=0;i--){
                used+=f[i];
                if(used>50){used-=f[i];cetak(i,50-used);}
                else{cetak(i,f[i]);}
            }cout<<endl;
            used=0;
            ll limit;
            for(ll i=0;i<=n;i++){
                used+=f[i];
                if(used>50){
                    used-=f[i];
                    f[i]=50-used;
                    limit=i;
                    break;
                }
            }
            for(ll i=0;i<=limit;i++){cetak(i,f[i]);}cout<<endl;
        }

    }

}
