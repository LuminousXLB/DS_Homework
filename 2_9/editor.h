#ifndef _EDITOR_H_
#define _EDITOR_H_

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#endif

using namespace std;

/***********************************************************/
// DEFINITION
/***********************************************************/

class FileOpenFailed {};
class InvalidRange {};

const bool Start_With_Zero = false;
const size_t _col_ = 2000;

class TextEditor {
private:
	list<string> text_;
	string filename_;
	void print(ostream & os);
	size_t standardlize(size_t line) {
		return line - !Start_With_Zero;
	}
	bool validate(size_t line) {
		return 0 <= line && line < text_.size();
	}
	bool validate(size_t bg, size_t ed) {
		return 0 <= bg && bg <= ed && ed < text_.size();
	}
public:
	TextEditor() {};
	TextEditor(const string filename);
	void open(const string filename);
	void quit();
	list<string> list(const size_t bg, const size_t ed);
	void del(size_t line, size_t col, const size_t len);
	void ins(size_t line, size_t col, const string istr);
	size_t cnt_l() {
		return text_.size();
	}
	size_t cnt_c() {
		return _col_;
	}
};

/***********************************************************/
// IMPLEMENTATION
/***********************************************************/

void TextEditor::print(ostream & os) {
	typename list<string>::const_iterator itr = text_.begin();
	typename list<string>::const_iterator itre = text_.end();

	do {
		os << *itr << endl;
		++itr;
	} while (itr != itre);
}

TextEditor::TextEditor(const string filename) {
	open(filename);
}

void TextEditor::open(const string filename) {
	ifstream reader;
	reader.open(filename.c_str());
	if(!reader) {
        throw FileOpenFailed();
    } else {
		filename_ = filename;
	}

    char ch[_col_ + 1];
    while(!reader.eof()) {
        reader.clear();
        reader.getline(ch, _col_ + 1);
        string str(ch);
        text_.push_back(str);
    }

    reader.close();

    print(cout);
}

void TextEditor::quit() {
	ofstream writer;
	// string fn = filename_ + ".out";
	writer.open(filename_.c_str());
	if(!writer) {
		throw FileOpenFailed();
	}

	print(writer);

	writer.close();
	text_.clear();
}

list<string> TextEditor::list(size_t bg, size_t ed) {
	bg = standardlize(bg);
	ed = standardlize(ed);
	if (!validate(bg, ed)) {
		throw InvalidRange();
	}

	::list<string> subtext;

	typename list<string>::const_iterator itr = text_.begin();
	size_t i = 0;
	for (; i < bg; ++i, ++itr);
	for (; i <= ed; ++i, ++itr) {
		cout << *itr << endl;
		subtext.push_back(*itr);
	}

	return subtext;
}

void TextEditor::del(size_t line, size_t col, const size_t len) {
	line = standardlize(line);
	col = standardlize(col);
	if (!validate(line)) {
		throw InvalidRange();
	}

	typename list<string>::iterator itrb, itr = text_.begin();
	for (size_t i = 0; i < line; ++i, ++itr);
	itrb = itr;

	itr -> erase(col, len);
}

void TextEditor::ins(size_t line, size_t col, const string istr) {
	line = standardlize(line);
	col = standardlize(col);
	if (!validate(line)) {
		throw InvalidRange();
	}

	typename list<string>::iterator itrb, itr = text_.begin();
	typename list<string>::const_iterator itre = text_.end();

	for (size_t i = 0; i < line; ++i, ++itr);
	itrb = itr;
	itr -> insert(col, istr);
}
