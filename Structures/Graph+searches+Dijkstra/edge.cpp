#include "edge.h"

Edge::Edge(const int next_index, const int weight) : m_weight { weight }, m_next_index { next_index }
{

}

int Edge::get_weight() const
{
    return m_weight;
}

int Edge::get_next_index() const
{
    return m_next_index;
}
