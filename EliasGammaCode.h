#pragma once
#ifndef EliasGammaCode
#define EliasGammaCode
#include <string>
#include "ASCII.h"
#include "Tools.h"

namespace Elias {
	//Checking first char
	std::deque<char> CheckFst(std::deque<char>bindeq) {
		if (bindeq[0] == '1') {
			bindeq.pop_front();
		}
		return bindeq;
	}
	//Convert binary code to Elias gamma code fragments.Convert fragments to decimal numeral system.
	std::deque<int> FragmentsAndRLE(std::deque<char>bindeq) {
		int size = 0;
		std::deque<int> res(size + 1);
		int i = 0;
		while (i < bindeq.size()) {
			int ic = i;
			int ZeroCount = 0;
			while (bindeq[ic] == '0') {
				ZeroCount++;
				ic++;
			}
			int resel, b1, b2;
			if (ZeroCount > 0) {
				b1 = i + ZeroCount;
				b2 = b1 + ZeroCount;
				std::string bin = Tools::DeqToStr(bindeq, b1, b2 + 1);
				resel = Tools::FromBinToDec(bin);
				i = b2 + 1;
			}
			else {
				resel = 1;
				i++;
			}
			res[size] = resel;
			size++;
			res.resize(size + 1);

		}
		res.resize(size);
		return res;
	}

	std::string Alternation(std::deque<int> deq) {
		std::string res = "";
		char chr;
		for (int i = 0;i < deq.size();++i) {
			if (i % 2 == 0) {
				chr = '1';
			}
			else {
				chr = '0';
			}
			for (int j = 0;j < deq[i];++j) {
				res += chr;
			}
		}
		return res;
	}

	std::string	 JoinTheFlats(std::string bin) {
		std::string res = "";
		for (int i = 0;i < bin.length() / 8;++i) {
			int pl = 8 * i;
			std::string tmp = "";
			for (int j = 0;j < 8;++j) {
				tmp += bin[j + pl];
			}
			res += ASCII::GetASCII(Tools::FromBinToDec(tmp));
		}

		return res;
	}

	std::string EliasGammaCodeASCII(std::string str) {
		std::deque<char>deq = Tools::StrToDeq(Tools::DeleteGaps(str), deq);
		return Alternation(FragmentsAndRLE(CheckFst(deq)));
	}

	std::string EliasGammaCodeAlgorithm(std::string str) {
		return JoinTheFlats(EliasGammaCodeASCII(str));
	}
}

#endif
