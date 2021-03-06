#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

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
typedef vector<vector<int>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N, M;

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	//assert(a[0].size() == b.size());
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<int>(p));
	int col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j]; //cache friendly
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++)
				s += (ll)((ll)a[i][k] * (ll)col[k])%MOD;
			c[i][j] = s%MOD;
		}
	}
	return c;
}

matrix id(int n) {
	matrix c(n, vector<int>(n));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	return c;
}

matrix matrixExp(matrix a, int n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}

/*
 * TEST MATRIX
 */

int main() {
	rvr(t);
	while(t--){
		scanf("%d%d", &M, &N);
		matrix inp(M, vector<int>(M));
		fr(i, M){
			fr(j, M){
				rvr(aux);
				inp[i][j] = aux;
			}
		}
		inp = matrixExp(inp, N);
		fr(i, M){
			fr(j, M){
				printf("%d ", inp[i][j]);
			}
			gnl;
		}
	}
	
}
