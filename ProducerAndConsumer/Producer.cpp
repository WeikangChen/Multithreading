#include "Producer.h"
#include "Merchandise.h"

template<class DataType>
Producer<DataType>::Producer(string n, Warehouse<DataType> *w) {
	name = n;
	pWarehouse = w;
}

template<class DataType>
string Producer<DataType>::getName() {
	return name;
}

template<class DataType>
void Producer<DataType>::operator()(const DataType array[], const int length) { // override operator "()" for thead called by class
	for (int id = 0; id < length; ++id)
		pWarehouse->moveIn(array[id % length], this);
}