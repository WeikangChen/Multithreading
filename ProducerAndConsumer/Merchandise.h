#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <string>
using namespace std;

class Merchandise {
private:
	string name;
	int id;

public:
	Merchandise() {}

	Merchandise(string n, int i) {
		name = n;
		id = i;
	}

	string toString() {
		return name + "-" + to_string(id);
	}
};

#endif
