#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,harga[20],red[20],f[20],digit,cheapest,cheap2;
void cetak(ll x, ll xx){
    for(ll i=1;i<=xx;i++){cout<<x;}
}
ll tukar_tambah(ll angka,ll target){
    if(f[target]==0){return 0;}
	ll cost = harga[red[angka]] - harga[target];
	if (cost<=0){return 0;}
    ll jumlah_tukar = m/cost;
    if(jumlah_tukar>f[target]){jumlah_tukar=f[target];}
    m -= cost * jumlah_tukar;
    f[red[angka]]+=jumlah_tukar;
    f[target]-=jumlah_tukar;
    return 0;
}
int main(){
    cin>>n;
    for(ll i=0;i<=n;i++){cin>>harga[i];}
    cin>>m;
    cheapest=0;
    for(ll i=1;i<=n;i++){
        if(harga[i]<harga[cheapest]){cheapest=i;}
    }
    for(ll i=0;i<=n;i++){red[i]=i;}
    for(ll i=n;i>=0;i--){
        for(ll j=i-1;j>=0;j--){
            if(red[j]!=j){continue;}
            if(harga[j] == harga[i]){
                if(red[j]==j){red[j]=red[i];}
            }
        }
    }
    cheapest=red[cheapest];
    cheap2=cheapest+1;
    for(ll i=cheapest+1;i<=n;i++){
        if(harga[i]<harga[cheap2]){if(harga[i]!=cheapest){cheap2=i;}}
    }
    cheap2=red[cheap2];
    //cout<<cheap2<<endl;
    if(harga[red[cheapest]] > m){cout<<0<<endl;}
    else if((red[cheapest]== 0)&&(harga[red[cheap2]] > m)){cout<<1<<endl<<0<<endl<<0<<endl;}
    else if(n==0){cout<<1<<endl<<0<<endl<<0<<endl;}
    else{
        if(red[cheapest]==0){
            digit=1;
            f[red[cheap2]]++;
            m-= harga[red[cheap2]];
            digit+=m/harga[red[cheapest]];
            f[red[cheapest]]+=digit-1;
            m-=(digit-1) * harga[red[cheapest]];
            cheapest = red[cheapest];

        }
        else{
            digit = m/harga[red[cheapest]];
            m-= digit * harga[red[cheapest]];
            f[red[cheapest]]=digit;
        }
        cout<<digit<<endl;
        for(ll i=n;i>=cheapest+1;i--){
                for(ll j=cheapest;j<i;j++){
                    tukar_tambah(red[i],j);
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
                if(used>50){used-=f[i];cetak(i,50-used);break;}
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
                else if(used==50){limit=i;break;}
            }
            for(ll i=limit;i>=0;i--){cetak(i,f[i]);}cout<<endl;
        }
    }
}
