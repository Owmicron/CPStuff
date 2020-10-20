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
pair <pii,int> city[200000];
int n,m;
str id[200000];
str ID(int p, int x){
    str temp = "";
    while(x>0){
        int last = x%10;
        temp = char(last+'0') + temp;
        x/=10;
    }
    while(temp.size()<6){
        temp = '0' + temp;
    }
    while(p>0){
        int last = p%10;
        temp = char(last+'0') + temp;
        p/=10;
    }
    while(temp.size()<12){
        temp = '0' + temp;
    }
    return temp;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int p,y;
        cin>>p>>y;
        city[i] = mp (mp (p,y),i);
    }
    sort(city+1,city+1+m);
    int f = 0;
    for(int i=1;i<=m;i++){
        if(city[i].ff!=city[i-1].ff){f=1;}
        else{f++;}
        id[city[i].se] = ID(city[i].ff,f);
    }
    for(int i=1;i<=m;i++)cout<<id[i]<<endl;


}
