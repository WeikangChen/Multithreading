#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include "Warehouse.h"
using namespace std;

template<class DataType>
class Consumer {
private:
	string name;
	Warehouse<DataType> *pWarehouse = NULL;

public:
	Consumer(string n, Warehouse<DataType> *w);
	string getName();
	void operator()(); // override operator "()" for thead called by class
};

#endif