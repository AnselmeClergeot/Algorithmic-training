#include "edge.h"
#include <iostream>

Edge::Edge(const int previous_index, const int next_index, const int weight) : m_previous_index {previous_index}, m_next_index{next_index}, m_weight {weight}
{

}

int Edge::get_previous_index() const
{
    return m_previous_index;
}
int Edge::get_next_index() const
{
    return m_next_index;
}
int Edge::get_weight() const
{
    return m_weight;
}

std::ostream& operator<<(std::ostream& stream, const Edge& o)
{
    stream << "Edge from " << o.get_previous_index() << " to " << o.get_next_index() << " with a weight of " << o.get_weight() << std::endl;
    return stream;
}
