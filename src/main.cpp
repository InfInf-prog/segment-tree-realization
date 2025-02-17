#include <iostream>
#include <vector>
#include <algorithm>

#include "utils/ArraysFunctions.h"
#include "tree/SegmentTree.h"

using namespace std;

int main() {
    int size = 14;
    //vector<int> arr = generate_array_with_random_numbers(size);
    vector<long long> arr = {0, 1, 2, 3, 4, 5, 6, 7 ,8 , 9, 10, 11, 12, 13};
    vector<long long> tree(size * 4);
    print_array(arr);

    build(tree, arr, 0, 0, size);
    cout << "----tree is built" << endl;

    // запрос суммы на отрезке  [5, 7] = 5 + 6 + 7 = 18
    int left = 5;
    int right = 7;
    cout  <<  "sum  on [" << left << ", " << right << "] = " << rsq(tree, 0, 0, size, left, right + 1) << endl;

    cout << "----sum is counted" << endl;

    // обновление 7 элемента массива на значение 10 (было 6, станет 10)
    update(tree, 0, 0, size, 7, 10);
    cout << "tree is updated" << endl;

    // запрос суммы на обновлённом отрезке  [5, 7] = 5 + 10 + 7 = 22
    cout << "----sum  on [" << left << ", " << right << "] = " << rsq(tree, 0, 0, size, left, right + 1);

    return 0;
}

