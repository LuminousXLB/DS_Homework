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

    char ch[120];
    while(!reader.eof()) {
      // cout << "read a line" << endl;
      reader.getline(ch, 80, '\n');
    	string str(ch);
      // cout << ch << endl;  // 这一行输出是空的？
      // cout << str << endl;  // 这一行输出也是空的？
      text.push_back(str);
    }

    reader.close();

    print(text);


    return 0;


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
        typename list<T>::const_iterator itr = li.begin();
        typename list<T>::const_iterator itre = li.end();

        do {
            cout << *itr << '\t';
            ++itr;
        } while (itr != itre);
    }
}
