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

multiset <int> ms;
multiset <int> :: reverse_iterator itr;
bool isprime[3000010];
vi prime,ans;
int child[3000010],n;
void genprime(int x){
    for(int i=2;i<=x;i++)isprime[i]=true;
    for(int i=2;i<=x;i++){
        if(isprime[i]){
            prime.pb(i);
            for(int j=2*i;j<=x;j+=i){
                isprime[j]=false;
            }
        }
    }
    for(int i=0;i<prime.size();i++){
        child[prime[i]] = i+1;
    }
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    genprime(2800000);
    cin>>n;
    for(int i=1;i<=2*n;i++){
        int temp;
        cin>>temp;
        ms.insert(temp);
    }
    for(int i=1;i<=n;i++){
        itr = ms.rbegin();
        int x = *itr;
        int y;
        if(isprime[x]){
            y = child[x];
        }
        else{
            int mx = 1;
            for(int i=2;i<=sqrt(x);i++){
                if(x%i==0){
                    mx = max(mx,i);
                    mx = max(mx,x/i);
                }
            }
            y = mx;
            swap(x,y);
        }
        ms.erase(ms.find(x));
        ms.erase(ms.find(y));
        ans.pb(y);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}
