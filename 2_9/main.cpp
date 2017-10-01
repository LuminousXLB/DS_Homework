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
#include <string>
#include <fstream>

using namespace std;

template <class T>
void print (const list<T> &l);

int main() {
    cout << "Hello world!" << endl;

//  Initilize a list to store the text
    list<string> text;

//  Read the file
    ifstream reader;
    while (true) {
        char input[80];
        cout << "Please set the input file: ";
        cin >> input;
        reader.open(input);
        if(reader) {
            break;
        } else {
            cerr << "cannot open input file" << endl;
        }
    }

    char ch[80];
    while(reader.getline(ch, 80, '\n')) {
    	string str = ch;
        text.push_back(str);
    }

    reader.close();

    print(text);

//  Initilize a writer
    ofstream writer;
    while (true) {
        char output[80];
        cout << "Please set the output file: ";
        cin >> output;
        writer.open(output);
        if(writer) {
            break;
        } else {
            cerr << "cannot open output file" << endl;
        }
    }

    writer.close();

    return 0;
}

template <class T>
void print (const list<T> &li) {
    if (li.empty()) {
        cout << "EMPTY\t";
    } else {
        list<T>::const_iterator itr = li.begin();
        list<T>::const_iterator itre = li.end();

        do {
            cout << *itr << '\t';
            ++itr;
        } while (itr != itre);
    }
}
