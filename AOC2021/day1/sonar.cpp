#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int part1(void) {
    ifstream input("input.txt");
    int dummy = 0, count = 0, num = 0;
    input >> dummy;
    while (input >> num) {
        if (dummy < num) {
            count++;
        }
        dummy = num;
    }
    return count;
}

int part2(void) {
    ifstream input("input.txt");
    int temp = 0, num = 0, count = 0;
    vector<int> v, sum;
    while (input >> num) v.push_back(num);
    int current_sum = 0;
    for (int i=0; i<3; i++) {
        current_sum += v[i];
    }
    sum.push_back(current_sum);
    for (int i=3; i<v.size(); i++) {
        current_sum += v[i] - v[i-3];
        sum.push_back(current_sum);
    }
    temp = sum.front();
    for (int i : sum) {
        if (temp < i) count++;
        temp = i;
    }
    return count;
}

int main(void)
{
    cout << part1() << endl;
    cout << part2() << endl;
}