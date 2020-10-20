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
typedef set <int> si;
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
int dua[30],n,sum[30],current,far;
vector < pair < pii , int> > ans;
vi v;
int node = 1;
int main(){
    dua[0]=1;sum[1]=0;
    for(int i=1;i<=26;i++)dua[i]=2*dua[i-1];
    for(int i=2;i<=26;i++)sum[i]=sum[i-1]+dua[i-2];

    cin>>n;
    n--;

    for(int i=0;i<=22;i++){
        if(current+dua[i]>n){break;}
        else{
            current+=dua[i];
            v.pb(dua[i]);
        }
    }

    for(int i=0;i<v.size();i++){
        ans.pb( mp ( mp(node,node+1) , 0 ) );
        ans.pb( mp ( mp(node,node+1) , v[i] ) );
        node++;
    }

    while(current < n){
        int pl = current+1;
        int idx;
        for(int i=1;i<=26;i++){
            if(pl+sum[i]>n){break;}
            else{
                idx=i;
            }
        }
        ans.pb( mp ( mp(idx,node) , pl ) );
        current = pl + sum[idx];
    }

    cout<<node<<" "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%d %d %d\n",ans[i].ff,ans[i].fs,ans[i].se);
    }

}
