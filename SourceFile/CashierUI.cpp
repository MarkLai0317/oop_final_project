#include <vector>
#include <iostream>
#include <cstdlib>
#include "../HeaderFile/CashierUI.h"


using namespace std;

static const char* category_string[] = {"碗裝泡麵", "包裝餅乾", "利樂包", "寶特瓶", "酒"};


void CashierUI::cashierSystem(){
	
	while(!terminate){

		if(this->page_status == CATEGORY_STATUS){

			categoryPage();
		}
		else if(this->page_status == ID_STATUS){

			idPage();
		}
		else if(this->page_status == QUANTITY_STATUS){

			quantityPage();
		}
		else if(this->page_status == RECIEPT_STATUS){

			receiptPage();
		}
		
	}
	system("clear");
}


//correct
void CashierUI::categoryPage(){

	
	clearScreen();
	this->input_invalid = false;
	// get first input category of user
	int chosen_category = inputCategory();
			
	// if the input is invalid
	// ask for input one more time
	while(chosen_category == INVALID){
		// need to print the text to warn user
		this->input_invalid = true;
		clearScreen();		
		chosen_category = inputCategory();
	}

	// if user input quit
	// -->terminate the program 
	if(chosen_category == QUIT){
		
		this->input_invalid = false;
		this->terminate = true;
			
	}
	// user choose to see the receipt
	else if(chosen_category == RECIEPT){
		
		this->input_invalid = false;
		this->page_status = RECIEPT_STATUS;

	}
	// user choose a valid category
	// --> move on to the next page 
	//    --> change page_status to id status
	else{
		
		this->input_invalid = false;
		// choose one category
		this->category_now = chosen_category;
		// step to next page to choose id
		this->page_status = ID_STATUS;

	}
		
}



void CashierUI::quantityPage(){

	clearScreen();
	
	// print the good of the chosen id and wait for the input quantity
	vector<GoodInventory> good_of_idnow;
	good_of_idnow.push_back(search.findInventoryById(this->id_now));
	printMenu(good_of_idnow);///////////////////////


	// ask user to input the quantity he or she wnat
	int chosen_quantity = inputQuantity();
	
	// if the user input is invalid, ask user to input one more time
	while(chosen_quantity == INVALID){
			
		clearScreen();
		printMenu(good_of_idnow);	
		// need to print the text to warn user
		//cout << "Please input the Valid quantity or type 'b' to go back to the last page.\n\n";
		// input one more time
		chosen_quantity = inputQuantity();

	}
	if(chosen_quantity == BACK){
		// set the page_status to go back to the last page
		this->page_status = ID_STATUS;
	}
	else{

		// put the chosen good to the receipt vector.
		quantity_now = chosen_quantity;
		addReceipt();
		this->page_status = ID_STATUS;

	}
}




int CashierUI::inputCategory(){
	// print all categories for customer to chooose
	std::cout << '\n';
	
	std::vector <string> cgy;
        std::string tmp;

        for(int i = 0; i < (WIDE/5/2) - 1 - 2; ++i){
        	for(int j = 0; j < WIDE; ++j) tmp.push_back(' ');
        	cgy.push_back(tmp);
        	tmp.clear();
        }

        for(int i = 0; i < 5; ++i){
       		for(int j = 0; j < (WIDE/5/2) ; ++j) tmp.push_back(' ');
        	tmp += std::to_string(i+1);
       		tmp += ".";
        	for(int j = 0; j < (WIDE/5/2) - 1 - 1; ++j) tmp.push_back(' ');
    	}
    	tmp.push_back(' ');
    	cgy.push_back(tmp);
    	tmp.clear();

 	for(int i = 0; i < (WIDE/5/2) - 1 - 2; ++i){
        	for(int j = 0; j < WIDE; ++j) tmp.push_back(' ');
        	cgy.push_back(tmp);
        	tmp.clear();
    	}

    	for(int i = 0; i < cgy.size(); ++i){
        	for(int j = 0; j < 30; ++j) std::cout << " ";
        	if (i == 6){
                	std::cout << FORE_GROUND_BLACK << BACK_GROUND_RED << "     " << category_string[0] << "    " << BACK_GROUND_GREEN << "    " << category_string[1] << "    " <<  BACK_GROUND_BLUE <<  "     " << category_string[2] << "     " << BACK_GROUND_BROWN <<  "     " << category_string[3] << "     " << BACK_GROUND_WHITE <<  "       " << category_string[4] << "       " << RESET << '\n';
                	for(int j = 0; j < 30; ++j) std::cout << " ";
        	}
        	for(int j = 0; j < cgy[i].size(); ++j){
                	string stmp;
               		stmp.push_back(cgy[i][j]);
                	if(j > (WIDE/5)*4) printcontent_w(stmp);
                	else if (j > (WIDE/5)*3) printcontent_br(stmp);
               		else if (j > (WIDE/5)*2) printcontent_b(stmp);
                	else if (j > (WIDE/5)) printcontent_g(stmp);
                	else printcontent_r(stmp);
        	}
        	std::cout << '\n';
    	}

    	std::cout << '\n';


	for(int i = 0; i < 52; ++i)
		cout << " ";
	cout << "s : Check your receipt     q : Quit \n" << endl;
	// error message
	
	if(input_invalid){
		for(int i = 0; i < 61; ++i)
			cout << " ";
		cout << "Your option is invalid, please try again : ";
	}
	else{
		for(int i = 0; i < 75; ++i)
			cout << " ";
		//cout << "Your option : ";
	}

	char choose = getKeyboardChar();

	// judge whether the choose is valid
	if(choose == '1'){
		category_now = SNACK;
		return SNACK;
	}

	else if(choose == '2'){
		category_now = DRINK;
		return DRINK;
	}

	else if(choose == '3'){
		category_now = DAILY;
		return DAILY;
	}

	else if(choose == '4'){
		category_now = CLOTHES;
		return CLOTHES;
	}

	else if(choose == '5'){
		category_now = ELECTRONIC;
		return ELECTRONIC;
	}

	else if(choose == 'q')
		return QUIT;

	else if(choose == 's')
		return RECIEPT;

	else
		return INVALID;
}


int CashierUI::inputQuantity(){
	// the quantity customer want or back command
	string quantity;
	for(int i = 0; i < 57; ++i)
			cout << " ";
	cout << "Quantity of good (b : Back) : ";
	getline(cin, quantity);

	// back command
	if(quantity == "b")
		return BACK;
	
	// judge whether the input quantity is valid
	// if the quantity is invalid(true)
	bool quantity_invalid = false;
	for(int i = 0 ; i < quantity.size(); ++i){
		// if the input quantity have the char which is not number then it is invalid
		if(quantity[i] < '0' || quantity[i] > '9'){
			quantity_invalid = true;
			break;
		}
	}

	if(quantity_invalid)
		return INVALID;

	GoodInventory temp = search.findInventoryById(id_now);
	int already_buy = 0;
	for(int i = 0 ; i < receipt.size(); ++i){
		int receipt_id_temp = receipt[i].getId();
		if(id_now == receipt_id_temp){
			already_buy = receipt[i].getQuantity();
			break;
		}
	}
	// convert the quantity customer want from string to int
	int quantity_want = stoi(quantity);

	// the quantity in inventory
	int quantity_have = temp.getQuantity() - already_buy;
		
	// invalid quantity(<=0) or too much quantity
	if(quantity_want <= 0 || quantity_want > quantity_have)
		return INVALID;

	if(quantity_want <= quantity_have && quantity_want > 0)
		return quantity_want;	

	return INVALID;
}


int CashierUI::sizeOfReceipt(){
	return this->receipt.size();
}



void CashierUI::confirm(){
	// return the receipt and resize the receipt to 0
	search.purchaseConfirm(this->receipt);
	this->receipt.resize(0);
}

/*void Cashier::addReceipt(){

	receipt.push_back(search.findInventoryOfIdAndSetQuantity(id_now, chosen_quantity));
}*/

void CashierUI::addReceipt(){
    for(int i=0; i<receipt.size(); ++i) {
        if(receipt[i].getId() == id_now){
            receipt[i] = GoodInventory(receipt[i].getId(), receipt[i].getCategory(),
                                           receipt[i].getName(), receipt[i].getPrice(),
                                           receipt[i].getQuantity() + quantity_now);
           
            return; 
        }
    }
    receipt.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now));
}



void CashierUI::deleteOrder(int chosen_order){

	this->receipt.erase(this->receipt.begin()+chosen_order);

}




void CashierUI::printReceipt(){
    std::vector<std::string> rcp;
    std::string tmp;
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < ((WIDE - 1) / 2) - 3; ++i) tmp.push_back(' ');
    tmp += "Receipt";
    for (int i = 0; i < ((WIDE - 1) / 2) - 3; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < 5; ++i) tmp.push_back(' ');
    tmp += "ID";
    for (int i = 0; i < 3; ++i) tmp.push_back(' ');
    tmp += "Description";
    for (int i = 0; i < WIDE - 10 - 10 - 11 - 5; ++i) tmp.push_back(' ');
    tmp += "Price";
    for (int i = 0; i < 10; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();
    int total = 0;
    for (int i = 0; i < receipt.size(); ++i){
        for (int j = 0; j < 5; ++j) tmp.push_back(' ');
	std::string o = std::to_string(i+1);
	tmp += o;
//<<<<<<< HEAD
	for (int j = 0; j < 10 - 5 - o.size(); ++j) tmp.push_back(' ');
//=======
	//for(int j = 0; j < 5 - o.size(); ++j) tmp.push_back(' ');
//>>>>>>> 63f40cc96813dee3d79ada5cf605897a0d55d293
        std::string q = std::to_string(receipt[i].getQuantity());
        std::string p = std::to_string(receipt[i].getPrice());
        std::string pq = std::to_string(receipt[i].getPrice() * receipt[i].getQuantity());
        tmp += q;
        tmp += " x ";
        tmp += receipt[i].getName();
        for (int j = 0; j < WIDE - 10 - q.size() - 3 - receipt[i].getName().size()*2/3 - q.size() - 3 - p.size() - 3 - 3 - 5 - 10; ++j) tmp.push_back('.');
        tmp += q;
        tmp += " x ";
        tmp += p;
        tmp += " = ";
        tmp += "NT$";
        tmp += pq;
        for (int j = 0; j < 15 - pq.size(); ++j) tmp.push_back(' ');
        rcp.push_back(tmp);
        total += receipt[i].getPrice() * receipt[i].getQuantity();
        tmp.clear();
        for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
        rcp.push_back(tmp);
        tmp.clear();
    }

    std::string t = std::to_string(total);
    for (int i = 0; i < WIDE - 5 - 10 - 3 - 6; ++i) tmp.push_back(' ');
    tmp += "Total";
    tmp += " ";
    tmp += "NT$";
    tmp += t;
    for (int j = 0; j < 15 - t.size(); ++j) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for (int i = 0; i < WIDE; ++i) tmp.push_back(' ');
    rcp.push_back(tmp);
    tmp.clear();

    for(int i = 0; i < WIDE; ++i) tmp.push_back('-');
    rcp.push_back(tmp);
    tmp.clear();

    std::cout << '\n';

    for (int i = 0; i < rcp.size(); ++i){
	    for(int j = 0; j < 30; ++j) std::cout << " "; 
        printborder( 2 );
        if(i%2) printcontent_w(rcp[i]);
        else printcontent_b(rcp[i]);
        printborder( 2 );
        std::cout << '\n';
    }
    std::cout << '\n';
}

int CashierUI::quantityFix(int i, std::vector<GoodInventory> &menu){
	for (int j = 0; j < receipt.size(); j++){
		if (receipt[j].getName() == menu[i].getName()){
			int x = receipt[j].getQuantity();
			return x;
		}
	}
	return 0;
}