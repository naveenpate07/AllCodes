#include <bits/stdc++.h>
using namespace std;

struct Item {
    string storeName;
    int rackNumber;
    string itemName;
    int quantity;
    double itemPrice;
};

void addingItems(vector<vector<Item>>& inventory, string& name) {
    while (true) {
        cin.ignore();
        Item item;
        int rnumber, qnumber;
        double pnumber;
        string itemname;

        cout << "Enter the Rack Number: ";
        cin >> rnumber;

        cin.ignore();

        cout << "Enter the Item Name: ";
        getline(cin, itemname);

        cout << "Enter the quantity of the item: ";
        cin >> qnumber;

        cout << "Enter the price of the item: ";
        cin >> pnumber;

        item.storeName = name;
        item.rackNumber = rnumber;
        item.itemName = itemname;
        item.quantity = qnumber;
        item.itemPrice = pnumber;

        int index = inventory.size() - 1;
        inventory[index].push_back(item);

        int option;
        cout << endl << "0. Exit" << endl << "1. Add Another Item" << endl;
        cin >> option;

        if (option == 0) {
            return;
        }
    }
}

void displayStores(const vector<string>& stores) {
    cout << "The stores you have:" << endl;
    int count = 0;
    for (const auto& store : stores) {
        cout << count++ << " " << store << endl;
    }
}

void addStore(vector<vector<Item>>& inventory, vector<string>& stores) {
    int index = inventory.size();
    string name;
    cin.ignore();
    cout << "Hi Admin, please enter the store name: ";
    getline(cin, name);
    cout << endl << "Your store number is: " << index << endl;
    cout << "Store added successfully with the name: " << name << endl;

    stores.push_back(name);
    inventory.push_back(vector<Item>());

    addingItems(inventory, name);
}

void addItems(vector<vector<Item>>& inventory, vector<string>& stores) {
    while (true) {
        cout << endl << "Can you please enter the id of store: ";
        int num;
        cin >> num;

        if (num >= stores.size() || num < 0) {
            cout << "Invalid store ID. Please try again." << endl;
            displayStores(stores);
        } else {
            addingItems(inventory, stores[num]);
            break;
        }
    }
}

Item findItem(int sourceStoreIndex, string itemName, vector<vector<Item>>& inventory) {
    for (int i = 0; i < inventory[sourceStoreIndex].size(); i++) {
        if (inventory[sourceStoreIndex][i].itemName == itemName) {
            Item item = inventory[sourceStoreIndex][i];
            inventory[sourceStoreIndex].erase(inventory[sourceStoreIndex].begin() + i);
            return item;
        }
    }
    return Item{};
}

void replaceItems(vector<vector<Item>>& inventory, int targetStoreIndex, Item item,int sourceStoreIndex) {
    item.storeName=inventory[targetStoreIndex][0].storeName;
    inventory[targetStoreIndex].push_back(item);
}

void shiftItems(vector<vector<Item>>& inventory, vector<string>& stores) {
    while (true) {
        cout << endl << "Enter the index of your store: ";
        int sourceStoreIndex;
        cin >> sourceStoreIndex;

        if (sourceStoreIndex >= stores.size() || sourceStoreIndex < 0) {
            cout << "Invalid store ID. Please try again." << endl;
            displayStores(stores);
        } else {
            string itemName;
            cout << endl << "Enter the item Name: ";
            cin.ignore();
            getline(cin, itemName);

            Item item = findItem(sourceStoreIndex, itemName, inventory);

            if (item.itemName.empty()) {
                cout << "Item not found in store!" << endl;
            } else {
                int targetStoreIndex;
                cout << "Enter the target store index: ";
                cin >> targetStoreIndex;

                if (targetStoreIndex >= stores.size() || targetStoreIndex < 0) {
                    cout << "Invalid target store!" << endl;
                } else {
                    replaceItems(inventory, targetStoreIndex, item,sourceStoreIndex);
                    cout << "Item shifted successfully!" << endl;
                    break;
                }
            }
        }
    }
}

void checkAvaliable(vector<vector<Item>>& inventory) {
    cout << "The Available Items are : " << endl;
    for (auto& store : inventory) {
        for (auto& item : store) {
            if (item.quantity != 0) {
                cout << "Store: " << item.storeName << " | Rack: " << item.rackNumber
                     << " | Item: " << item.itemName << " | Price: " << item.itemPrice
                     << " | Quantity: " << item.quantity << endl;
            }
        }
    }
}

void customerBuy(int index, string name, int quantity, vector<pair<string, int>>& buyed, int& totalPrice, vector<vector<Item>>& inventory, vector<Item>& less, vector<Item>& sparse) {
    bool isAllOkay = false;
    for (int i = 0; i < inventory[index].size(); i++) {
        if (inventory[index][i].itemName == name) {
            if (inventory[index][i].quantity >= quantity) {
                isAllOkay = true;
                inventory[index][i].quantity -= quantity;
                totalPrice += inventory[index][i].itemPrice * quantity;

                if (inventory[index][i].quantity <= 5 && inventory[index][i].quantity != 0) {
                    less.push_back(inventory[index][i]);
                } else if (inventory[index][i].quantity == 0) {
                    sparse.push_back(inventory[index][i]);
                }

                buyed.push_back(make_pair(name, quantity));
            }
        }
    }

    if (isAllOkay) {
        cout << endl << "Purchase successful!" << endl;
        cout << "Total Price: " << totalPrice << endl;
    } else {
        cout << endl << "Something went wrong. Please check the availability of the items." << endl;
    }
}

void buyingItems(vector<Item>& sparse, vector<Item>& less, vector<vector<Item>>& inventory, vector<string>& stores) {
    cout << endl << "Enter your name: ";
    string name;
    getline(cin, name);
    cout << endl << "Hi " << name << ". These are the Available Items in our Stores: " << endl;
    checkAvaliable(inventory);

    while (true) {
        cout << "1. For Buy" << endl << "2. For Exit" << endl;
        int num;
        cin >> num;
        if (num == 2) return;
        else {
            cout << "Enter the store index: " << endl;
            cin >> num;
            cout << "Enter the Item: " << endl;
            cin.ignore();
            getline(cin, name);
            int q;
            cout << "Enter the quantity: " << endl;
            cin >> q;

            vector<pair<string, int>> buyed;
            int totalPrice = 0;
            customerBuy(num, name, q, buyed, totalPrice, inventory, sparse, less);
        }
    }
}

void nonavailable(vector<Item> sparse) {
    for (auto it : sparse) {
        cout << it.storeName << " Rack no : " << it.rackNumber << " Item Name : " << it.itemName << endl;
    }
}

int main() {
    vector<vector<Item>> inventory;  
    vector<string> stores;
    vector<Item> sparse;
    vector<Item> less;

    while (true) {
        int num;
        cout << "Welcome to the Store Inventory System:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "Enter option: ";
        cin >> num;

        if (num == 1) {
            cout << "1. Add Store" << endl;
            cout << "2. Add Items" << endl;
            cout << "3. Shift Items" << endl;
            cout << "4. Check Available Items" << endl;
            cout << "5. Non-Available Items" << endl;
            cout << "6. Show Stores Names" << endl;
            cout << "0. Exit" << endl;
            cin >> num;

            if (num == 1) {
                addStore(inventory, stores);
            } else if (num == 2) {
                addItems(inventory, stores);
            } else if (num == 3) {
                shiftItems(inventory, stores);
            } else if (num == 4) {
                checkAvaliable(inventory);
            } else if (num == 5) {
                nonavailable(sparse);
            } else if (num == 6) {
                displayStores(stores);
            } else if (num == 0) {
                return 0;
            }
        } else if (num == 2) {
            buyingItems(sparse, less, inventory, stores);
        } else if (num == 0) {
            return 0;
        }
    }

    return 0;
}
