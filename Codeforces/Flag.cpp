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
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

int n,m;
ll ans;
char a[1002][1002];
bool calc[2000];
ll memo[2000];
ll calculate (ll x){
    if(calc[x])return memo[x];
    else{
        ll res = 0;
        ll idx = 1;
        for(int i=x;i>=1;i--){
            res+=i*idx;
            idx++;
        }
        calc[x]=true;
        memo[x]=res;
        return res;
    }

}
queue <int> q;
map < pii , pair < int,str> > M;
map < pii , pair < int,str> > :: iterator itr;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int j=1;j<=m;j++){
        int f,st;
        vector < pair < pair<char,int> ,int> > v;
        for(int i=1;i<=n;i++){
            if(i==1){
                f = 1;
                st = 1;
            }
            else{
                if(a[i][j]==a[i-1][j]){
                    f++;
                }
                else{
                    v.pb ( mp( mp(a[i-1][j],f) ,st ) );
                    f=1; st=i;
                }
            }
        }
        v.pb ( mp( mp(a[n][j],f) ,st ) );

        for(int i=0;i<v.size();i++){
            if(i+2<v.size()){
                if((v[i].fs == v[i+1].fs)  && (v[i+1].fs == v[i+2].fs)){
                    str s;
                    s+= v[i].ff;
                    s+= v[i+1].ff;
                    s+= v[i+2].ff;
                    int f = v[i].fs;
                    int st = v[i].se;
                    M [mp(st,j)] = mp(f,s);
                }
            }
            else break;
        }
        while(!v.empty())v.pob();
    }

    for(int i=1;i<=n;i++){
        int cons = 0;
        for(int j=1;j<=m;j++){
            pii cor = mp(i,j);
            if(M[cor].fi == 0){
                if(cons>0)q.push(cons);
                cons=0;
            }
            else{
                pii cpr = mp(i,j-1);
                if(M[cor]==M[cpr]){
                    cons++;
                }
                else{
                    if(cons>0)q.push(cons);
                    cons = 1;
                }
            }
        }
        if(cons>0)q.push(cons);
    }

    while(!q.empty()){
        ll z = q.front();
        cout<<calculate(z)<<newl;
        q.pop();
    }

}
