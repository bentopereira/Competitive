#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 
#define tsts(t) rvr(t); while(t--)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int main(){
    rvr(n); rvr(x); rvr(pos);
    int G = n - x, L = x - 1;
    int l = 0, r = n;
    ll ans = 1;
    while(l < r){
        int mid = (l+r)/2;
        if(pos == mid){
            break;
        }
        if(pos < mid){
            ans *= (ll) G;
            ans %= MOD;
            G--;
            r = mid;
        }
        else{
            ans *= (ll) L;
            ans %= MOD;
            L--;
            l = mid + 1;
        }
    }
    int lf = G + L;
    while(lf){
        ans *= (ll) lf;
        lf--;
        ans %= MOD;
    }
    printf("%lld\n", ans);
}
