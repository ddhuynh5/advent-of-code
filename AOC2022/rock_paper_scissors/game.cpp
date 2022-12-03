#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int part_one()
{
    pair<char, int> opponent_shapes[3] = {make_pair('A', 1), make_pair('B', 2), make_pair('C', 3)}, my_shapes[3] = {make_pair('X', 1), make_pair('Y', 2), make_pair('Z', 3)};
    ifstream myFile("input.txt");
    char opponent, response;
    int total_score = 0;

    while (myFile >> opponent >> response)
    {
        int score = 0;

        for (int i = 0; i < 3; i++)
        {
            if (opponent == opponent_shapes[i].first)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (response == my_shapes[j].first)
                    {
                        switch (opponent)
                        {
                        case 'A':
                            switch (response)
                            {
                            case 'X':
                                score += 3 + my_shapes[j].second;
                                break;
                            case 'Y':
                                score += 6 + my_shapes[j].second;
                                break;
                            case 'Z':
                                score += 0 + my_shapes[j].second;
                                break;
                            }
                            break;
                        case 'B':
                            switch (response)
                            {
                            case 'X':
                                score += 0 + my_shapes[j].second;
                                break;
                            case 'Y':
                                score += 3 + my_shapes[j].second;
                                break;
                            case 'Z':
                                score += 6 + my_shapes[j].second;
                                break;
                            }
                            break;
                        case 'C':
                            switch (response)
                            {
                            case 'X':
                                score += 6 + my_shapes[j].second;
                                break;
                            case 'Y':
                                score += 0 + my_shapes[j].second;
                                break;
                            case 'Z':
                                score += 3 + my_shapes[j].second;
                                break;
                            }
                            break;
                        }
                    }
                }
            }
        }
        total_score += score;
    }
    myFile.close();

    return total_score;
}

int part_two()
{
    pair<char, int> opponent_shapes[3] = {make_pair('A', 1), make_pair('B', 2), make_pair('C', 3)};
    ifstream myFile("input.txt");
    char opponent, decide, decision[3] = {'X', 'Y', 'Z'};
    int total_score = 0;

    while (myFile >> opponent >> decide)
    {
        int score = 0;

        for (int i = 0; i < 3; i++)
        {
            if (opponent == opponent_shapes[i].first)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (decide == decision[j])
                    {
                        switch (opponent)
                        {
                        case 'A':
                            switch (decide)
                            {
                            case 'X':
                                score += 0 + 3;
                                break;
                            case 'Y':
                                score += 3 + 1;
                                break;
                            case 'Z':
                                score += 6 + 2;
                                break;
                            }
                            break;
                        case 'B':
                            switch (decide)
                            {
                            case 'X':
                                score += 0 + 1;
                                break;
                            case 'Y':
                                score += 3 + 2;
                                break;
                            case 'Z':
                                score += 6 + 3;
                                break;
                            }
                            break;
                        case 'C':
                            switch (decide)
                            {
                            case 'X':
                                score += 0 + 2;
                                break;
                            case 'Y':
                                score += 3 + 3;
                                break;
                            case 'Z':
                                score += 6 + 1;
                                break;
                            }
                            break;
                        }
                    }
                }
            }
        }
        total_score += score;
    }

    myFile.close();

    return total_score;
}

int main()
{
    cout << part_one() << endl;
    cout << part_two() << endl;
}