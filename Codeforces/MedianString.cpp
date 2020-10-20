#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int p[300000];
str a,b;
int k;
int da[300000],db[300000],res[300000];
int main(){
    cin>>k;
    cin>>a;
    cin>>b;
    for(int i=0;i<a.size();i++){
        da[i] = int(a[i])-96;
        db[i] = int(b[i])-96;
    }
    for(int i=k-1;i>=0;i--){
        if(db[i]>=da[i]){
            p[i]=db[i]-da[i];
        }
        else{
            db[i-1]--;
            p[i]=26+db[i]-da[i];
        }
    }
    for(int i=0;i<k;i++){
        if(p[i]%2==0){p[i]/=2;}
        else{p[i]/=2;p[i+1]+=26;}
    }
    for(int i=k-1;i>=0;i--){
        da[i] += p[i];
        if(da[i]>26){da[i]-=26;da[i-1]++;}
    }
    for(int i=0;i<k;i++){
        cout<<char(da[i]+96);
    }cout<<endl;
}

