#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(const int next_index, const int weight);

    int get_weight() const;
    int get_next_index() const;

private :
    int m_weight;
    int m_next_index;
};

#endif // EDGE_H
