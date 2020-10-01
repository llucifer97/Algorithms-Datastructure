class dsu {
    vector<int> parent, size;
public:
    dsu (int v) {
        parent.resize(v);
        size.resize(v, 1);

        for (int i = 0 ; i < v ; i++)
            parent[i] = i;
    }

    int find (int x) {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    bool inSameSet (int a, int b) {
        return find(a) == find(b);
    }

    void union (int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        // always add smaller set to bigger set
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};
