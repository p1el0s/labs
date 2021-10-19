#include <list>
#include <map>

class multimap {
private:
	std::map <std::string, std::list<int>> a;
public:
	void insert(const std::string& key, int value) {
		auto it = a.find(key);
		if (it != a.end()) it->second.push_back(value); else { std::list<int> e; e.push_back(value); a[key] = e; }
	}
	const std::list<int>& find(const std::string& key) {
		auto it = a.find(key);
		if (it != a.end()) return it->second; else throw 1;
	}
	void erase(const std::string& key) {
		auto it = a.find(key);
		if (it != a.end()) { auto &la = it->second; la.pop_back(); it->second = la; } else std::cout << "Error!" << std::endl;
	}
	friend std::ostream& operator<< (std::ostream& os, const multimap& dt) {
		auto &ad = dt.a;
		for (auto da = ad.begin(); da != ad.end(); ++da) {
			auto &e = da->second;
			std::cout << da->first << " - key, value - ";
			for (auto ti = e.begin(); ti != e.end(); ti++)
				std::cout << *ti << ' ';
			std::cout << std::endl;
		}
		return os;
	};
};