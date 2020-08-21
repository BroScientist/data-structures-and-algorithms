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
    int minimumCost(int N, vector<vector<int>>& connections) {

        sort(begin(connections), end(connections), [] (vector<int>& a, vector<int>& b)
             {
                 return a.back() < b.back();
             });
        
        // since cities are numbered from 1 instead of 0, make the size N + 1
        UnionFind uf(N + 1);
        int cost = 0;
        for (vector<int>& conn : connections)
        {
            // unify the two components if they are not already connected
            if (!uf.connected(conn[0], conn[1]))
            {
                uf.unify(conn[0], conn[1]);
                cost += conn[2];
            }
        }
        
        // substract one from the uf to get the actual number of components
        return uf.components() - 1 == 1 ? cost : -1;
    }
};















