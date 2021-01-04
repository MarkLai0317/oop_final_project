#include <iostream>
#include <vector>
#include "../HeaderFile/FileConnector.h"
#include "../HeaderFile/MainSystem.h"

using namespace std;

int main(){

<<<<<<< HEAD
=======
    system("./data_init");

>>>>>>> 53feacddaf7c5abb0b09c83ba9390f047b8fb5c8
    //declaration of ss
    MainSystem sys;
    //declaraion of supply
    vector<GoodInventory> _old, _new;

    cout << "type enter to supply new product: "; cin.get();

    //supply new product
    _new.push_back( GoodInventory(123, "碗裝泡麵", "dog", 1000, 100) );
    _new.push_back( GoodInventory(123, "碗裝泡麵", "cat", 1200, 100) );
    _new.push_back( GoodInventory(123, "包裝餅乾", "water", 10, 1000) );
    sys.supplyConfirm(_old, _new);
    _old.clear(); _new.clear();

    cout << "type enter to add new purchase: "; cin.get();
    //add new purchase
    vector<GoodInventory> reciept;
    reciept.push_back( GoodInventory(3, "包裝餅乾", "water", 10, 90) );
    reciept.push_back( GoodInventory(2, "碗裝泡麵", "cat", 1200, 10) );
    sys.purchaseConfirm( reciept );

    cout << "type enter to supply new and old product: "; cin.get();
    //supply new and old product
    _old.push_back( GoodInventory(1, "碗裝泡麵", "dog", 1000, 100) );
    _old.push_back( GoodInventory(2, "碗裝泡麵", "cat", 1200, 100) );
    _old.push_back( GoodInventory(3, "包裝餅乾", "water", 10, 1000) );
    _new.push_back( GoodInventory(123, "包裝餅乾", "black", 10000, 3) );
    sys.supplyConfirm(_old, _new);

    cout << "system close" << endl;

<<<<<<< HEAD
=======


>>>>>>> 53feacddaf7c5abb0b09c83ba9390f047b8fb5c8
}