#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

char compare_strings(string first, string second, string third)
{
    for (int i = 0; i < first.length(); i++)
    {
        for (int j = 0; j < second.length(); j++)
        {
            if (first[i] == second[j])
            {
                for (int k = 0; k < third.length(); k++)
                {
                    if (first[i] == third[k])
                    {
                        return first[i];
                    }
                }
            }
        }
    }

    return '\0';
}

void test_func()
{
    /* string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int test1 = 0;
    for (int i = 0; i < alphabet.length(); i++)
    {
        test1 += get_num_from_case(alphabet[i]);
        cout << test1 << endl;
    }

    int test2 = 0;
    char ch[6] = {'p', 'L', 'P', 'v', 't', 's'};

    for (int i = 0; i < (sizeof(ch) / sizeof(char)); i++)
        test2 += get_num_from_case(ch[i]);
    cout << test2; */

    string first = "vJrwpWtwJgWrhcsFMMfFFhFp";
    string second = "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL";
    string third = "PmmdzqPrVvPwwTWBwg";

    cout << "TEST: " << compare_strings(first, second, third);
}

int get_num_from_case(char c)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lower_count = 0, upper_count = 0;
    map<char, int> letter_to_num;

    for (int i = 0; i < alphabet.length(); i++)
    {
        letter_to_num.insert(make_pair<char, int>(tolower(alphabet[i]), (int)++lower_count));
        upper_count = lower_count + 26;
        letter_to_num.insert(make_pair<char, int>((char)alphabet[i], (int)upper_count));
    }

    return letter_to_num.at(c);
}

int part_one()
{
    int prio = 0;
    ifstream myFile("input.txt");
    string s;

    while (myFile >> s)
    {
        string first = s.substr(0, s.length() / 2);
        string second = s.substr(s.length() / 2, s.length() - 1);
        bool found = false;

        for (int i = 0; i < s.length() / 2; i++)
        {
            for (int j = 0; j < s.length() / 2; j++)
            {
                if (first[i] == second[j])
                {
                    prio += get_num_from_case(first[i]);
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    }

    myFile.close();

    return prio;
}

int part_two()
{
    int prio = 0;
    ifstream myFile("input.txt");
    string f, s, t;

    while (myFile >> f >> s >> t)
    {
        prio += get_num_from_case(compare_strings(f, s, t));
    }

    return prio;
}

int main()
{
    cout << "PART ONE: " << part_one() << endl;
    cout << "PART TWO: " << part_two() << endl;

    test_func();
}
