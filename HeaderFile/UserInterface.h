#ifndef _USERINTERFACE_H
#define _USERINTERFACE_H

#include "GoodInventory.h"

#define SNACK 0
#define DRINK 1
#define DAILY 2
#define CLOTHES 3
#define ELECTRONIC 4
#define INVALID -100 
#define BACK -1
#define QUIT -2
#define DELETE -3
#define CONFIRM -4 
#define RECIEPT -5

enum status {CATEGORY_STATUS, ID_STATUS, QUANTITY_STATUS, RECIEPT_STATUS};

class UserInterface{

    public:

        
    	virtual int inputCategory() = 0;

    	virtual void categoryPage() = 0;


	    // 1.Need to see if we have the chosen ID
		//   If we don't have, it's a invalid input--> return INVALID.
		// 2.return the valid id input
		//   input 'b' means back to the last page, return BACK
		// 3.same as above 3.
    	int inputId();


	    // 1.Need to see if we have the chosen Quantity.
		//   If we don't have enough goods, tell customer that the goods has only X left
		//   and return INVALID
		// 	 
		// 2.return the valid id input
		//   input 'b' means back to choose id --> return BACK
    	int inputQuantity();


    	// recieve list of goods and print with nice format
		// need to show id, name, quantity, and price $  
        void printMenu(&vector<GoodInventory>);


        void idPage();


        void quantityPage();

        // 本來就在這裏
        void clearScreen(){
        	std::cout << std::flush;
        	system("clear");
        }

    private:


    	


    	// the recent chose ategory
    	int category_now;
    	
    	// the recent chose id
    	int id_now;

    	// check this variable to determine
		// whether to print warning  
    	bool input_invalid = false;

    	//check if it's true terminate the program
    	bool terminate = false;

    	// indicate what page is user in
    	status page_status = CATEGORY_STATUS;


    	//used to interact with searchSystem;
    	SearchSystem search;


}


#endif