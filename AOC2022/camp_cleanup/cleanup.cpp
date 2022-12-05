#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<int> pairs(vector<string> v)
{
    vector<int> numbers, pairs;
    int a = 0, b = 0, c = 0, d = 0, part_one = 0, part_two = 0;

    for (auto i : v)
    {
        replace_if(
            i.begin(), i.end(),
            [](const char &c)
            { return std::ispunct(c); },
            ' ');

        if (stringstream(i) >> a >> b >> c >> d)
        {
            if ((a >= c && b <= d) || (c >= a && d <= b))
                part_one++;
            part_two++;
            if (d < a || c > b)
                part_two--;
        }
    }

    pairs.push_back(part_one);
    pairs.push_back(part_two);

    return pairs;
}

int main()
{
    vector<string> v;
    ifstream f("input.txt");
    string s;

    while (f >> s)
        v.push_back(s);

    for (auto i : pairs(v))
        cout << i << " ";
    cout << endl;

    f.close();

    return 0;
}