#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 2e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = inf, cnt = 1;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            if (l->val < r->val) {
                val = l->val;
                cnt = l->cnt;
            }
            else if (r->val < l->val) {
                val = r->val;
                cnt = r->cnt;
            }
            else {
                val = l->val;
                cnt = l->cnt + r->cnt;
            }

		}
		else val = v[lo];
	}
	pii query(int L, int R) {
		if (R <= lo || hi <= L) return {inf, 0};
		if (L <= lo && hi <= R) return {val, cnt};
		push();
        pii lRes = l->query(L, R), rRes = r->query(L, R);
        if (lRes.first < rRes.first) {
            return {lRes.first, lRes.second};
        }
        else if (rRes.first < lRes.first) {
           return {rRes.first, rRes.second};
        }
        return {lRes.first, lRes.second + rRes.second};

		
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = val = x, madd = 0;
            cnt = 1;
        } 
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
            if (l->val < r->val) {
                val = l->val;
                cnt = l->cnt;
            }
            else if (r->val < l->val) {
                val = r->val;
                cnt = r->cnt;
            }
            else {
                val = l->val;
                cnt = l->cnt + r->cnt;
            }

		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			if (l->val < r->val) {
                val = l->val;
                cnt = l->cnt;
            }
            else if (r->val < l->val) {
                val = r->val;
                cnt = r->cnt;
            }
            else {
                val = l->val;
                cnt = l->cnt + r->cnt;
            }
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,m; cin >> n >> m;
    vector<int> a (n);
    for (auto &x : a) cin >> x;
    Node root = Node(a, 0, n);
    for (int i = 0; i < m; ++i) {
        int cmd, u, v; cin >> cmd >> u >> v;
        if (cmd == 1) {
            root.set(u, u + 1, v);
        }
        else {
            auto [val, cnt] = root.query(u, v);
            cout << val << " " << cnt << endl;
        }
    }

}
