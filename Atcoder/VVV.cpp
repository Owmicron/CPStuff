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
priority_queue < pii > odd,even;
int n,v[200000];
vector <int> o,e;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;cin>>temp;
        if(i%2==1){o.pb(temp);}
        else{e.pb(temp);}
    }
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());

    int f = 1;
    for(int i=1;i<o.size();i++){
        if(o[i]!=o[i-1]){
            odd.push ( mp (-1 * (n/2-f),o[i-1]) );
            f = 1;
        }
        else f++;
    }
    odd.push( mp (-1 * (n/2-f),o[o.size()-1]) );
    odd.push( mp (-1 * n/2 ,100001) );

    f=1;
    for(int i=1;i<e.size();i++){
        if(e[i]!=e[i-1]){
            even.push(mp(-1*(n/2-f),e[i-1]));
            f=1;
        }
        else f++;
    }
    even.push(mp(-1*(n/2-f),e[e.size()-1]));
    even.push(mp (-1* n/2,100001) );
    int a1,a2,b1,b2,c1,c2,d1,d2;
    a1 = odd.top().fi * -1;
    a2 = odd.top().se;
    odd.pop();
    c1 = odd.top().fi * -1;
    c2 = odd.top().se;

    b1 = even.top().fi * -1;
    b2 = even.top().se;
    even.pop();
    d1 = even.top().fi * -1;
    d2 = even.top().se;

    int ans1,ans2,ans3,ans;

    ans1 = a1+b1;
    ans2 = c1+b1;
    ans3 = a1+d1;

    if(a2 == b2){
        ans = min(ans2,ans3);
    }
    else {ans = ans1;}
    cout<<ans<<endl;

}
