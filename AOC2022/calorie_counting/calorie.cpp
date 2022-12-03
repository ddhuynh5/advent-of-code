#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> totals;

int part_one()
{
    ifstream myFile("input.txt");
    string s;
    int total_cal = 0, i = 0, most_cal = 0;

    while (getline(myFile, s))
    {
        if (s.empty() || myFile.eof())
        {
            if (myFile.eof())
            {
                int s_to_i = 0;
                istringstream(s) >> s_to_i;
                total_cal += s_to_i;
            }
            totals.push_back(total_cal);
            total_cal = 0;
        }
        else
        {
            istringstream tmp(s);
            int n = 0;
            tmp >> n;
            total_cal += n;
        }

        if (total_cal > most_cal)
            most_cal = total_cal;
        i++;
    }

    myFile.close();

    return most_cal;
}

int part_two()
{
    int first = totals[0], second = totals[1], third = totals[2];

    for (vector<int>::iterator it = totals.begin(); it != totals.end(); it++)
    {
        if (*it > first)
            first = *it;
        else if (*it > second)
            second = *it;
        else if (*it > third)
            third = *it;
    }

    return first + second + third;
}

int main()
{
    cout << "Part One: " << part_one() << endl;
    cout << "Part Two: " << part_two() << endl;

    return 0;
}