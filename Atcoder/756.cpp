#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
int pangkat[200],ans,n;
bool isprime[200];
vi prime;
vi power;
void sieve (int x){
    for(int i=2;i<=x;i++){
        isprime[i]=true;
    }
    for(int i=2;i<=x;i++){
        if(isprime[i]){
            prime.pb(i);
            for(int j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void factorize(int x){
    while(x>1){
        for(int i=0;i<prime.size();i++){
            if(x%prime[i]==0){
                x/=prime[i];
                pangkat[prime[i]]++;
                break;
            }
        }
    }

}
void calculate (){
    // product3
    for(int i=0;i<power.size();i++){
        if(power[i]>=5){
            for(int j=i+1;j<power.size();j++){
                if(power[j]>=5){
                    for(int k=0;k<power.size();k++){
                        if(k==i || k==j){continue;}
                        else{
                            if(power[k]>=3){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }

    //product2
    for(int i=0;i<power.size();i++){
        for(int j=0;j<power.size();j++){
            if(j==i)continue;
            if(power[i]>=3 && power[j]>=25){ans++;}
            if(power[i]>=5 && power[j]>=15){ans++;}
        }
    }

    //product1
    for(int i=0;i<power.size();i++){
        if(power[i]>=75){ans++;}
    }
}
int main(){
    sieve(150);
    cin>>n;
    for(int i=2;i<=n;i++){
        factorize(i);
    }
    for(int i=1;i<=100;i++){
        if(pangkat[i]>0){
            power.pb(pangkat[i]+1);
        }
    }
    calculate();
    cout<<ans<<endl;
}
