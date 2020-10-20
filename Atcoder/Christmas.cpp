#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
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
#define stop if(idx==x) return 0
int n;
ll x,idx;
ll layer[60],p[60],ans;

int eat (int z){
    idx++;
    stop;
    if(idx + layer[z-1] > x){
        x = x - idx;
        idx = 0;
        eat(z-1);
        return 0;
    }
    else{
        idx += layer[z-1];
        ans += p[z-1];
    }
    stop;

    idx++;
    ans++;
    stop;

    if(idx + layer[z-1] > x){
        x = x - idx;
        idx = 0;
        eat(z-1);
        return 0;
    }
    else{
        idx += layer[z-1];
        ans += p[z-1];
    }
    stop;

    idx++;
    stop;


}
int main(){
    layer[0] = 1;
    p[0] = 1;
    for(int i=1;i<=52;i++){
        layer[i] = 3 + 2*layer[i-1];
        p[i] = 1 + 2*p[i-1];
    }
    cin>>n>>x;
    eat(n);
    cout<<ans<<endl;

}
