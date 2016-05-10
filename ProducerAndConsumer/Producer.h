#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include "Warehouse.h"
using namespace std;

template<class DataType>
class Producer {
private:
	string name;
	Warehouse<DataType> *pWarehouse = NULL;

public:
	Producer(string n, Warehouse<DataType> *w);
	string getName();
	void operator()(const DataType array[], const int length); // override operator "()" for thead called by class
};

#endif