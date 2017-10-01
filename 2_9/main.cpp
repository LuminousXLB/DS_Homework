/************************************************************
  * Line editing system



  ** Function
    ```
    template <class T>
    void print (const list<T> &l);
    ```
    print all the elements in the list

************************************************************/

#include <iostream>
#include <list>

using namespace std;

template <class T>
void print (const list<T> &l);

int main() {
    cout << "Hello world!" << endl;
    return 0;
}



template <class T>
void print (const list<T> &l) {
    if (l.empty()) {
        cout << "EMPTY\t";
    } else {
        list<T>::const_iterator itr = l.begin();
        list<T>::const_iterator itre = l.end();

        do {
            cout << *itr << '\t';
            ++itr;
        } while (itr != itre);
    }
}
