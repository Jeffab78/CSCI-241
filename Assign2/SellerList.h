#ifndef SellerList_h
#define SellerList_h
#include "Seller.h"
#include <string>


class SellerList
{
	private:
		Seller list[30];
		int numSellers;

	public:
		SellerList();
		SellerList(const std::string& fileName);
		void print() const;
		void sortSellers();
		int searchForSeller(const char* searchName) const;
		void processSalesData(const std::string& fileName);
};
#endif			
