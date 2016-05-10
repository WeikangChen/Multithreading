#include "Consumer.h"

template<class DataType>
Consumer<DataType>::Consumer(string n, Warehouse<DataType> *w) {
	name = n;
	pWarehouse = w;
}

template<class DataType>
string Consumer<DataType>::getName() {
	return name;
}

template<class DataType>
void Consumer<DataType>::operator()() { // override operator "()" for thead called by class
	for (int i = 0; i < 4; ++i)
		pWarehouse->moveOut(this);
}