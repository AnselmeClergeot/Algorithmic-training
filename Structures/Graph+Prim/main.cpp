#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph G(5);

    G.connect(0, 1, 2);
    G.connect(0, 4, 1);
    G.connect(1, 4, 6);
    G.connect(3, 4, 1);
    G.connect(1, 3, 1);
    G.connect(1, 2, 5);
    G.connect(3, 2, 3);

    G.prim_algorithm();

    return 0;
}
