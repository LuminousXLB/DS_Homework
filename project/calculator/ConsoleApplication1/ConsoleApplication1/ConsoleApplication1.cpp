// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。਍⼀⼀ഀഀ
਍⌀椀渀挀氀甀搀攀 ∀猀琀搀愀昀砀⸀栀∀ഀഀ
#include <iostream>਍⌀椀渀挀氀甀搀攀 ∀挀愀氀挀甀氀愀琀漀爀⸀栀∀ഀഀ
਍甀猀椀渀最 渀愀洀攀猀瀀愀挀攀 猀琀搀㬀ഀഀ
਍搀漀甀戀氀攀 挀愀氀挀甀氀愀琀攀⠀挀栀愀爀 猀琀爀嬀崀⤀ 笀ഀഀ
	// 考虑基础题模式਍ऀ⼀⼀ 鸀끛❳⬀✀Ⰰ ✀ⴀ✀Ⰰ ✀⨀✀Ⰰ ✀⼀✀Ⰰ ✀帀✀Ⰰ ✀℀✀ഀഀ
	// 不包含`(`和`)`਍ऀ瘀攀挀琀漀爀㰀漀瀀㸀 猀攀爀椀愀氀 㴀 猀攀爀椀愀氀椀稀攀⠀猀琀爀⤀㬀ഀഀ
਍ऀ瘀攀挀琀漀爀㰀搀漀甀戀氀攀㸀 渀甀洀戀攀爀㬀ഀഀ
	vector<op_type> oper;਍ऀ⼀⼀ ㄀⸀㈀ ⬀ ㈀ ⨀ ㌀ ⼀ 㐀 ⬀ ㈀ 帀 ㌀ ⬀ ㌀ ℀ഀഀ
਍ऀ昀漀爀 ⠀椀渀琀 椀 㴀 　㬀 椀 㰀 猀攀爀椀愀氀⸀猀椀稀攀⠀⤀㬀 椀⬀⬀⤀ 笀ഀഀ
		op cur = serial[i];਍ऀऀ猀眀椀琀挀栀 ⠀挀甀爀⸀琀礀瀀攀⤀ 笀ഀഀ
		case NUM:਍ऀऀऀ渀甀洀戀攀爀⸀瀀甀猀栀开戀愀挀欀⠀挀甀爀⸀瘀愀氀⤀㬀ഀഀ
			break;਍ऀऀ挀愀猀攀 䘀䄀䌀吀㨀ഀഀ
			singleOp(cur.type, number);਍ऀऀऀ戀爀攀愀欀㬀ഀഀ
		case POW:਍ऀऀऀ漀瀀攀爀⸀瀀甀猀栀开戀愀挀欀⠀挀甀爀⸀琀礀瀀攀⤀㬀ഀഀ
			break;਍ऀऀ挀愀猀攀 䴀唀䰀㨀ഀഀ
		case DIV:਍ऀऀऀ眀栀椀氀攀 ⠀℀漀瀀攀爀⸀攀洀瀀琀礀⠀⤀ ☀☀ 漀瀀攀爀⸀戀愀挀欀⠀⤀ 㸀㴀 䴀唀䰀⤀ 笀ഀഀ
				binaryOp(oper.back(), number);਍ऀऀऀऀ漀瀀攀爀⸀瀀漀瀀开戀愀挀欀⠀⤀㬀ഀഀ
			}਍ऀऀऀ漀瀀攀爀⸀瀀甀猀栀开戀愀挀欀⠀挀甀爀⸀琀礀瀀攀⤀㬀ഀഀ
			break;਍ऀऀ挀愀猀攀 䄀䐀䐀㨀ഀഀ
		case SUB:਍ऀऀऀ眀栀椀氀攀 ⠀℀漀瀀攀爀⸀攀洀瀀琀礀⠀⤀⤀ 笀ഀഀ
				binaryOp(oper.back(), number);਍ऀऀऀऀ漀瀀攀爀⸀瀀漀瀀开戀愀挀欀⠀⤀㬀ഀഀ
			}਍ऀऀऀ漀瀀攀爀⸀瀀甀猀栀开戀愀挀欀⠀挀甀爀⸀琀礀瀀攀⤀㬀ഀഀ
			break;਍ऀऀ紀ഀഀ
	}਍ऀ⼀⼀ 欀㹢൜ഀ
	while (!oper.empty()) {਍ऀऀ漀瀀开琀礀瀀攀 挀甀爀 㴀 漀瀀攀爀⸀戀愀挀欀⠀⤀㬀ഀഀ
		binaryOp(cur, number);਍ऀऀ漀瀀攀爀⸀瀀漀瀀开戀愀挀欀⠀⤀㬀ഀഀ
	}਍ऀ⼀⼀ 쀀豨펚鱾൧ഀ
	double result = 0;਍ऀ椀昀 ⠀渀甀洀戀攀爀⸀攀洀瀀琀礀⠀⤀⤀ 笀ഀഀ
		throw Invalid_Experission();਍ऀ紀 攀氀猀攀 笀ഀഀ
		result = number.back();਍ऀऀ渀甀洀戀攀爀⸀瀀漀瀀开戀愀挀欀⠀⤀㬀ഀഀ
		if (!number.empty()) {਍ऀऀऀ琀栀爀漀眀 䤀渀瘀愀氀椀搀开䔀砀瀀攀爀椀猀猀椀漀渀⠀⤀㬀ഀഀ
		}਍ऀ紀ഀഀ
਍ऀ爀攀琀甀爀渀 爀攀猀甀氀琀㬀ഀഀ
}਍ഀഀ
int main() {਍ऀ挀漀甀琀 㰀㰀 ∀倀爀攀猀猀 䌀琀爀氀⬀䌀 琀漀 攀砀椀琀⸀⸀⸀∀ 㰀㰀 攀渀搀氀㬀ഀഀ
	char str[80] = { 0 };਍ऀ挀漀甀琀 㰀㰀 ∀㸀 ∀㬀ഀഀ
	while (cin >> str) {਍ऀऀ挀漀甀琀 㰀㰀 ∀ 㸀 ∀㬀ഀഀ
		cout << calculate(str) << endl;਍ऀ紀ഀഀ
}