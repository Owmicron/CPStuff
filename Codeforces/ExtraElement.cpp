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

ll n,ans;
ll b[300000];
pll a[300000];
map <ll,ll> f;
map <ll,ll> :: iterator itr;
bool valid;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        a[i] = mp(b[i],i);
    }
    sort(a+1,a+1+n);
    if(n<=3){
        valid=true;
        ans = 1;
    }
    else{
        ll need = n-1;
        for(int i=2;i<=n;i++){
            ll sel = a[i].fi - a[i-1].fi;
            f[sel]++;
            if(f[sel]==need){valid=true; ans=a[i].se;}
        }
        if(!valid){
            need = n-2;
            for(int i=1;i<=n;i++){
                ll sel,sel1,temp,sel2,sel3;
                if(i==1){
                    sel=a[i+1].fi-a[i].fi;
                    f[sel]--;
                    for(itr = f.begin();itr!=f.end();itr++){
                        if (itr->se > 0){temp=itr->fi;break;}
                    }
                    if(f[temp]==need){valid=true;ans=a[i].se;}
                    f[sel]++;
                }
                else if(i==n){
                    sel=a[i].fi - a[i-1].fi;
                    f[sel]--;
                    for(itr = f.begin();itr!=f.end();itr++){
                        if (itr->se > 0){temp=itr->fi;break;}
                    }
                    if(f[temp]==need){valid=true;ans=a[i].se;}
                    f[sel]++;
                }
                else{
                    sel1 = a[i].fi - a[i-1].fi;
                    sel2 = a[i+1].fi - a[i].fi;
                    sel3 = a[i+1].fi - a[i-1].fi;
                    f[sel1]--;
                    f[sel2]--;
                    f[sel3]++;
                    for(itr = f.begin();itr!=f.end();itr++){
                        if (itr->se > 0){temp=itr->fi;break;}
                    }
                    if(f[temp]==need){valid=true;ans=a[i].se;}
                    f[sel1]++;
                    f[sel2]++;
                    f[sel3]--;
                }
                if(valid)break;
            }
        }
    }
    if(!valid)ans=-1;
    cout<<ans<<newl;

}

