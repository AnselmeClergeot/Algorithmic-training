#ifndef EDGE_H
#define EDGE_H
#include <ostream>

class Edge
{
public:
    Edge(const int previous_index, const int next_index, const int weight);

    int get_previous_index() const;
    int get_next_index() const;
    int get_weight() const;

private :
    int m_previous_index, m_next_index;
    int m_weight;
};

std::ostream& operator<<(std::ostream& stream, const Edge& o);

#endif // EDGE_H
