#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll harga[20],n,m,digit,f[20],batas,ans,bottom,besar;
void cetak(ll x, ll xx){
    for(ll i=1;i<=xx;i++){
        cout<<x;
    }
}
pair<ll,ll> p[20];
bool unval[20];
ll tukar_tambah(ll angka){
    ll cost = harga[angka] - p[bottom].first;
    if(cost==0){
        return 0;
    }
    ll jumlah_tukar = m/cost;
    m-= jumlah_tukar*cost;
    f[angka]+=jumlah_tukar;
    f[batas-1]-=jumlah_tukar;
}
int main(){
    bottom = 0;
    besar = 2147483647;
    cin>>n;
    for(ll i=0;i<=n;i++){cin>>harga[i];p[i].first=harga[i];p[i].second=i;}
    sort(p,p+n);
    cin>>m;
    for(ll i=0;i<n;i++){
        if(p[i].first==p[i+1].first){unval[p[i].second]=true;}
    }
    sort(p,p+n);
    for(ll i=0;i<=n;i++){cout<<unval[i]<<endl;}
//    for(ll i=0;i<=n;i++){
//        cout<<p[i].first<<" "<<p[i].second<<endl;
//    }

    if(p[bottom].first>m){cout<<0<<endl;}
    else if(n==0){
        if(p[bottom].first>m){cout<<0<<endl;}
        else{cout<<1<<endl<<0<<endl<<0<<endl;}
    }
    else{
        if((p[bottom].second==0)&&(p[bottom+1].first>m)){
            cout<<1<<endl<<0<<endl<<0<<endl;
        }
        else{
            //if(p[0].second==0){digit+=1;m-=p[1].first;f[p[1].second]++;}
            ll tt=0;
            for(ll i=0;i<=9;i++){
                if(unval[i]){tt++;}
                else{break;}
            }
            digit+= m/p[bottom+tt].first;
            //cout<<digit<<endl;
            f[p[bottom+tt].second]+= m/p[bottom+tt].first;
            if(digit * p[bottom+tt].first == m){
                if(p[bottom+tt].second==0){
                    digit=1;m-=p[bottom+tt+1].first;f[p[bottom+tt].second]++;
                    digit+= m/p[bottom+tt].first;
                    f[p[bottom+tt].second]= m/p[bottom+tt].first;
                }
            }
            m-= digit * p[bottom+tt].first;

            batas = p[bottom+tt].second+1;
            if(batas >= n){
                cout<<digit<<endl;
                if(digit>50){
                    cetak(n,50);cout<<endl;cetak(n,50);cout<<endl;
                }
                else{
                    cetak(n,digit);cout<<endl;cetak(n,digit);cout<<endl;
                }
            }
            else{
                cout<<digit<<endl;
                for(ll i=n;i>=batas;i--){
                    if(unval[i]){continue;}
                    tukar_tambah(i);
                    if(m<=0){break;}
                }
                if(digit<=50){
                    for(ll i=n;i>=0;i--){
                        cetak(i,f[i]);
                    }cout<<endl;
                    for(ll i=n;i>=0;i--){
                        cetak(i,f[i]);
                    }cout<<endl;
                }
                else{
                    ll d=50;
                    for(ll i=n;i>=0;i--){
                        d-=f[i];
                        if(d<0){
                            d+=f[i];
                            cetak(i,d);
                        }
                        else{
                            cetak(i,f[i]);
                        }
                    }cout<<endl;

                    ans=0;
                    ll mark=0;
                    ll limit;
                    while(d>0){
                        ans+=f[mark];
                        if(ans>50){ans -= f[mark]; f[mark]=50-ans; limit=mark; break;}
                        mark++;
                    }
                    for(ll i=0;i<=limit;i++){
                        cetak(i,f[i]);
                    }cout<<endl;


                }
            }

        }
    }
}
