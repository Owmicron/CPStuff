#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,f[10];
queue <str> q;
str x;
bool vis[50000];
int d[50000];
int num (str s){
    int pro = 0;
    for(int i=0;i<s.size()-1;i++){
        pro += f[s.size()-(i+1)] * (int(s[i])-49);
        for(int j=i+1;j<s.size();j++){
            if(int(s[j])>=int(s[i])){
                s[j]=char((int(s[j])-1));
            }
        }
    }
    pro+=int(s[s.size()-1])-48;
    return pro;
}
str flip(str s,int start){
    int fin = start + k - 1;
    int cnt = 0;
    for(int i = start; i <= start + (k/2) - 1; i++){
        swap (s[i],s[fin-cnt]);cnt++;
    }
    return s;
}
int main(){
    f[0]=1;for(int i=1;i<=8;i++)f[i]=i*f[i-1];
    cin>>n;
    for(int i=1;i<=n;i++){
        int a; cin>>a; x += char(a+48);
    }
    cin>>k;
//    cout<<x<<endl;
//    for(int i=0;i<=x.size()-k;i++){
//        cout<<flip(x,i)<<endl;
//    }
    vis [num(x)] = true;
    q.push(x);
    if(vis[1]){q.pop();}
    else{d[1]=-1;}
    while(!q.empty()){
        str t;
        t = q.front();q.pop();
        int nt = num(t);
        if(nt == 1){break;}
        for(int i=0;i<=t.size()-k;i++){
            str temp = flip(t,i);
            int ntemp = num(temp);
            if(!vis[ntemp]){
                vis[ntemp]=true;
                d[ntemp]=d[nt]+1;
                q.push(temp);
            }

        }
    }
    cout<<d[1]<<endl;

}
