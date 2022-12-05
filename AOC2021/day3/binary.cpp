#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/* int get_bit(int n, int k) {
    return (n >> k) & 1;
}

int digit_counter(int n) {
    int count=0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
} */

/* int part1(void) {
    ifstream input("input.txt");
    int num=0, one_count=0, zero_count=0, most_common=0, digits=0;
    vector<int> v;
    while (input >> num) v.push_back(num);
    digits = digit_counter(v.front());
    for (const int &x : v) {
        for (int i=0; i<digits; i++) {
            
        }
        cout << x << endl;
    }
    return num;
} */

int main(void)
{
    ifstream input("input.txt");
    int num=0, one_count=0, zero_count=0, most_common=0, digits=0;
    vector<int> v;
    while (input >> num) cout << num << endl;
    /* for (const int &x : v) {
        cout << x << endl;
    } */
}