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

int n,m,x,y,thrown,ex;
int f[400000];
pii p[400000];
bool disc[400000];
bool found;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        p[i]=mp(a,b);
    }

    x = p[1].fi;
    for(int i=1;i<=m;i++){
        if(p[i].fi == x || p[i].se == x){disc[i]=true;thrown++;}
    }
    ex = m-thrown;

    for(int i=1;i<=m;i++){
        if(disc[i])continue;
        if(p[i].fi!=p[i].se){
            f[p[i].fi]++;
            f[p[i].se]++;
        }
        else{
            f [p[i].fi]++;
        }
    }

    for(int i=1;i<=n;i++){
        if(f[i]==ex){y=i;found=true;break;}
    }

    if(!found){
        for(int i=1;i<=n;i++)f[i]=0;
        for(int i=1;i<=m;i++)disc[i]=false;
        thrown = 0;
        x = p[1].se;
        for(int i=1;i<=m;i++){
            if(p[i].fi == x || p[i].se == x){disc[i]=true;thrown++;}
        }
        ex = m-thrown;
        for(int i=1;i<=m;i++){
            if(disc[i])continue;
            if(p[i].fi!=p[i].se){
                f[p[i].fi]++;
                f[p[i].se]++;
            }
            else{
                f [p[i].fi]++;
            }
        }

        for(int i=1;i<=n;i++){
            if(f[i]==ex){y=i;found=true;break;}
        }
    }

    if(found)cout<<"YES\n";
    else cout<<"NO\n";

}
