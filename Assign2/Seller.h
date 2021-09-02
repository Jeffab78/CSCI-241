#ifndef SELLER_H
#define SELLER_H

/**
 *
 * Seller.h
 *
 * Author:    Jeff Byerly
 * z-ID:      z1860060
 * Date:      2/21/19
 * 
 * Contains the declaration for the Seller class.
 */

class Seller
   {
   private:
   
	char  name[31]{};
	double salesTotal=0.0;
   
   public:


   Seller();
   Seller(const char*, double);

   const char* getName() const;
   double getSalesTotal() const;
   void setSalesTotal(double);
   void print() const;
   };

#endif
