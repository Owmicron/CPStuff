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

int n,q;
bool hz;
ll dua[30],sum,mx,ans;
vector <int> bin;
ll gcd (ll a, ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;

    while(a%b>0){
        ll c = a%b;
        a = b;
        b = c;
    }
    return b;
}
void to_bin (int x){
    while(x>0){
        if(x%2==0){bin.pb(0);}
        else{bin.pb(1);}
        x/=2;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dua[0]=1;
    for(int i=1;i<=27;i++)dua[i]=dua[i-1]*2;

    cin>>q;
    for(int cases=1;cases<=q;cases++){
        cin>>n;
        while(!bin.empty())bin.pob();
        to_bin(n);
        hz = false;
        for(int i=0;i<bin.size();i++){
            if(bin[i]==0){hz=true;break;}
        }
        ans = 0;
        if(hz){
            sum = 0;
            for(int i=0;i<bin.size();i++){
                sum+=dua[i];
            }
            ans = sum;
        }
        else{
            mx = 0;
            for(int i=1;i<=sqrt(n);i++){
                if(n%i == 0){
                    ll a = i;
                    ll b = n/i;
                    if(a!=n){mx=max(mx,a);}
                    if(b!=n){mx=max(mx,b);}
                }
            }
            ans = mx;
        }
        cout<<ans<<newl;
    }

}
