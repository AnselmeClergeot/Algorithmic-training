#include <iostream>
#include <cassert>
#include "Heap.h"

Heap::Heap() : m_heap_array {}, m_heap_size {0}
{}

Heap::Heap(const std::initializer_list<int> elements) : m_heap_array(elements), m_heap_size {elements.size()}
{
}

Heap::Heap(const std::vector<int> &elements) : m_heap_array(elements), m_heap_size {elements.size()}
{

}

void Heap::build(const std::vector<int> &array)
{
    m_heap_array = array;
    m_heap_size = array.size();
    build();
}

void Heap::build(const std::initializer_list<int> &array)
{
    m_heap_array = array;
    m_heap_size = array.size();
    build();
}

void Heap::build()
{
    for(int i {m_heap_size - 1}; i >= 0; i--)
    {
        percolate_down(i);
    }
}

void Heap::debug_display() const
{
    for(int value : m_heap_array)
        std::cout << value << ' ';
}

void Heap::clear()
{
    m_heap_array.clear();
    m_heap_size = 0;
}

void Heap::insert_value(const int value)
{
    m_heap_array.push_back(value);
    m_heap_size++;

    percolate_up(m_heap_size-1);
}

std::vector<int> Heap::get_heap_array() const
{
    return m_heap_array;
}

int Heap::get_parent_index(const int index) const
{
    return (index-1)/2;
}

int Heap::get_left_child_index(const int index) const
{
    return index*2 + 1;
}

int Heap::get_right_child_index(const int index) const
{
    return index*2 + 2;
}

void Heap::swap(const int lhs_index, const int rhs_index)
{
    assert(lhs_index < m_heap_size && rhs_index < m_heap_size);

    int temp { m_heap_array[lhs_index] };
    m_heap_array[lhs_index] = m_heap_array[rhs_index];
    m_heap_array[rhs_index] = temp;
}

void Heap::remove_root()
{
    assert(m_heap_size > 0);

    if(m_heap_size > 1)
        swap(m_heap_size-1, 0);

    m_heap_size--;

    if(m_heap_size > 0)
        percolate_down(0);
}

int Heap::get_root() const
{
    assert(m_heap_size > 0);
    return m_heap_array[0];
}

int Heap::get_value_at(const int index) const
{
    assert(index < m_heap_size);
    return m_heap_array[index];
}
