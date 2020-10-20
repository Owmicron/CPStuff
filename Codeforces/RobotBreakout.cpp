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
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset

typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;

#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'

char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
// end of Template

int q,xmin,xmax,ymin,ymax,x,y,n,f[6];
bool valid;
bool inrange (int l1, int r1, int l2, int r2){
    pii p[2];
    p[0] = mp(l1,r1);
    p[1] = mp(l2,r2);
    if(p[0] > p[1])swap(p[0],p[1]);
    if(p[1].fi <= p[0].se)return true;
    else return false;
}
void solve(){
    if(valid){
        int l,r;
        l = x; r = x;
        if(f[1]==1)l=-1e5;
        if(f[3]==1)r=1e5;

        if(inrange(l,r,xmin,xmax)){
            xmin = max(xmin,l);
            xmax = min(xmax,r);
        }
        else valid=false;
    }

    if(valid){
        int l,r;
        l = y; r = y;
        if(f[4]==1)l=-1e5;
        if(f[2]==1)r=1e5;

        if(inrange(l,r,ymin,ymax)){
            ymin = max(ymin,l);
            ymax = min(ymax,r);
        }
        else valid=false;
    }

}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;
    for(int cases=1;cases<=q;cases++){
        xmin = -1e5; ymin = xmin;
        xmax = 1e5; ymax = xmax;
        valid = true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            for(int j=1;j<=4;j++)cin>>f[j];
            solve();
        }
        if(valid){
            cout<<1<<" "<<xmin<<" "<<ymin<<newl;
        }
        else cout<<0<<newl;
    }


}
