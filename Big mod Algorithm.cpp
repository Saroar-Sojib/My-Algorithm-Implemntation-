#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod(string n, ll a)
{

    ll res = 0;
    for (int i = 0; i < n.length(); i++)
         res = (res*10 + (n[i]-'0')) % a;

    return res;
}
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        ll m;
        string s;
        cin>>s>>m;
        if(s[0]=='-')s.erase(0,1);

        int r=mod(s,m);
        if(r==0)cout<<"Case "<<i<<": Yes"<<endl;
        else
            cout<<"Case "<<i<<": No"<<endl;
            i++;
    }
    return 0;
}
