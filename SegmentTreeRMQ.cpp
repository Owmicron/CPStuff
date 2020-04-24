// lazy vars
int g[100010], stree[4 * 100010], lazy[4 * 100010], inf = 1e9 + 10, lf, rg, v;
int sstree[4 * 100010], slazy[4 * 100010],MAX;
// 1 is for min
// 2 is for max
void build1(int now, int l, int r) {
	if(l == r) {
		stree[now] = g[l];
		return;
	}
	int m = (l + r) / 2;
	build1(now * 2, l, m);
	build1(now * 2 + 1, m + 1, r);
	stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}
void build2(int now, int l, int r) {
	if(l == r) {
		sstree[now] = g[l];
		return;
	}
	int m = (l + r) / 2;
	build2(now * 2, l, m);
	build2(now * 2 + 1, m + 1, r);
	sstree[now] = max(sstree[now * 2], sstree[now * 2 + 1]);
}
void update1(int now, int l, int r, int st, int en, int val) {
	if(lazy[now] != 0) {
		stree[now] += lazy[now];
        if(l!=r) {
            lazy[now * 2] += lazy[now];
            lazy[now * 2 + 1] += lazy[now];
        }
        lazy[now] = 0;
	}
	if(en < l || r < st) {
		return;
	}
	if(st <= l && r <= en){
        stree[now] += val;
        if(l != r){
            lazy[now * 2] += val;
            lazy[now * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update1(now * 2, l, m, st, en, val);
    update1(now * 2 + 1, m + 1, r, st, en, val);
    stree[now] = min(stree[now * 2], stree[now * 2 + 1]);
}
void update2(int now, int l, int r, int st, int en, int val) {
	if(slazy[now] != 0) {
		sstree[now] += slazy[now];
        if(l!=r) {
            slazy[now * 2] += slazy[now];
            slazy[now * 2 + 1] += slazy[now];
        }
        slazy[now] = 0;
	}
	if(en < l || r < st) {
		return;
	}
	if(st <= l && r <= en){
        sstree[now] += val;
        if(l != r){
            slazy[now * 2] += val;
            slazy[now * 2 + 1] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    update2(now * 2, l, m, st, en, val);
    update2(now * 2 + 1, m + 1, r, st, en, val);
    sstree[now] = max(sstree[now * 2], sstree[now * 2 + 1]);
}

int querymin(int now, int l, int r, int st, int en) {
	if(en < l || r < st) {
		return inf;
	}
	if(lazy[now] != 0) {
		stree[now] += lazy[now];
        if(l!=r) {
            lazy[now * 2] += lazy[now];
            lazy[now * 2 + 1] += lazy[now];
        }
        lazy[now] = 0;
	}
	if(st <= l && r <= en) {
		return stree[now];
	}
	int m = (l + r) / 2;
    return min(querymin(now * 2, l, m, st, en), querymin(now * 2 + 1, m + 1, r, st, en));
}
int querymax(int now, int l, int r, int st, int en) {
	if(en < l || r < st) {
		return -inf;
	}
	if(lazy[now] != 0) {
		sstree[now] += slazy[now];
        if(l!=r) {
            slazy[now * 2] += slazy[now];
            slazy[now * 2 + 1] += slazy[now];
        }
        slazy[now] = 0;
	}
	if(st <= l && r <= en) {
		return sstree[now];
	}
	int m = (l + r) / 2;
    return max(querymax(now * 2, l, m, st, en), querymax(now * 2 + 1, m + 1, r, st, en));
}
