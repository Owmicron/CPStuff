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

ll dua[42],pre[300100],prex,ans;
pll s[40][300100];
int n,k,a[300100];
pll smaller (pll a, pll b){
    if(a.fi < b.fi)return a;
    else return b;
}
pll mini (int l, int r){
    int rg = r-l+1;
    int lv = log(rg)/log(2);
    pll res = smaller (s[lv][l],s[lv][r-dua[lv]+1]);
    return res;
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dua[0]=1;
    for(int i=1;i<=40;i++)dua[i]=dua[i-1]*2;

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = a[i] + pre[i-1];
    }
    for(int i=1;i<=n;i++){
        s[0][i] = mp (pre[i], i);
    }
    for(int i=1;i<= (log(n)/log(2));i++){
        for(int j=1;j<=n;j++){
            if(j + dua[i-1] <=n){
                s[i][j] = smaller (s[i-1][j],s[i-1][j+dua[i-1]]);
            }
            else break;
        }
    }
//    for(int i=0;i<= (log(n)/log(2));i++){
//        for(int j=1;j<=n;j++){
//            cout<<s[i][j].fi<<" ";
//        }cout<<newl;
//    }

    ll st = 1;
    for(int i=1;i<k;i++){
        ll mx = n-k+i;
        pll z;
//        cout<<"from "<<st<<" "<<mx<<newl;
        z = mini (st,mx);
//        cout<<"mini "<<z.fi<<" "<<z.se<<newl;
        ans += (ll) (z.fi - prex) * i;
        st = z.se+1;
        prex = z.fi;
    }
    ans += (pre[n] - prex)*k;
    cout<<ans<<newl;

}
