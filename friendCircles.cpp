class UnionFind
{
    int *id, *sz, size, numComponents;
    
public:
    UnionFind(int size)
    {
        id = new int[size];
        sz = new int[size];
        size = size;
        numComponents = size;
        for (int i = 0; i < size; i++)
            id[i] = i, sz[i] = 1;
    }
    
    ~UnionFind()
    {
        delete[] id;
        delete[] sz;
    }
    
    int find(int p)
    {
        int root = p;
        // loop until root is not equal to id[root]
        while (root != id[root])
            root = id[root];
        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }
    
    void unify(int p, int q)
    {
        int root1 = find(p);
        int root2 = find(q);
        if (root1 == root2)
            return;
        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        else
        {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numComponents--;
    }
    
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    int componentSize(int p)
    {
        return sz[find(p)];
    }
    
    int count()
    {
        return size;
    }
    
    int components()
    {
        return numComponents;
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UnionFind uf(M.size());
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                if (M[i][j] == 1)
                    uf.unify(i, j);
            }
        }
        return uf.components();
    }
};


