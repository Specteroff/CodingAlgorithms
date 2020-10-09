#include "CodingAlgorithms.h"
int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "What would you like?\n1 - Elias\t2 - Hamming\t3 - ASCII\t4 - BASE64\n";
	std::string dec1;
	std::getline(std::cin, dec1);
	if (dec1 == "1") {
		std::string str;
		std::getline(std::cin, str);
		std::cout << Coding::EliasGammaCodeAlgorithm(str);
	}
	if (dec1 == "2") {
		std::string str;
		std::getline(std::cin, str);
		std::cout << Coding::HammingAlgorithm(str);
	}
	if (dec1 == "3") {
		std::cout << "Which numeral system?\n1 - Binary\t2 - Decimal\n";
		std::string dec2;
		std::getline(std::cin, dec2);
		std::cout << "Enter string:";
		std::string str;
		std::getline(std::cin, str);

		std::string res = "";

		std::deque<int>gap_index = { -1 };
		int size = 1;
		gap_index.resize(2);
		for (int i = 0;i < str.length();++i) {
			if (str[i] == ' ') {
				gap_index[size] = i;
				size++;
				gap_index.resize(size + 1);
			}
		}
		gap_index.resize(size);
		gap_index.push_back(str.length());
		for (int i = 0;i < gap_index.size() - 1;++i) {
			std::string tmp = "";
			for (int j = gap_index[i] + 1;j < gap_index[i + 1];++j) {
				tmp += str[j];
			}
			if (dec2 == "1") {
				res += Coding::GetASCII(Coding::FromBinToDec(tmp));
			}
			else if (dec2 == "2") {
				res += Coding::GetASCII(atoi(tmp.c_str()));
			}
			else {
				std::cout << "Incorrect input";
			}
		}
		std::cout << res;
	}
	if (dec1 == "4") {
		std::cout << "Encode or decode?\n1 - Encode\t2 - Decode\n";
		std::string dec2;
		std::getline(std::cin, dec2);
		if (dec2 == "1") {
			std::cout << "Enter string:(Doesn't work with Russian yet)";
			std::string str;
			std::getline(std::cin, str);
			std::cout << Coding::EncodeBase64(str);
		}
		else if (dec2 == "2") {
			std::cout << "Enter string:";
			std::string str;
			std::getline(std::cin, str);
			std::cout << Coding::DecodeBase64(str);
		}
		else {
			std::cout << "Incorrect input";
		}
	}
}

