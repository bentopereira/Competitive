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

int main(){
    rvr(t);
    while(t--){
        int n; ll k; scanf("%d%lld", &n, &k);
        vi a(n);
        int mx = -2e9, mn = 2e9;
        fr(i, n){
            scanf("%d", &a[i]);
            if(a[i] < mn) mn = a[i];
            if(a[i] > mx) mx = a[i];
        }   
        if(k%2){
            fr(i, n){
                printf("%d%c", mx - a[i], " \n"[i==n-1]);
            }
        }
        else{
            fr(i, n){
                printf("%d%c", a[i] - mn, " \n"[i==n-1]);
            }
        }

    }
}
