#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<ll,ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef set <int> :: iterator sitr;
typedef set <ll> :: iterator sltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef mset <int> :: iterator msitr;
typedef mset <ll> :: iterator msltr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
int depth[20],f;
vector <str> v;
str s;
void permute (int start, int x, int deep){
    if(deep>0){

    for(int i=start;i<=3;i++){
        depth[x]=i;
        if(x<deep){
            permute(i,x+1,deep);
        }
        else{
            str temp = "";
            for(int i=1;i<=deep;i++){
                temp += char(depth[i]+'0');
            }
            str z = temp + s;
            sort(z.begin(),z.end());
            v.pb(z);
            while(next_permutation(z.begin(),z.end())){
                v.pb(z);
            }
        }
    }

    }
}

void construct (int x){
    int add = x-3;
    s = "123";
    permute (1,1,add);
    if(x==3){
        v.pb(s);
        while(next_permutation(s.begin(),s.end())){
            v.pb(s);
        }
    }

}
int n;
ll numerize (str z){
    ll m=1;
    ll sum=0;
    for(int i=z.size()-1;i>=0;i--){
        int digit = int(z[i]-'0');
        digit = 1 + 2*digit;
        sum += digit*m;
        m*=10;
    }
    return sum;
}
int main(){
    for(int i=3;i<=9;i++)construct(i);
    cin>>n;
    for(int i=0;i<v.size();i++){
        ll temp = numerize(v[i]);
        if(temp<=n){
            //cout<<temp<<endl;
            f++;
        }
    }
    cout<<f<<endl;
}
