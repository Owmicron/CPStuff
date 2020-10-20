#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll dua[10],r,c,p;
ll tree[130][130];
str quest[40000];
void trans(str s){
    ll xa,xb,ya,yb;
    xa=1;ya=1;xb=dua[p];yb=dua[p];
    for(ll i=1;i<=s.size();i++){
        if(s[i-1]=='0'){xb-=dua[p-i];yb-=dua[p-i];}
        else if(s[i-1]=='1'){xa+=dua[p-i];yb-=dua[p-i];}
        else if(s[i-1]=='2'){xb-=dua[p-i];ya+=dua[p-i];}
        else if(s[i-1]=='3'){xa+=dua[p-i];ya+=dua[p-i];}
    }

    for(ll i=ya;i<=yb;i++){
        for(ll j=xa;j<=xb;j++){
            tree[i][j]=1;
        }
    }
}
int main(){
    dua[0]=1;
    for(ll i=1;i<=8;i++){
        dua[i]=dua[i-1]*2;
    }
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>quest[i];
    }
    cin>>r>>c;
    p=max(r,c);
    for(ll i=1;i<=7;i++){
        if(p<=dua[i]){p=i;break;}
    }

    for(ll i=1;i<=n;i++){
        quest[i].replace(0,1,"");
        trans(quest[i]);
    }

    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<tree[i][j];
            if(j<c){cout<<" ";}
            else{cout<<endl;}
        }
    }
}

