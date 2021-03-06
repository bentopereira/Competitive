#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


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

const int MOD = 998244353;

ll fastxp(ll a, int x, int mod){
	if(x == 0) return 1;
	if(x == 1) return a;
	return (fastxp((a*a)%mod, x/2, mod)*((x&1)?a:1))%mod;
}

ll check(ll x){
    while(x < 0) x += MOD;
    if(x >= MOD) x %= MOD;
    return x;
}

int main(){
    int n, m; scanf("%d%d", &n, &m);
    if(n == 2){
        printf("0\n");
        return 0;
    }
    ll plc = 1, ans = 0;
    for(int i = n - 1; i <= m; i++){
        if(i == n-1){
            plc = fastxp(2, n - 3, MOD);
            plc *= (ll)(n-2);
            plc = check(plc);
        }
        else{
            plc *= (ll)(i-1);
            plc = check(plc);
            plc *= fastxp(i - (n-1), MOD - 2, MOD);
            plc = check(plc);
        }
        ans += plc;
        ans = check(ans);
    }
    printf("%lld\n", ans);
}
