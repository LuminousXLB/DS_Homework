#include <stack>
#include <vector>
#include <iostream>

using namespace std;

const size_t TravNum = 9;

int main() {
    int arr[10] = { 0 };

    vector<int *> vec(8, NULL);
    // vec.reserve(16);
    //
    // cout << "----------\t" << vec.size() << "\t" << vec.capacity() << "\t" << &*vec.begin() << "\t----------" << endl;
    //
    //
    // vec.resize(1);
    // vec.reserve(4);
    //
    // cout << "----------\t" << vec.size() << "\t" << vec.capacity() << "\t" << &*vec.begin() << "\t----------" << endl;
    //
    // vec.resize(2);
    // vec.shrink_to_fit();
    // // feature introduced by the latest revision of the C++ standard (2011). Older compilers may not support it.
    // // it doesn't
    //
    // cout << "----------\t" << vec.size() << "\t" << vec.capacity() << "\t" << &*vec.begin() << "\t----------" << endl;

    cout << &vec[0] << endl;
    cout << &vec[1] << endl;
    cout << &vec[1] - &vec[0] << endl;

    return 0;

    // for (int i = 0; i < 5; ++i) {
    //     vec.push_back(arr + i);
    // }
    // vec.push_back(NULL);
    // vec.push_back(arr + 1);
    //
    // vec.reserve(5);


    cout << "========================================" << endl;

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
