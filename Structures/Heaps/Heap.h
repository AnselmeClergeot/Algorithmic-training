#ifndef HEAP_H
#define HEAP_H
#include <vector>

class Heap {
    public:
        Heap();
        Heap(const std::initializer_list<int> elements);
        Heap(const std::vector<int> &elements);

        std::vector<int> get_heap_array() const;

        void insert_value(const int value);
        void remove_root();
        int get_root() const;
        int get_value_at(const int index) const;


        void clear();
        void debug_display() const;

        void build(const std::vector<int> &array);
        void build(const std::initializer_list<int> &elements);

    protected :
        std::vector<int> m_heap_array;
        int m_heap_size;


        void build();
        int get_parent_index(const int index) const;
        int get_left_child_index(const int index) const;
        int get_right_child_index(const int index) const;

        void swap(const int lhs_index, const int rhs_index);

        virtual void percolate_up(const int index) = 0;
        virtual void percolate_down(const int index) = 0;


};

#endif // HEAP_H
