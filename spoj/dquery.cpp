#include <bits/stdc++.h>

using namespace std;

const int MAXN = 312345;

int n, q;
int last[4 * MAXN], v[MAXN], ans[2 * MAXN];

struct node {
    int value;
    node *left, *right;
    node(int value = 0) : value(value), left(NULL), right(NULL) {}
};

node *seg[MAXN];

void init(node *root, int l = 0, int r = n - 1) {
    if (l == r) {
	root->value = 0;
	return;
    }
    int m = (l + r) / 2;
    root->left = new node();
    root->right = new node();
    init(root->left, l, m);
    init(root->right, m + 1, r);
    root->value = 0;
}

void update(node *cur, node *prev, int i, int v, int l = 0, int r = n - 1) {
    if (l == r) {
	cur->value = v;
	return;
    }
    int m = (l + r) / 2;
    if (i > m) {
	cur->right = new node();
	update(cur->right, prev->right, i, v, m + 1, r);
	cur->left = prev->left;
    } else {
	cur->left = new node();
	update(cur->left, prev->left, i, v, l, m);
	cur->right = prev->right;
    }
    cur->value = cur->left->value + cur->right->value;
}

int query(node *root, int x, int y, int l = 0, int r = n - 1) {
    if (x > r || y < l) return 0;
    if (l >= x && r <= y) return root->value;
    int m = (l + r) / 2;
    return query(root->left, x, y, l, m) + query(root->right, x, y, m + 1, r);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
	scanf(" %d", v + i);
	last[v[i]] = -1;
    }
    seg[0] = new node();
    init(seg[0]);
    for (int r = 1; r <= n; r++) {
	seg[r] = new node();
        node *tmp = new node();
	if (last[v[r-1]] != -1) {
	    update(tmp, seg[r-1], last[v[r-1]], 0);
	} else {
            tmp = seg[r-1];
        }
	last[v[r-1]] = r-1;
	update(seg[r], tmp, r-1, 1);
    }

    scanf(" %d", &q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        printf("%d\n", query(seg[r], l-1, r-1));
    }
    return 0;
}

