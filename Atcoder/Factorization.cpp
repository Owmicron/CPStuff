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
ll n,m;
bool isprime[20000000];
vll prime,v,num;
map <ll,ll> factor;
map <ll,ll> :: iterator itr;
ll md = 1000000007;
void sieve (ll x){
    for(int i=2;i<=x;i++)isprime[i]=true;
    for(int i=2;i<=x;i++){
        if(isprime[i]){
            prime.pb(i);
            for(int j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
void factorize(ll x){
    while(x>1){
        bool cant=true;
        for(int i=0;i<prime.size();i++){
            if(x%prime[i]==0){
                x/=prime[i];
                factor[prime[i]]++;
                cant=false;
                break;
            }
        }
        if(cant){factor[2]=1;break;}
    }
}
bool calc[200000][40];
ll memo[200000][40];
ll dp(ll s, ll d){
    if(d==1)return s;
    else if (s==1) return 1;
    else if (calc[s][d]) return memo[s][d];
    else if(calc[s+1][d]){
        ll temp = memo[s+1][d];
        temp -= dp(s+1,d-1);
        if(temp<0){temp+=md;}
        calc[s][d] = true;
        memo[s][d]= temp;
        return temp;
    }
    else{
        ll sum = 0;
        for(int i=s;i>=1;i--){
            sum = ((sum%md) + (dp(i,d-1) % md))%md;
        }
        calc[s][d]=true;
        memo[s][d]=sum;
        return sum;
    }
}
int main(){
    sieve(10000000);
    cin>>n>>m;
    if(n==1 || m==1)cout<<1<<endl;
    else{
        factorize(m);
        for(itr=factor.begin();itr!=factor.end();itr++){
            v.pb(dp(n,itr->se));
            //cout<<itr->fi<<" "<<itr->se<<endl;
        }
        ll ans = 1;
        for(int i=0;i<v.size();i++){
            ans = ((ans%md) * (v[i]%md))%md;
        }
        cout<<ans<<endl;

    }

}
