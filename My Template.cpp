#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define odrkey order_of_key
#define fbodr find_by_order
#define ll long long
#define sq(a) ((a)*(a))
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define pi 3.1415926536
#define endl "\n"
#define nwl cout << endl
#define MAXN 200009
#define ff first
#define ss second
#define pb push_back

ll Pow(ll a, ll b) {
    if (a == 0) return 0LL;
    ll ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}
ll md = (ll) 1e9 + 7;
ll bigmod(ll a, ll b, ll m) {
    if (b == 0) return 1LL;
    ll tm = bigmod(a, b / 2, m);
    tm = (tm * tm) % m;
    if (b % 2) tm = (tm * a) % m;
    return tm;
}
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll up = 1;
    ll down = 1;
    for (ll i = 0; i < r; i++) {
        up = (up * (n - i)) % md; /* md== mod */
        down = (down * (r - i)) % md;
    }
    return (up * bigmod(down, md - 2, md)) % md;
}
string add(string str1, string str2) {
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());

    return str;
}
string divide(string number, int divisor = 2)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    #ifndef ONLINE_JUDGE
        // for getting innput from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    */
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        string a, b;
        cin >> a >> b;
        string s = add(a, b);
        cout << "Case " << cs << ": ";
        cout << divide(s) << endl;
    }
}
