#pragma once
#include <iostream>
#include <vector>

class Graph {
private:
	std::vector<std::vector<int>> vector;
public:
	void rebro(int rebro) {
		std::vector<int> rebr;
		rebr.push_back(rebro);
		vector.push_back(rebr);
	}
	void smeznost(int rebro, int value) {
		int i = 0;
		for (auto it = vector.begin(); it != vector.end(); ++it, i++) {
			std::vector<int> temp = *it;
			if (temp[0] == rebro) {
				vector[i].push_back(value);
			}
		}
	}
	void vivod() {
		for (auto it = vector.begin(); it != vector.end(); ++it) {
			std::vector<int> temp = *it;
			for (auto tit = temp.begin(); tit != temp.end(); ++tit) {
				std::cout << *tit << ' ';
			}
			std::cout << std::endl;
		}
	}
};
