#include <bits/stdc++.h>
using namespace std;
struct Restarunt {
    string rname;
    vector<pair<string, double>> menu; 

    Restarunt(string name) {
        rname = name;
    }
};
struct Apps {
    string appName;
    Apps* next = nullptr;
    vector<Restarunt*> res; 

    Apps(string appName) {
        this->appName = appName;
    }
};

class Functions {
public:
    string customerName;
    string streetName;
    string mainAddress;
    long long pincode;
    double totalPrice = 0;
    vector<pair<string, int>> allItems;

    Functions(string appName, double price, vector<pair<string, int>> item) {
        cout << "                 Welcome to " << appName << endl;
        string name, sname, mname;
        long long pcode;
        cout << "Enter your Name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter the street Name: ";
        getline(cin, sname);

        cout << "Enter the main address with house no and remaining: ";
        getline(cin, mname);

        cout << "Enter the pincode: ";
        cin >> pcode;

        customerName = name;
        streetName = sname;
        mainAddress = mname;
        pincode = pcode;
        totalPrice = price;
        allItems = item;
    }
};
void insertionRes(string appName, string reName, Apps* apps) {
    Apps* ap = apps;
    while (ap != nullptr && ap->appName != appName) {
        ap = ap->next;
    }

    if (ap == nullptr) {
        cout << "App not found!" << endl;
        return ;
    }
    Restarunt* newnode = new Restarunt(reName);

    bool run = true;
    cout << "\n                Enter the Menu for " << reName << endl;

    while (run) {
        cout << "1. Add item\n2. Exit\n";
        int data;
        cin >> data;

        if (data == 1) {
            cout << "Enter the item name: ";
            cin.ignore(); 
            string itemName;
            getline(cin, itemName);

            cout << "Enter the price of " << itemName << ": ";
            double price;
            cin >> price;
            newnode->menu.push_back({itemName, price});
        } else {
            run = false; 
        }
    }
    ap->res.push_back(newnode);
}
void createApp(string appName, Apps*& apps) {
    Apps* newnode = new Apps(appName);

    if (apps == nullptr) {
        apps = newnode;
    } else {
        Apps* temp = apps;
        while (temp->next != nullptr) {
            temp = temp->next; 
        }
        temp->next = newnode; 
    }
}
void displayAppsAndMenus(Apps* apps) {
    Apps* currentApp = apps;
    while (currentApp != nullptr) {
        cout << "App Name: " << currentApp->appName << endl;

        for (Restarunt* restaurant : currentApp->res) {
            cout << "  Restaurant: " << restaurant->rname << endl;
            cout << "    Menu:" << endl;
            for (const auto& item : restaurant->menu) {
                cout << "      Item: " << item.first << ", Price: " << item.second << endl;
            }
        }
        currentApp = currentApp->next;
        cout << endl;
    }
}
void display(Apps* apps) {
    Apps* temp = apps;
    if (apps == nullptr) {
        cout << endl << "No apps still added" << endl;
    } else {
        cout << "The Apps available are: " << endl;
        while (temp != nullptr) {
            cout << temp->appName << endl;
            temp = temp->next;
        }
    }
}

void displayItems(Apps* app, string rname) {
    for (Restarunt* r : app->res) {
        if (r->rname == rname) {
            cout << "\nMenu for " << rname << ":" << endl;
            for (auto& item : r->menu) {
                cout << "Item: " << item.first << ", Price: " << item.second << endl;
            }
        }
    }
}

bool findItem(Restarunt* res, string name) {
    for (auto it : res->menu) {
        if (it.first == name) {
            return true;
        }
    }
    return false;
}
double getPrice(Restarunt* res, string name) {
    for (auto it : res->menu) {
        if (it.first == name) {
            return it.second;
        }
    }
    return 0;
}
void makeOrder(Apps* apps, vector<Functions>& customers) {
    double totalPrice = 0;
    vector<pair<string, int>> orderedItems;  
    Apps* appNode = apps;

    cout << "Enter the app Name: ";
    string aname;
    cin.ignore();
    getline(cin, aname);

    while (appNode != nullptr && appNode->appName != aname) {
        appNode = appNode->next;
    }

    if (appNode == nullptr) {
        cout << "!!!!! Please enter a correct app name" << endl;
    } else {
        string rname;
        cout << "Enter the restaurant name: ";
        getline(cin, rname);
        displayItems(appNode, rname);

        while (true) {
            cout << "Enter the Item (or type 'exit' to finish): ";
            string item;
            getline(cin, item);

            if (item == "exit") {
                break;
            }

            cout << "Enter the quantity: ";
            int quantity;
            cin >> quantity;
            cin.ignore(); 

            Restarunt* selectedRestaurant = nullptr;
            for (Restarunt* r : appNode->res) {
                if (r->rname == rname) {
                    selectedRestaurant = r;
                    break;
                }
            }

            if (selectedRestaurant && findItem(selectedRestaurant, item)) {
                double itemPrice = getPrice(selectedRestaurant, item);
                totalPrice += itemPrice * quantity;
                orderedItems.push_back({item, quantity});
                cout << "Added " << item << " with quantity " << quantity << " to your order." << endl;
            } else {
                cout << "Item not found in the menu." << endl;
            }
        }
        cout << "\nYour Order Summary:" << endl;
        for (const auto& orderedItem : orderedItems) {
            cout << "Item: " << orderedItem.first << ", Quantity: " << orderedItem.second << endl;
        }
        cout << "Total Price: " << totalPrice << endl;
        Functions customer(aname, totalPrice, orderedItems);
        customers.push_back(customer);
        cout << endl << "Your order has been placed successfully!" << endl;
    }
}
void displayOrderData(const vector<Functions>& customers) {
    for (const auto& customer : customers) {
        cout << "Customer Name: " << customer.customerName << endl;
        cout << "Address: " << customer.streetName << ", " << customer.mainAddress << endl;
        cout << "Total Price: " << customer.totalPrice << endl;

        cout << "Items Ordered:" << endl;
        for (const auto& item : customer.allItems) {
            cout << "Item: " << item.first << ", Quantity: " << item.second << endl;
        }
        cout << endl;
    }
}

void deleteApp(Apps*& apps) {
    cout << "Enter the App name to delete: ";
    string name;
    cin.ignore();
    getline(cin, name);

    Apps* temp = apps;
    Apps* prev = nullptr;
    if (temp == nullptr) {
        cout << "No apps available to delete." << endl;
        return;
    }

    if (temp != nullptr && temp->appName == name) {
        apps = temp->next; 
        delete temp; 
        cout << "App deleted successfully." << endl;
        return;
    }
    while (temp != nullptr && temp->appName != name) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "App not found." << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "App deleted successfully." << endl;
}
void deleteRes(Apps* apps) {
    cout << "Enter the app name: ";
    string appName;
    cin.ignore();
    getline(cin, appName);

    Apps* app = apps;
    while (app != nullptr && app->appName != appName) {
        app = app->next;
    }

    if (app == nullptr) {
        cout << "App not found!" << endl;
        return;
    }

    cout << "Enter the restaurant name: ";
    string restaurantName;
    getline(cin, restaurantName);
    Restarunt* resToDelete = nullptr;
    for (auto it = app->res.begin(); it != app->res.end(); ++it) {
        if ((*it)->rname == restaurantName) {
            resToDelete = *it;
            app->res.erase(it);
            delete resToDelete; 
            cout << "Restaurant deleted successfully." << endl;
            return;
        }
    }

    cout << "Restaurant not found." << endl;
}
int main() {
    Apps* apps = nullptr; 
    vector<Functions> customers;

    while (true) {
        cout << "1. Admin\n2. Customer\n";
        int a;
        cin >> a;
        if (a == 1) {
            cout << "1. Adding App\n2. Adding Restaurant & Menu\n3. Display Apps & Menus\n4. Orders Details\n5. Delete App\n6. Delete Restaurant\n0. Exit\n";
            int data;
            cin >> data;

            if (data == 1) {
                string appName;
                cout << "Enter the App name: ";
                cin.ignore();
                getline(cin, appName);
                createApp(appName, apps);
            } else if (data == 2) {
                string appName, restaurantName;
                cout << "Enter the app name: ";
                cin.ignore();
                getline(cin, appName);
                cout << "Enter the restaurant name: ";
                getline(cin, restaurantName);
                insertionRes(appName, restaurantName, apps);
            } else if (data == 3) {
                displayAppsAndMenus(apps);
            } else if (data == 4) {
                displayOrderData(customers);
            } else if (data == 5) {
                deleteApp(apps);
            } else if (data == 6) {
                deleteRes(apps);
            } else if (data == 0) {
                break;
            }
        } else if (a == 2) {
            makeOrder(apps, customers);
        }
    }
    return 0;
}
