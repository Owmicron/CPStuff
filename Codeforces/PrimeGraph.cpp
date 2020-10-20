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

bool isprime[200000];
void sieve(int x){
    for(int i=2;i<=x;i++)isprime[i]=true;
    for(int i=2;i<=x;i++){
        if(isprime[i]){
            for(int j=i*2;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
}
bool valid (int x){
    int l = x;
    int r = x + (x/4);
    bool v = false;
    for(int i=l;i<=r;i++){
        if(isprime[i]){v=true;break;}
    }
    return v;
}
int n;
vpii ans;
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(100000);

    cin>>n;
    for(int i=1;i<=n;i++){
        int l = i;
        int r = i + 1;
        if(r>n)r=1;
        ans.pb(mp(l,r));
    }

    int idx = 1;
    int id = 0;
    while(!isprime[ans.size()]){
        id++;
        if(id>2){idx+=4;id = 1;}

        if(id%2==1){
            ans.pb(mp(idx,idx+2));
        }
        else{
            ans.pb(mp(idx+1,idx+3));
        }
    }

    cout<<ans.size()<<newl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi<<" "<<ans[i].se<<newl;
    }

}

