#include <cassert>
#include "MaxHeap.h"

MaxHeap::MaxHeap() : Heap()
{

}

MaxHeap::MaxHeap(std::initializer_list<int> elements) : Heap(elements)
{
    build();
}

MaxHeap::MaxHeap(const std::vector<int> &elements) : Heap(elements)
{
    build();
}

void MaxHeap::percolate_up(const int index)
{
    assert(index < m_heap_array.size());

    if(index != 0 && m_heap_array[get_parent_index(index)] < m_heap_array[index])
    {
        swap(get_parent_index(index), index);
        percolate_up(get_parent_index(index));
    }
}

void MaxHeap::percolate_down(const int index)
{
    assert(index < m_heap_array.size());

    int min_child {};

    if(get_right_child_index(index) < m_heap_array.size())
    {
        if(m_heap_array[get_left_child_index(index)] > m_heap_array[get_right_child_index(index)])
            min_child = get_left_child_index(index);
        else
            min_child = get_right_child_index(index);
    }

    else if(get_left_child_index(index) < m_heap_array.size())
    {
        min_child = get_left_child_index(index);
    }
    else
        return;

    if(m_heap_array[min_child] > m_heap_array[index])
    {
        swap(min_child, index);
        percolate_down(min_child);
    }
}
