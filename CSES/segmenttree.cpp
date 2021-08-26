#include <vector>
#include <iostream>
using namespace std;

template<class T> struct Seg {
    const T ID = 0; T comb(T a, T b) { return a+b; }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void update(int p, T val) { 
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Seg<long long> segTree;
    segTree.init(n+1);
    int currNumber, queryType, num1, num2;
    for(int i = 1; i <= n; i++) {
        cin >> currNumber;
        segTree.update(i, currNumber);
    }
    for(int i = 0; i < q; i++) {
        cin >> queryType >> num1 >> num2;
        if(queryType == 1) {
            segTree.update(num1, num2);
        } else {
            cout << segTree.query(num1, num2) << endl;
        }
    }
    return 0;
}