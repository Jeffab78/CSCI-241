#include <string>
#include <iostream>
#include <iomanip>
#include "SellerList.h"


int main()
{
	SellerList SellerList1("sellerData"); //constructor
	SellerList1.print();

	SellerList1.processSalesData("sales.txt");
	SellerList1.print();
}

