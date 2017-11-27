#include <iostream>

using namespace std;

class Node
{
private:
    size_t index_;
public:
    Node(int d){
        cout << this << endl;
    };
    ~Node() {}
    
};

int main(int argc, char const *argv[])
{
    Node n(1);
    cout << &n << endl;
    /* code */
    return 0;
}
