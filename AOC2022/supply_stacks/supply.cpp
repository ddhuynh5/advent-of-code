#include <bits/stdc++.h>
using namespace std;

void part_one(fstream &f)
{
    string line[9] = {
        "DTWFJSHN",
        "HRPQTNBG",
        "LQV",
        "NBSWRQ",
        "NDFTVMB",
        "MDBVHTR",
        "DBQJ",
        "DNJVRZHQ",
        "BNHMS"},
           ignore, move;
    int how_many, from, to;

    for (int i = 0; i < 10; i++)
        getline(f, ignore);

    while (getline(f, move))
    {
        if (sscanf(move.c_str(), "move %d from %d to %d\n", &how_many, &from, &to) == 3)
        {
            for (int i = 0; i < how_many; i++)
            {
                line[to - 1].append(1, line[from - 1].back());
                line[from - 1].pop_back();
            }
        }
    }

    for (auto i : line)
        cout << i.back();
    cout << endl;
}

void part_two(fstream &f)
{
    string line[9] = {
        "DTWFJSHN",
        "HRPQTNBG",
        "LQV",
        "NBSWRQ",
        "NDFTVMB",
        "MDBVHTR",
        "DBQJ",
        "DNJVRZHQ",
        "BNHMS"},
           ignore, move;
    int how_many, from, to;

    for (int i = 0; i < 10; i++)
        getline(f, ignore);

    while (getline(f, move))
    {
        if (sscanf(move.c_str(), "move %d from %d to %d\n", &how_many, &from, &to) == 3)
        {
            from--;
            to--;
            line[to].append(line[from].substr(line[from].size() - how_many));
            line[from].erase(line[from].size() - how_many, how_many);
        }
    }

    for (auto i : line)
        cout << i.back();
    cout << endl;
}

int main()
{
    fstream f("input.txt");

    cout << "Part 1: ";
    part_one(f);

    f.clear();
    f.seekg(0, ios::beg);

    cout << "Part 2: ";
    part_two(f);

    f.close();

    return 0;
}