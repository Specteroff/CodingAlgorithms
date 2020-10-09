#pragma once
#ifndef base64
#define base64
#include <iostream>
#include <string>
#include <deque>
#include "Tools.h"
#include "ASCII.h"
namespace BASE64 {
	char Base64[64] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U',
	'V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w',
	'x','y','z','0','1','2','3','4','5','6','7','8','9','+','/' };



	char GetBASE64(int num) {
		return Base64[num];
	}

	std::string DecodeBase64(std::string frombase64) {
		std::string res = "";
		//Base64 chars to Base64 numbers. Base64 numbers to binary numeral system
		std::string six = "";
		int ExtraZeros = 0;
		for (int i = 0;i < frombase64.length();i++) {
			std::string el = Tools::FromDecToBin(Tools::GetIdByEl(frombase64[i],64,Base64));
			if (frombase64[i] == '=') {
				ExtraZeros += 2;
			}
			else {
				if (el.length() % 6 != 0) {
					int a = 6 - (el.length() % 6);
					std::string newel = "";
					for (int i = 0;i < a;++i) {
						newel += '0';
					}
					newel += el;
					six += newel;
				}
				else {
					six += el;
				}
			}
		}
		for (int i = 0;i < ExtraZeros;++i) {
			six += '0';
		}
		//Distribution by 8 and translation to ASCII
		for (int i = 0;i < six.length() / 8;++i) {
			int pl = 8 * i;
			std::string tmp = "";
			for (int j = 0;j < 8;++j) {
				tmp += six[j + pl];
			}
			res += ASCII::GetASCII(Tools::FromBinToDec(tmp));
		}
		return res;
	}

	std::string EncodeBase64(std::string tobase64) {
		std::string res = "";
		//ASCII chars to binary numeral system.
		std::string eight = "";
		for (int i = 0;i < tobase64.length();++i) {
			std::string el = Tools::FromDecToBin(ASCII::GetASCIINumber(tobase64[i]));
			if (el.length() < 8) {
				int a = 8 - (el.length() % 8);
				std::string newel = "";
				for (int i = 0;i < a;++i) {
					newel += '0';
				}
				newel += el;
				eight += newel;
			}
			else {
				eight += el;
			}
		}
		bool flag = 1;
		int EqualCount;
		if (eight.length() % 6 != 0) {
			flag = 0;
			EqualCount = (6 - (eight.length() % 6)) / 2;
			for (int i = 0;i < EqualCount * 2;++i) {
				eight += '0';
			}
			std::string Equal = "";
		}
		//Distribution by 6 and translation to ASCII
		for (int i = 0;i < eight.length() / 6;++i) {
			int pl = 6 * i;
			std::string tmp = "";
			for (int j = 0;j < 6;++j) {
				tmp += eight[j + pl];
			}
			res += GetBASE64(Tools::FromBinToDec(tmp));
		}
		if (flag == 0) {
			for (int i = 0;i < EqualCount;++i) {
				res += '=';
			}
		}
		return res;
	}
}
#endif