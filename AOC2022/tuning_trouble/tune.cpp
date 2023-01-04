#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void tune(string line, int distinct)
{
    string window;
    set<char> s;
    int count = 0;
    bool marker = false;

    for (int i = 0; i < distinct; i++)
        window += line[i];

    count = window.length();

    for (int i = 0; i < line.length() - distinct; i++)
    {
        for (int j = 0; j < window.length(); j++)
        {
            if (!s.insert(window[j]).second)
            {
                s.clear();
                break;
            }

            if (s.size() == distinct)
            {
                marker = true;
                break;
            }
        }

        // slide window
        // [ a b c d]   -->  [b c d e] --> ...
        window = window.substr(1, window.length() - 1);
        window += line[i + distinct];

        if (marker)
            break;

        count++;
    }

    cout << count << endl;
}

int main()
{
    fstream f("input.txt");
    char c;
    int part_one = 4, part_two = 14, test_size = 0, dist[2] = {4, 14};
    string line, test_input[5] = {
                     "mjqjpqmgbljsphdztnvjfqwrcgsmlb",
                     "bvwbjplbgvbhsrlpgdmjqwftvncz",
                     "nppdvjthqldpwncqszvftbrmjlhg",
                     "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg",
                     "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw"};

    while (f >> c)
        line.append(1, c);

    tune(line, part_one);
    tune(line, part_two);

    test_size = sizeof(test_input) / sizeof(string);
    cout << "\n--------- Tests ---------" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Distinct Characters - " << dist[i] << ":" << endl;

        for (int j = 0; j < test_size; j++)
            tune(test_input[j], dist[i]);
        cout << endl;
    }

    f.close();

    return 0;
}
