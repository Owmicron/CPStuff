#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,a,b,wl;
char st[200000];
bool dis[200000],iswl[200000];
pair<ll,ll> node[200000];
vector<ll> w,e;
void disc(ll x){
    w.erase(w.begin()+x-2,w.begin()+x-1);
}
int main(){
    cin>>n;
    n--;
    for(ll i=1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        if(u>v){swap(u,v);}
        node[i].first=u;
        node[i].second=v;
    }
    sort(node+1,node+1+n);
    dis[node[1].first]=true;
    st[node[1].first]='a';a++;
    dis[node[1].second]=true;
    st[node[1].second]='b';b++;
    for(ll i=2;i<=n;i++){
        if((!dis[node[i].first])&&(!dis[node[i].second])){
            w.push_back(i);
        }
        else if((dis[node[i].first])&&(dis[node[i].second])){continue;}
        else{
            if(dis[node[i].first]){
                dis[node[i].second]=true;
                if(st[node[i].first]=='a'){st[node[i].second]='b';b++;}
                else{st[node[i].second]='a';a++;}
            }
            else{
                dis[node[i].first]=true;
                if(st[node[i].second]=='a'){st[node[i].first]='b';b++;}
                else{st[node[i].first]='a';a++;}
            }
        }
    }
    while(!w.empty()){

        for(ll i=0;i<w.size();i++){
            if((!dis[node[w[i]].first])&&(!dis[node[w[i]].second])){continue;}
            if(dis[node[w[i]].first]){
                dis[node[w[i]].second]=true;
                if(st[node[w[i]].first]=='a'){st[node[w[i]].second]='b';b++;}
                else{st[node[w[i]].second]='a';a++;}
                e.push_back(i);
            }
            else{
                dis[node[w[i]].first]=true;
                if(st[node[w[i]].second]=='a'){st[node[w[i]].first]='b';b++;}
                else{st[node[w[i]].first]='a';a++;}
                e.push_back(i);
            }
            while(!e.empty()){
                disc(e[e.size()-1]);
                e.pop_back();
            }
        }
    }


    cout<<(a*b)-n<<endl;
}
