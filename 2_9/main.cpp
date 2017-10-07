/************************************************************
  * Line editing system
	- open
		```
		open str
		```
		仅此格式合法，

	- list
		```
		list n1 n2
		```
		仅此格式合法，一个合法的list指令表示输出n1到n2这n2-n1+1行。

	- ins
		```
		ins i j str
		```
		仅此格式合法，表示从i行第j个位置起插入str这个字符串，具体可以看样例，每次加入字符串长度小于100,注意可以加在行末，此时j为行的长度加1。

	- del
		```
		del i j num
		```
		仅此格式合法，表示从i行第j个位置起删除num个字符，数据保证不会删除整行。

	- quit
		```
		quit
		```
		退出程序，并且将所有修改后的字符串输出。


	// 强行open确认是否保存，或者追加？
	// 没有open就不不能做别的事
	// 分段落的问题

************************************************************/
#include "editor.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

	TextEditor editor;

	char filename[80];
	cout << "Please input the filename (without spaces): ";

// OPEN
	try {
		cin >> filename;
		editor.open(filename);
	} catch (FileOpenFailed) {
		cerr << "ERROR\tCannot open the file " << filename << endl;
	}

// QUIT
	try {
		editor.quit();
	} catch (FileOpenFailed) {
		cerr << "ERROR\tCannot open the file " << filename << endl;
	}

    return 0;
}
