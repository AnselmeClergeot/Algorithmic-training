/*Algorithm problem from PROLOGIN 2008 semi-final.
Link to exercise : https://prologin.org/train/2008/semifinal/pathfinder
Algorithm problem level 3. (average)
Feel free to copy and/or modify. Don't forget to search by yourself !*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

void allPath(std::vector<std::vector<int>> &square, int currentX, int currentY, int accumulated, int &maximum, std::vector<std::vector<int>> &traces);

int main()
{
    std::vector<std::vector<int>> square; //Multidimensional array to store square contents

    int width;
    std::cin >> width; //Width of the square


    for(int y {0}; y < width; y++) //Filling the square with correct input
    {
        square.push_back(std::vector<int>());

        for(int x {0}; x < width; x++)
        {
            int number;
            std::cin >> number;

            square[y].push_back(number);
        }
    }


    int maximumPath {0};

    /* Multidimensional array :
    Last accumulated path will be stored in concerned coordinates.
    Storing the accumulated path permits not searching already computed path.
    */
    std::vector<std::vector<int>> traces(0);


    for(int y {0}; y < width; y++) //Filling traces[][] with zeros
    {
        traces.push_back(std::vector<int>());
        for(int x {0}; x < width; x++)
        {
            traces[y].push_back(0);
        }
    }

    allPath(square, 0, 0, 0, maximumPath, traces); //Start searching maximum (maximumPath is passed as reference)

    std::cout << maximumPath; //Printing maximum
}

/*Main algorithm recursive function*/
void allPath(std::vector<std::vector<int>> &square, int currentX, int currentY, int accumulated, int &maximum, std::vector<std::vector<int>> &traces)
{
    accumulated+=square[currentY][currentX]; //Add the current number to the total path length

    /* Checking for the last accumulated path starting from this coordinates.
       If the current accumulated path is strictly superior to the one in traces[currentY][currentX] then it is useful to compute this path.
       Otherwise it would be useless because we already searched from this path, but starting with a greater accumulation...*/
    if(traces[currentY][currentX] < accumulated)
    {
        traces[currentY][currentX] = accumulated; //Storing our last path "length"

        if(currentX+1 == square.size() && currentY+1 == square.size()) //If we reached the bottom-right corner then our path is finished
        {
            if(accumulated > maximum) //Is the current path longer than the maximum we have found ?
                maximum = accumulated;
        }


        else //If our path is not finished yet
        {
            //RECURSIVE CALLS
            if(currentX+1 < square.size()) //If we can progress to the right without being out-of-bounds
                allPath(square, currentX+1, currentY, accumulated, maximum, traces);
            if(currentY+1 < square.size()) //If we can progress to the bottom without being out-of-bounds
                allPath(square, currentX, currentY+1, accumulated, maximum, traces);
        }
    }
}
