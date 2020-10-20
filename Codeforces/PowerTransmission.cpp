#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
ll ans;
double x[100000],y[100000];
double INF = INT_MAX;
vector <double> gra;
vector <pair < double , pair< double, double> > > line,linef;
void make_line (int a, int b){
    double x1,y1,x2,y2;
    x1 = x[a];
    y1 = y[a];
    x2 = x[b];
    y2 = y[b];
    double y,m,c;
    if(x2-x1 == 0){
        y = 0;
        m = INF;
        c = -x1;
    }
    else{
        m = (y2 - y1) / (x2 - x1);
        y = 1;
        c = y1 - m * x1;
    }
    line.push_back (make_pair(y,make_pair(m,c))) ;
}
bool is_equal (double a, double b){
    if(abs(a-b)<=0.00001){return true;}
    else return false;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            make_line(i,j);
        }
    }
    sort(line.begin(),line.end());
    linef.push_back(line[0]);
    for(int i=1;i<line.size();i++){
        if(line[i]!=line[i-1]){linef.push_back(line[i]);}
    }
    for(int i=0;i<linef.size();i++){
        gra.push_back(linef[i].second.first);
    }
    sort(gra.begin(),gra.end());

    ll temp = linef.size();
    ans = (temp * (temp-1))/2;
    int f = 1;
    for(int i=1;i<gra.size();i++){
        if(gra[i]==gra[i-1]){f++;}
        else {
            if(f>1){
                ans -= (f * (f-1))/2;
            }
            f=1;
        }
    }
    ans -= (f*(f-1))/2;
    cout<<ans<<endl;
}
