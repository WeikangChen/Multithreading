#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <string>
#include "Merchandise.h"
using namespace std;

template<class DataType>
class Producer;

template<class DataType>
class Consumer; 

template<class DataType>
class Warehouse {
private:
	string name;
	DataType *queue = NULL;
	int size = 0, head = 0, tail = 0, capacity = 0;
	mutex mutexLocker;
	condition_variable conditionVariable;

public:
	Warehouse(string n, int c);
	void moveIn(DataType product, Producer<DataType> *pProducer);
	void moveOut(Consumer<DataType> *pConsumer);
};

#endif
