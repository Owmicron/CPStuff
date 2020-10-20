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
int n,xmax,ymin,m,x,y;
int main(){
    xmax = -101;
    ymin = 101;
    cin>>n>>m>>x>>y;

    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        xmax = max(temp,xmax);
    }

    for(int i=1;i<=m;i++){
        int temp;
        cin>>temp;
        ymin = min(temp,ymin);
    }

    bool has=false;
    for(int i=x+1;i<=y;i++){
        if(i<=ymin && i>xmax){
            has=true;break;
        }
    }
    if(has)cout<<"No War\n";
    else cout<<"War\n";




}
