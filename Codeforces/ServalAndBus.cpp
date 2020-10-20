#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,t,s,d,ans;
int mn = 1000000;
int wait(int ar,int in){
    if(ar>t){
        return ar-t;
    }
    else{
        int c;
        int nt = t - ar;
        if(nt%in==0) c = nt;
        else{
            int kal = (nt/in)+1;
            c = in * kal;
        }
        return c-nt;
    }

}
int main(){
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&s,&d);
        if(wait(s,d)<mn){mn=wait(s,d);ans=i;}
    }
    printf("%d\n",ans);
}
