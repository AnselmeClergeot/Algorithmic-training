#ifndef MINHEAP_H
#define MINHEAP_H
#include <vector>
#include "Heap.h"

class MinHeap : public Heap
{
    public:
        MinHeap();
        MinHeap(std::initializer_list<int> elements);
        MinHeap(const std::vector<int> &elements);

    private :
        void percolate_up(const int index);
        void percolate_down(const int index);
};

#endif // MINHEAP_H
