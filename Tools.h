#pragma once
#ifndef tools
#define tools

#include <iostream>
#include <string>
#include <deque>

namespace Tools {

	int GetIdByEl(char el, int size, char arr[]) {
		int res = 0;
		for (int i = 0;i < size;++i) {
			if (arr[i] == el) {
				res = i;
			}
		}
		return res;
	}


	std::string DeleteGaps(std::string str) {
		for (int i = 0;i < str.length();++i) {
			if (str[i] == ' ') {
				str.erase(i, 1);
			}
		}
		return str;
	}


	std::string  DeqToStr(std::deque<char>bindeq, int start, int end) {
		std::string res = "";
		if (end > bindeq.size()) {
			end = bindeq.size();
		}
		for (int i = start;i < end;++i) {
			res += bindeq[i];
		}
		return res;
	}

	std::string ReverseString(std::string bin) {
		std::string res = "";
		for (int i = bin.length() - 1;i >= 0;--i) {
			res += bin[i];
		}
		return res;
	}


	std::deque<char> StrToDeq(std::string todeq, std::deque<char>bindeq) {
		bindeq.resize(todeq.length());
		for (int i = 0;i < todeq.length();++i) {
			bindeq[i] = todeq[i];
		}
		return bindeq;
	}

	int FromBinToDec(std::string bin) {
		std::deque<char> deq;
		for (int i = 0;i < bin.length();++i) {
			deq.push_back(bin[i] - 48);
		}
		int res = 0;
		int mult = 1;
		for (int i = bin.length() - 1;i >= 0;--i) {
			res += deq[i] * mult;
			mult *= 2;
		}
		return res;
	}

	std::string FromDecToBin(int dec) {
		int bin = 0, k = 1;
		while (dec > 0) {
			bin += (dec % 2) * k;
			k *= 10;
			dec /= 2;
		}
		return std::to_string(bin);
	}
}
#endif