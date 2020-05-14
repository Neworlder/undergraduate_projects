#include "common.h"

Int &median(Int &a, Int &b, Int &c)
{
    return a < b ? b < c ? b : a < c ? c : a : c < b ? b : a < c ? a : c;
}
Int *mid3_partition(Int *l, Int *r)
{
    std::swap(median(*l, *(l + (r - l) / 2), *r), *r);
    return partition(l, r);
}

void qsort(Int *l, Int *r) // [l, r]
{
    if (l >= r)
        return;
    else if (r == l + 1)
    {
        if (*r < *l)
            std::swap(*l, *r);
    }
    else
    {
        Int *pivot = mid3_partition(l, r);
        qsort(l, pivot - 1);
        qsort(pivot + 1, r);
    }
}

int main()
{
    const int sample = 4000;
    for (int n = N / 20; n <= N; n += N / 20)
    {
        int cmp[sample];
        for (int s = 0; s < sample; ++s)
        {
            for (int i = 0; i < n; ++i)
                a[i].val = dis(mt);
            cmp_cnt = 0;
            qsort(a, a + n - 1);
            cmp[s] = cmp_cnt;
        }
        auto res = ave_s2(cmp, sample);
        printf("%d %.4lf %.4lf\n", n, res.first, res.second);
    }
}