#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>

class Graph {
private:
	std::vector<std::vector<int>> llst;
public:
	void rebro(int rebro) {
		std::vector<int> rebr;
		rebr.push_back(rebro);
		llst.push_back(rebr);
	}
	void smeznost(int rebro, int value) {
		int i = 0;
		for (auto it = llst.begin(); it != llst.end(); ++it, i++) {
			std::vector<int> temp = *it;
			if (temp[0] == rebro) {
				llst[i].push_back(value);
			}
		}
	}
	void vivod() {
		for (auto it = llst.begin(); it != llst.end(); ++it) {
			std::vector<int> temp = *it;
			for (auto tit = temp.begin(); tit != temp.end(); ++tit) {
				std::cout << *tit << ' ';
			}
			std::cout << std::endl;
		}
	}
	void filee(std::ifstream& F) {
		int rebro = 0;
		int smeznost = 0;
		bool ya = true;
		if (F)
		{
			while (!F.eof())
			{
				for (std::string line; getline(F, line);) {
					if (line[0] == '/') { ya = true; break; }
					if (line[0] == '-') { ya = false; break; }
					if (ya == true) {
						rebro = stoi(line);
						this->rebro(rebro);
					}
					if (ya == false) {
						smeznost = stoi(line);
						this->smeznost(rebro, smeznost);
					}
				}
			}
			F.close();
		}
	}
	void ready() {
		std::vector<std::vector<int>> temp = llst;
		std::vector<std::vector<int>> slst;
		while (1 != 0) {
			slst = temp;
			bool bol = false;
			for (auto it = slst.begin(); it != slst.end(); ++it) {
				std::vector<int> la = *it;
				std::vector<int> fo = *it;
				for (auto fit = ++fo.begin(); fit != fo.end(); ++fit) {
					for (auto lit = slst.begin(); lit != slst.end(); ++lit) {
						std::vector<int> lo = *lit;
						if (lo[0] == *fit) {
							for (auto llit = ++lo.begin(); llit != lo.end(); ++llit) {
								for (auto slit = fo.begin(); slit != fo.end(); ++slit) {
									if (*llit == *slit) {
										break;
									}
									if (slit == --fo.end()) {
										la.push_back(*llit);
										bol = true;
									}
								}
							}
							break;
						}
					}
				}
				temp.push_back(la);
				temp.erase(temp.begin());
			}
			if (bol == false) {
				break;
			}
		}
		llst = temp;
	}
	void show() {
		for (auto it = llst.begin(); it != llst.end(); ++it) {
			std::vector<int> ttemp = *it;
			for (auto tit = ttemp.begin(); tit != ttemp.end(); ++tit) {
				std::cout << *tit << ' ';
			}
			std::cout << std::endl;
		}
	}
};
