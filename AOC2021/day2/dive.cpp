#include <iostream>
#include <fstream>
using namespace std;

int part1(void) {
    ifstream input("input.txt");
    string commands[] = {"forward", "up", "down",};
    string cmd;
    int num=0, depth=0, horiz=0, multiply=0;
    while (input >> cmd >> num) {
        if (cmd == commands[0]) horiz += num;
        if (cmd == commands[1]) depth -= num;
        if (cmd == commands[2]) depth += num;
    }
    multiply = depth * horiz;
    return multiply;
}

int part2(void) {
    ifstream input("input.txt");
    string commands[] = {"forward", "up", "down",};
    string cmd;
    int num=0, depth=0, horiz=0, multiply=0, aim=0;
    while (input >> cmd >> num) {
        if (cmd == commands[0]) {
            horiz += num;
            depth += (aim*num);
        }
        if (cmd == commands[1]) aim -= num;
        if (cmd == commands[2]) aim += num;
    }
    multiply = depth * horiz;
    return multiply;
}

int main(void)
{
    cout << part1() << endl;
    cout << part2() << endl;
}