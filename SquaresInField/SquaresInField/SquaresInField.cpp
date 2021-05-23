#include <iostream>
#include <vector>
#include <math.h>

struct vector
{
    int x;
    int y;
};

void visualizeGrid(int columns, int rows, vector a, vector b, vector c, vector d);

class square
{
    float getDistance(vector inpA, vector inpB)
    {
        return hypot((inpA.x - inpB.x), (inpA.y - inpB.y));
    }

public:
    vector a{}, b{}, c{}, d{};

    bool checkSquare(vector a, vector b, vector c, vector d)
    {
        if (getDistance(a, b) == getDistance(b, c) == getDistance(c, d) == getDistance(a, d) && getDistance(a, c) == getDistance(b, d))
            return true;
        else
            return false;
    }
};

long int checkGrid(int x, int y)
{
    int xy{ x * y };
    vector countA{}, countB{}, countC{}, countD{};
    std::vector<square>foundSq{};
    int foundCount{0};
    for (countA.x = 0; countA.x < x; countA.x++)
    {
        for (countA.y = 0; countA.y < y; countA.y++)
        {
            for (countB.x = 0; countB.x < x; countB.x++)
            {
                for (countB.y = 0; countB.y < y; countB.y++)
                {
                    for (countC.x = 0; countC.x < x; countC.x++)
                    {
                        for (countC.y = 0; countC.y < y; countC.y++)
                        {
                            for (countD.x = 0; countD.x < x; countD.x++)
                            {
                                for (countD.y = 0; countD.y < y; countD.y++)
                                {
                                    square thisSquare{ countA,countB,countC,countD };
                                    if (thisSquare.checkSquare(countA,countB,countC,countD) == true)
                                    {
                                        foundSq.resize(foundCount + 1);
                                        foundSq[foundCount].a = countA;
                                        foundSq[foundCount].b = countB;
                                        foundSq[foundCount].c = countC;
                                        foundSq[foundCount].d = countD;
                                        foundCount++;
                                        visualizeGrid(x, y, countA, countB, countC, countD);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    long int result{};
    return result;
}

void visualizeGrid(int columns, int rows, vector a, vector b, vector c, vector d)
{
    int countX{};
    int countY{};
    for (;countY < rows;countY++)
    {
        for (;countX < columns; countX++)
        {
            if (a.x == countX && a.y == countY)
                std::cout << " [A] ";
            else if (b.x == countX && b.y == countY)
                std::cout << " [B] ";
            else if (c.x == countX && c.y == countY)
                std::cout << " [C] ";
            else if (d.x == countX && d.y == countY)
                std::cout << " [D] ";
            else
                std::cout << "  -  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int altmain()
{
    int testCases{};
    std::cin >> testCases;
    std::vector<long int>results;
    results.resize(testCases);
    for (int count{}; count < testCases; count++)
    {
        int rows{};
        int columns{};
        std::cin >> rows >> columns;
        results[count] = checkGrid(rows, columns);
    }
    for (auto& result : results)
        std::cout << result << "\n";
    return 0;
}

int main()
{
    vector a{ 1,1 };
    vector b{ 4,1 };
    vector c{ 4,4 };
    vector d{ 1,4 };
    visualizeGrid(5, 5, a, b, c, d);
}