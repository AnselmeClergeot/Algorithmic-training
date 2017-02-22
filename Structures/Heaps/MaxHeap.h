#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Heap.h"

class MaxHeap : public Heap
{
    public:
        MaxHeap();
        MaxHeap(std::initializer_list<int> elements);
        MaxHeap(const std::vector<int> &elements);

    private:
        void percolate_up(const int index);
        void percolate_down(const int index);
};

#endif // MAXHEAP_H
