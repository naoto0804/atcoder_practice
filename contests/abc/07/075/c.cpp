// ref: https://github.com/y-shindoh/pc_challenge_book/blob/master/2.4/q_2.4.3.cpp

#include "template.hpp"

template <typename TYPE>
class UnionFindTree
{
private:
    std::vector<TYPE> parent_;
    std::vector<TYPE> rank_;
    std::vector<TYPE> size_;
    size_t find(size_t i)
    {
        assert(i < parent_.size());
        size_t j = (size_t)parent_[i];
        if (i != j)
        {
            j = find(j);
            parent_[i] = (TYPE)j;
        }
        return j;
    }

public:
    UnionFindTree(size_t n)
        : parent_(n), rank_(n, (TYPE)0), size_(n, (TYPE)1)
    {
        for (size_t i(0); i < n; ++i)
        {
            parent_[i] = (TYPE)i;
        }
    }
    ~UnionFindTree()
    {
        ;
    }
    void
    unite(size_t i,
          size_t j)
    {
        assert(i < parent_.size());
        assert(j < parent_.size());
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        if (rank_[i] < rank_[j])
            std::swap<size_t>(i, j);
        parent_[j] = (TYPE)i;
        if (rank_[i] == rank_[j])
            rank_[i]++;
        size_[i] += size_[j];
    }
    bool
    same(size_t i,
         size_t j)
    {
        assert(i < parent_.size());
        assert(j < parent_.size());
        return find(i) == find(j);
    }
    TYPE
    size(size_t i)
    {
        assert(i < parent_.size());
        i = find(i);
        return size_[i];
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    int a[M], b[M];

    rep(i, M){
        cin >> a[i] >> b[i];
    }

    int ans = 0;
    rep(i, M){
        UnionFindTree<int> tree(N);
        int size;
        rep(j, M){
            if (i == j){continue;}
            tree.unite(a[j] - 1, b[j] - 1);
            size = tree.size(a[i] - 1);
        }
        if (size < N){ans += 1;}
    }
    cout << ans << endl;
}
