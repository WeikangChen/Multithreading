#include <string>
#include <thread>
#include "Merchandise.h"
#include "Warehouse.h"
#include "Producer.h"
#include "Consumer.h"
#include "Warehouse.cpp"
#include "Producer.cpp"
#include "Consumer.cpp"

int main() {
	const int productCount = 3;
	Merchandise products[productCount] = {
		Merchandise("Sneakers", 0),
		Merchandise("Hooder", 1),
		Merchandise("Jeans", 2)
	};
	Warehouse<Merchandise> *pWarehouse = new Warehouse<Merchandise>("Large Depot", 2);
	Producer<Merchandise> *pNike = new Producer<Merchandise>("Nike", pWarehouse);
	Producer<Merchandise> *pAdidas = new Producer<Merchandise>("Adidas", pWarehouse);
	Consumer<Merchandise> *pMacy = new Consumer<Merchandise>("Macy", pWarehouse);
	Consumer<Merchandise> *pSears = new Consumer<Merchandise>("Sears", pWarehouse);
	thread nike(*pNike, products, productCount); // last two are operator's arguments
	thread adidas(*pAdidas, products, productCount); // last two are operator's arguments
	thread macy(*pMacy); // will call operator
	thread sears(*pSears); // will call operator
	nike.join();
	adidas.join();
	macy.join();
	sears.join();
	system("pause");

	cout << " Hello Test " << endl;
	return 1;
}
