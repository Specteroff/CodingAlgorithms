#pragma once
#ifndef hamming
#define hamming
#include <iostream>
#include <string>
#include "Tools.h"
#include "ASCII.h"

namespace Hamming {
	//Check N Under One
	int CheckNUnderOne(int num) {
		if (num % 2 == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	//Hamming check of 1 element
	std::string OneElOfHamming(std::string tohamming) {
		std::string res = "";
		int OneUnderOne = 0, TwoUnderOne = 0, FourUnderOne = 0, EightUnderOne = 0;
		for (int o = 0;o < 15;++o) {
			if ((o % 2 == 0) && (tohamming[o] == '1')) {
				OneUnderOne++;
			}
		}
		for (int o = 2;o < 15;++o) {
			if ((o + 2) % 4 == 0) {
				for (int l = 0;l <= 1;++l) {
					if (tohamming[o + l - 1] == '1') {
						TwoUnderOne++;
					}
				}
			}
		}
		for (int o = 4;o < 15;++o) {
			if ((o + 4) % 8 == 0) {
				for (int l = 0;l < 4;++l) {
					if (tohamming[o + l - 1] == '1') {
						FourUnderOne++;
					}
				}
			}
		}
		for (int o = 8;o <= 15;++o) {
			if (tohamming[o - 1] == '1') {
				EightUnderOne++;
			}
		}
		std::string bin = std::to_string(CheckNUnderOne(EightUnderOne)) + std::to_string(CheckNUnderOne(FourUnderOne)) + std::to_string(CheckNUnderOne(TwoUnderOne)) + std::to_string(CheckNUnderOne(OneUnderOne));
		int check = Tools::FromBinToDec(bin);
		if (check > 0) {
			if (tohamming[check - 1] == '1') {
				tohamming[check - 1] = '0';
			}
			else {
				tohamming[check - 1] = '1';
			}
		}

		res = tohamming;
		res.erase(0, 2);
		res.erase(1, 1);
		res.erase(4, 1);
		return res;
	}

	std::string HammingAlgorithm(std::string tohamming) {
		tohamming = Tools::DeleteGaps(tohamming);
		std::string res = "";
		std::string checked = "";
		for (int i = 0;i < tohamming.length() / 15;++i) {
			int pl = 15 * i;
			std::string tmp = "";
			for (int j = 0;j < 15;++j) {
				tmp += tohamming[j + pl];
			}
			checked += OneElOfHamming(tmp);

		}
		for (int i = 0;i < checked.length() / 8;++i) {
			int pl = 8 * i;
			std::string tmp = "";
			for (int j = 0;j < 8;++j) {
				tmp += checked[j + pl];
			}
			res += ASCII::GetASCII(Tools::FromBinToDec(tmp));
		}
		return res;
	}
}

#endif hamming