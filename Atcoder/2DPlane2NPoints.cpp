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

pii red[200],blue[200];
int ans,n,f[200];
bool used[200];
int sz[200];
set <int> s[200];
sitr itr;
priority_queue <pii> q;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        red[i]=mp(x,y);
    }
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        blue[i]=mp(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a,b,c,d;
            a = red[i].fi;
            b = red[i].se;
            c = blue[j].fi;
            d = blue[j].se;
            if(a<c && b<d){sz[i]++;s[i].insert(j);f[j]++;}
        }

        if(sz[i]>0){q.push(mp(-1*sz[i],i));}
    }

    while(!q.empty()){
        int temp = q.top().se;
        int er = *s[temp].begin();
        int fm = f[er];
        for(itr = s[temp].begin();itr!= s[temp].end();itr++){
            if(f[*itr]<fm){
                fm = f[*itr];
                er = *itr;
            }
            f[*itr]--;
        }

        ans++;
        used[temp]=true;
        while(!q.empty())q.pop();

        for(int i=1;i<=n;i++){
            if(used[i])continue;
            if(s[i].count(er)){
                s[i].erase(s[i].find(er));
                sz[i]--;
                f[er]--;
            }
            if(sz[i]>0){q.push(mp(-1*sz[i],i));}
        }
    }
    cout<<ans<<newl;


}
