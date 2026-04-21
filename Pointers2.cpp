#include <iostream>





int main(){
	
	int qty; //has no value or unwanted value so is garbage, initialized
	int *qtyPtr;
	
	qty = 10;// qty assigned to 10
	qtyPtr = &qty;// assigns the address
	
	std::cout<<"\n1: "<<qtyPtr;// prints the address
	std::cout<<"\n1: "<<*qtyPtr; // prints out 10 because the Pointer tells the computer to get the value at the address

//===================================================================================================================
//===================================================================================================================
//===================================================================================================================

	float amt = 1.99, price = 2.99;
	float *amtPtr;
	amtPtr=&amt;
	
	std::cout<<"\n2: "<<*amtPtr;// prints 1.99
	
	*amtPtr = 5.99;
	
	std::cout<<"\n2: "<<*amtPtr;// prints 1.99
	std::cout<<"\n2: "<<amt;//amt is now set to 5.99 so prints 5.99
	
//===================================================================================================================

	float amt2 = 1.99, price2 = 2.99;
	float const *amtPtr2;
	amtPtr2=&amt2;
	
	std::cout<<"\n3: "<<*amtPtr2;// prints 1.99
	
//	*amtPtr2 = 5.99; // doesnt compile beacuse amtPtr2 is constant float and cannot change
	
	amtPtr2 = &price2; // but we can change the location its opinting to not he data in the location
	
	std::cout<<"\n3: "<<*amtPtr2;// prints 2.99
	
//===================================================================================================================


	float amt3 = 1.99, price3 = 2.99;
//	float * const amtPtr3;// now the pointer it self is constant so we have to initalize it 
	
	float * const amtPtr3 = &amt3;
	
	std::cout<<"\n4: "<<*amtPtr3;
	
	amtPtr2 = &price3;// cant change the value because the pointer is constant
	
	std::cout<<"\n4: "<<*amtPtr3;// prints 1.99

//===================================================================================================================
//===================================================================================================================
//===================================================================================================================
//===================================================================================================================
//
//int const *
// cant change the information at the location but can change the location
//
//
//int * consts
//cant change the location but can change the informaiton in the location 
//
//
//int const * const
//cannot change either the location or the informaiton in the location
//
//
//

// const whatever is on the left is the constant you can 





}

