#include <iostream>
#include "Warehouse.h"
//#include "Producer.h"
//#include "Consumer.h"
using namespace std;

template<class DataType>
Warehouse<DataType>::Warehouse(string n, int c) {
	name = n;
	capacity = c;
	queue = new DataType[capacity];
}

template<class DataType>
void Warehouse<DataType>::moveIn(DataType product, Producer<DataType> *pProducer) {
	unique_lock<mutex> lock(mutexLocker);
	while (size >= capacity) {
		cout << pProducer->getName() + " try to produce, but the warehouse " + name + " is full, waiting for consumer..." << endl;
		conditionVariable.wait(lock); // will do unlock first to release the mutex
	}
	queue[tail++] = product;
	tail %= capacity;
	++size;
	cout << pProducer->getName() + " produces " + product.toString() + " into warehouse " + name + ", size = " << size << endl;
	conditionVariable.notify_all(); // wake up all waiting threads
}

template<class DataType>
void Warehouse<DataType>::moveOut(Consumer<DataType> *pConsumer) {
	unique_lock<mutex> lock(mutexLocker);
	while (size <= 0) {
		cout << pConsumer->getName() + " ask for product, but the warehouse " + name + " is empty, waiting for producer..." << endl;
		conditionVariable.wait(lock); // will do unlock first to release the mutex
	}
	DataType product = queue[head++];
	head %= capacity;
	--size;
	cout << pConsumer->getName() + " consumes " + product.toString() + " from warehouse " + name + ", size = " << size << endl;
	conditionVariable.notify_all(); // wake up all waiting threads
}