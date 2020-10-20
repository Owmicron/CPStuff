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

int n;
vector < pair <char,int> > a,b;
bool valid;
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        str s,t;
        cin>>s;
        cin>>t;
        valid = false;

        int f = 1;
        char c = s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){f++;}
            else{
                a.pb(mp(c,f));
                c = s[i];
                f = 1;
            }
        }
        a.pb(mp(c,f));

        f = 1;
        c = t[0];
        for(int i=1;i<t.size();i++){
            if(t[i]==t[i-1]){f++;}
            else{
                b.pb(mp(c,f));
                c = t[i];
                f = 1;
            }
        }
        b.pb(mp(c,f));

        if(a.size()==b.size()){
            valid=true;
            for(int i=0;i<a.size();i++){
                char c1,c2;
                int f1,f2;
                c1 = a[i].fi;
                c2 = b[i].fi;
                f1 = a[i].se;
                f2 = b[i].se;
                if(c1==c2 && f2>=f1){valid=true;}
                else{valid=false;break;}
            }
        }
        else valid=false;


        while(!a.empty())a.pob();
        while(!b.empty())b.pob();
        if(valid)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
