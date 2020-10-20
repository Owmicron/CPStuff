#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool noz[101];
ll lz;
bool act;
str p[100000];
string rev(string x){
    string r="";
    for(int i=x.size()-1;i>=0;i--){
        r+=x[i];
    }
    return r;
}
int main(){
    ll n,m,f_1[101],l_1[101];
    string s[101];
    cin>>n>>m;
    m+=2;
    for(int i=n;i>=1;i--){
        cin>>s[i];

        f_1[i]=s[i].find('1');
        l_1[i]=rev(s[i]).find('1');
        if(f_1[i] > 300){f_1[i]=0;noz[i]=true;}
        else{
            if(!act){lz=i;act=true;}
        }
        if(l_1[i] > 300){l_1[i]=m-1;noz[i]=true;}
        else{
            if(!act){lz=i;act=true;}
        }
        l_1[i]=(m-1)-l_1[i];
        //cout<<" "<<f_1[i]<<" "<<l_1[i]<<" "<<endl;
    }

    ll poss=1;
    n=lz-1;
    for(ll i=1;i<=n;i++){
        poss*=2;
    }
    //cout<<poss<<endl;

    p[1]="";
    for(ll i=1;i<=lz;i++)p[1]+="l";

    for(ll i=2;i<=poss;i++){
        p[i]=rev(p[i-1]);
        for(ll j=0;j<lz;j++){
            if (p[i][j] == 'l'){
                p[i][j]='r';
                break;
            }
            else{p[i][j]='l';}
        }
        p[i]=rev(p[i]);
        //cout<<p[i]<<endl;
    }

    ll ans=10000000;
    for(ll i=1;i<=poss;i++){
        ll sum=0;
        for(ll j=0;j<lz-1;j++){
            if(p[i][j] == 'l'){
                if(p[i][j+1] == 'l'){
                    if(!noz[j+1]){sum+=(l_1[j+1]*2)+1;}
                    else{sum++;}
                }
                else{sum+=m;}
            }
            else{
                if(p[i][j+1] == 'l'){sum+=m;}
                else{
                    if(!noz[j+1]){sum+=((m-1-f_1[j+1])*2)+1;}
                    else{sum++;}
                }
            }
            //cout<<sum<<endl;
        }
        if(p[i][lz-1] == 'r'){sum+=(m-1-f_1[lz]);}
        else{sum+=l_1[lz];}
        ans=min(sum,ans);
        //cout<<p[i]<<" "<<sum<<endl<<endl;
    }
    if(act){cout<<ans;}
    else{cout<<0;}
}
