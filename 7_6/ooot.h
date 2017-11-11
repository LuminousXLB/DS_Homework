#pragma once
#include <list>

using namespace std;

template <class T>
class ooot {
private:
    list<T> data_;
public:
    ooot() {}

    ooot(T arr[], const int count) {
        for (int i = 0; i < count; i++) {
            data_.push_back(arr[i]);
        }
    }
    int search(const T& elem) {
        typename list<T>::const_iterator itre = data_.end();
        int index = 0;
        for (typename list<T>::const_iterator itr = data_.begin(); itr != itre; ++itr) {
            if (*itr == elem) {
                data_.push_front(elem);
                data_.erase(itr);
                return index;
            } else {
                ++index;
            }
        }
        return -1;
    }
};
