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
ll cx,cy,h,n;
ll py[200][200];
bool used[200][200];
pair < pll , ll > data[200];
bool found;
ll manhattan ( pll a, pll b ){
    return (ll) ( abs(a.fi - b.fi) + abs(a.se - b.se) );
}
bool isvalid (){
    pair<ll,ll> center;
    center = mp (cx,cy);
    bool valid = true;

    for(int i=1;i<=n;i++){
        ll dist = manhattan (center,data[i].fi);

        if(h-dist == data[i].se){continue;}
        else if(data[i].se==0 && h-dist <=0){continue;}
        else{valid=false;break;}
    }
    return valid;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y,height;
        cin>>x>>y>>height;
        py[x][y]=height;
        used[x][y]=true;
        data[i] = mp (mp(x,y),height);
    }
    ll temph;
    for(int i=1;i<=n;i++){
        if(data[i].se > 0){temph=i;break;}
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            cx = i;
            cy = j;
            if(!used[cx][cy]) h = data[temph].se + manhattan ( mp(cx,cy) , data[temph].fi);
            else{h = py[cx][cy];}

            if(h<=0)continue;
            if(isvalid()){found=true;break;}
        }
        if (found) break;
    }
    cout<<cx<<" "<<cy<<" "<<h<<endl;


}
