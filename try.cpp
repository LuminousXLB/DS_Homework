#include <stack>
#include <vector>
#include <iostream>

using namespace std;

const size_t TravNum = 9;

int main() {
    int arr[10] = { 0 };

    vector<int *> vec(1, NULL);
    // for (int i = 0; i < 5; ++i) {
    //     vec.push_back(arr + i);
    // }
    // vec.push_back(NULL);
    // vec.push_back(arr + 1);
    //
    // vec.reserve(5);

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    cout << &*vec.begin() << endl;

    cout << "====================================================" << endl;

    for (size_t i = 0; i < TravNum; i++) {
        cout << i << '\t' << vec[i] << endl;
    }

    cout << "====================================================" << endl;

    // int *p = new int (3);
    // cout << p << '\t' << *p << endl;

    // cout << "====================================================" << endl;

    // std::vector<int *>::iterator it;
    // it = vec.begin() + 5;

    // cout << *it << endl;

    // vec.reserve(vec.capacity());
    vec.resize(4, NULL);

    // vec[vec.size() + 1] = arr + 5;

    // cout << *it << endl;
    // vec.insert(it, p);
    // cout << *it << '\t' << **it << endl;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    cout << &*vec.begin() << endl;


    // delete p;
    cout << "====================================================" << endl;

    for (size_t i = 0; i < TravNum; i++) {
        cout << i << '\t' << vec[i] << endl;
    }

    return 0;
}
