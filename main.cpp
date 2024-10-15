#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

struct Food {
    string name;
    string id;
    double price;
    int quantity;
};

struct Bill {
    string billedTo;
    string invoiceNumber;
    string date;
    vector<Food> items;
    string packageType;
    string deliveryType;
    double deliveryCharge;
};

vector<Food> foodMenu;
vector<string> users = {"Prasad", "Pavani", "Shrihar", "Sanket", "Samay"};

void initializeMenu();
void mainMenu();
void adminLogin();
void adminMenu();
void userLogin();
void accountantLogin();
void displayFoodList(int callerMenu);
void searchFood(int callerMenu);
void addUser();
void searchUser();
void addProduct();
void userMenu();
void buyAndGenerateBill();
void accountantMenu();
void createInvoice();
void exitProgram();
void displayHelp();
void displayError();
int getValidIntInput();
double getValidDoubleInput();
string getValidStringInput();
int discount(double total);

int main() {
    initializeMenu();
    mainMenu();
    return 0;
}

void initializeMenu() {
    foodMenu = {
        {"Butter Cake", "11", 500, 50},
        {"Chocolate Cake", "12", 300, 50},
        {"Apple Cake", "13", 150, 50},
        {"Pol Cake", "14", 125, 50},
        {"Vegetable Roll", "15", 35, 50},
        {"Samosa", "16", 25, 50},
        {"Seeni Sambol Bun", "17", 30, 50},
        {"Fish Bun", "18", 45, 50},
        {"Egg Bun", "19", 30, 50},
        {"Chicken Cutlet", "20", 50, 50},
        {"Chicken Roll", "21", 60, 50},
        {"Egg Roll", "22", 40, 50},
        {"Chicken Pie", "23", 70, 50},
        {"Coffee", "25", 15, 50},
        {"Plain Tea", "26", 10, 50},
        {"Milk Tea", "29", 20, 50},
        {"Normal Package", "30", 70, 50},
        {"Super Package", "31", 100, 50}
    };
}

int getValidIntInput() {
    int input;
    while (true) {
        if (cin >> input) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setColor(12);
            cout << "\t\tInvalid input. Please enter a number: ";
            setColor(15);
        }
    }
}

double getValidDoubleInput() {
    double input;
    while (true) {
        if (cin >> input) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            setColor(12);
            cout << "\t\tInvalid input. Please enter a number: ";
            setColor(15);
        }
    }
}

string getValidStringInput() {
    string input;
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            return input;
        } else {
            setColor(12);
            cout << "\t\tInvalid input. Please enter a non-empty string: ";
            setColor(15);
        }
    }
}

void mainMenu() {
    system("cls");
    setColor(14);
    cout << "\n\t\t-----------------------------------------" << endl;
    cout << "\t\t-\t\tSnackSaga\t\t- " << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11);
    cout << "\t\t-\t1. Admin \t2. User\t\t-" << endl;
    cout << "\t\t-\t3. Accountant \t4. Help\t\t-" << endl;
    cout << "\t\t-\t5. Exit \t\t\t-" << endl;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\t\tEnter your choice: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: adminLogin(); break;
        case 2: userLogin(); break;
        case 3: accountantLogin(); break;
        case 4: displayHelp(); break;
        case 5: exitProgram(); break;
        default: displayError();
    }
}

void adminLogin() {
    system("cls");
    string username, password;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-            Admin Login                -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tUsername: ";
    username = getValidStringInput();
    cout << "\t\tPassword: ";
    password = getValidStringInput();

    if (username == "Jayesh" && password == "1234") {
        adminMenu();
    } else {
        setColor(12);
        cout << "\t\tInvalid credentials. Try again? (Y/N): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'Y' || choice == 'y') {
            adminLogin();
        } else {
            mainMenu();
        }
    }
}

void adminMenu() {
    system("cls");
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-       SnackSaga - Admin Menu       -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11);
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Search User     4. Add User     -" << endl;
    cout << "\t\t- 5. Add Product     6. Main Menu    -" << endl;
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    setColor(15);
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(1); break;
        case 2: searchFood(1); break;
        case 3: searchUser(); break;
        case 4: addUser(); break;
        case 5: addProduct(); break;
        case 6: mainMenu(); break;
        default: displayError();
    }
}

void userLogin() {
    system("cls");
    string username;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-            User Login                 -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tUsername: ";
    username = getValidStringInput();

    auto it = find(users.begin(), users.end(), username);
    if (it != users.end()) {
        userMenu();
    } else {
        setColor(12);
        cout << "\t\tUser not found. Try again? (Y/N): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'Y' || choice == 'y') {
            userLogin();
        } else {
            mainMenu();
        }
    }
}

void accountantLogin() {
    system("cls");
    string username, password;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-         Accountant Login              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tUsername: ";
    username = getValidStringInput();
    cout << "\t\tPassword: ";
    password = getValidStringInput();

    if (username == "Saidatta" && password == "1234") {
        accountantMenu();
    } else {
        setColor(12);
        cout << "\t\tInvalid credentials. Try again? (Y/N): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 'Y' || choice == 'y') {
            accountantLogin();
        } else {
            mainMenu();
        }
    }
}

void displayFoodList(int callerMenu) {
    system("cls");
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Food Menu List              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11);
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price";
    if (callerMenu == 1 || callerMenu == 3) {
        cout << setw(10) << "Quantity";
    }
    cout << endl;
    setColor(15);
    for (const auto& food : foodMenu) {
        cout << setw(5) << food.id << setw(20) << food.name << setw(10) << food.price;
        if (callerMenu == 1 || callerMenu == 3) {
            cout << setw(10) << food.quantity;
        }
        cout << endl;
    }
    setColor(14);
    cout << "\n\t\tPress any key to return to the previous menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    switch (callerMenu) {
        case 1: adminMenu(); break;
        case 2: userMenu(); break;
        case 3: accountantMenu(); break;
        default: mainMenu();
    }
}

void searchFood(int callerMenu) {
    system("cls");
    string searchTerm;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Search Food Item            -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tEnter food name or ID to search: ";
    searchTerm = getValidStringInput();

    auto it = find_if(foodMenu.begin(), foodMenu.end(), [&searchTerm](const Food& food) {
        return food.name == searchTerm || food.id == searchTerm;
    });

    if (it != foodMenu.end()) {
        setColor(10);
        cout << "\n\t\tFood Item Found:" << endl;
        cout << "\t\tID: " << it->id << endl;
        cout << "\t\tName: " << it->name << endl;
        cout << "\t\tPrice: " << it->price << endl;
        if (callerMenu == 1 || callerMenu == 3) {
            cout << "\t\tQuantity: " << it->quantity << endl;
        }
    } else {
        setColor(12);
        cout << "\n\t\tFood item not found." << endl;
    }

    setColor(14);
    cout << "\n\t\tPress any key to return to the previous menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    switch (callerMenu) {
        case 1: adminMenu(); break;
        case 2: userMenu(); break;
        case 3: accountantMenu(); break;
        default: mainMenu();
    }
}

void addUser() {
    system("cls");
    string newUser;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-             Add New User              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tEnter new username: ";
    newUser = getValidStringInput();

    if (std::find(users.begin(), users.end(), newUser) == users.end()) {
        users.push_back(newUser);
        setColor(10);
        cout << "\n\t\tUser added successfully!" << endl;
    } else {
        setColor(12);
        cout << "\n\t\tUser already exists!" << endl;
    }

    setColor(14);
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void searchUser() {
    system("cls");
    string searchTerm;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-             Search User               -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tEnter username to search: ";
    searchTerm = getValidStringInput();

    auto it = find(users.begin(), users.end(), searchTerm);
    if (it != users.end()) {
        setColor(10);
        cout << "\n\t\tUser found: " << *it << endl;
    } else {
        setColor(12);
        cout << "\n\t\tUser not found." << endl;
    }

    setColor(14);
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void addProduct() {
    system("cls");
    Food newFood;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Add New Product             -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    setColor(15);
    cout << "\t\tEnter product name: ";
    newFood.name = getValidStringInput();
    cout << "\t\tEnter product ID: ";
    newFood.id = getValidStringInput();
    cout << "\t\tEnter product price: ";
    newFood.price = getValidDoubleInput();
    cout << "\t\tEnter product quantity: ";
    newFood.quantity = getValidIntInput();

    foodMenu.push_back(newFood);
    setColor(10);
    cout << "\n\t\tProduct added successfully!" << endl;

    setColor(14);
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void userMenu() {
    system("cls");
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-       SnackSaga - User Menu        -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11);
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Buy and Generate Bill           -" << endl;
    cout << "\t\t- 4. Main Menu                       -" << endl;
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    setColor(15);
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(2); break;
        case 2: searchFood(2); break;
        case 3: buyAndGenerateBill(); break;
        case 4: mainMenu(); break;
        default: displayError();
    }
}

int discount(double total) {
    if (total > 500) {
        return 20;
    } 
    else if(total > 250){
        return 15;
    }
    else if(total > 200){
        return 10;
    }
    else if(total > 100){
        return 5;
    }
    else{
        return 0;
    }
}

void buyAndGenerateBill() {
    system("cls");
    Bill newBill;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-       Buy and Generate Bill           -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tEnter customer name: ";
    newBill.billedTo = getValidStringInput();
    cout << "\t\tEnter invoice number: ";
    newBill.invoiceNumber = getValidStringInput();
    cout << "\t\tEnter date (DD/MM/YYYY): ";
    newBill.date = getValidStringInput();

    char addMore;
    do {
        string itemIdentifier;
        cout << "\n\t\tEnter item name or ID to add to bill: ";
        itemIdentifier = getValidStringInput();

        auto it = find_if(foodMenu.begin(), foodMenu.end(), [&itemIdentifier](const Food& f) { 
            return f.id == itemIdentifier || f.name == itemIdentifier; 
        });
        if (it != foodMenu.end()) {
            int quantity;
            cout << "\t\tEnter quantity: ";
            quantity = getValidIntInput();
            if (quantity <= it->quantity) {
                Food billItem = *it;
                billItem.quantity = quantity;
                newBill.items.push_back(billItem);
                it->quantity -= quantity;
                setColor(10);
                cout << "\t\tItem added to bill." << endl;
            } else {
                setColor(12);
                cout << "\t\tInsufficient quantity in stock. Available: " << it->quantity << endl;
            }
        } else {
            setColor(12);
            cout << "\t\tItem not found or out of stock." << endl;
        }

        setColor(15);
        cout << "\t\tAdd more items? (Y/N): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (addMore == 'Y' || addMore == 'y');

    setColor(15);
    cout << "\n\t\tChoose package type:" << endl;
    cout << "\t\t1. Normal Package" << endl;
    cout << "\t\t2. Super Package" << endl;
    cout << "\t\tEnter your choice (1 or 2): ";
    int packageChoice = getValidIntInput();
    newBill.packageType = (packageChoice == 1) ? "Normal Package" : "Super Package";

    cout << "\n\t\tChoose delivery type:" << endl;
    cout << "\t\t1. Standard Delivery (Rs. 50)" << endl;
    cout << "\t\t2. Express Delivery (Rs. 100)" << endl;
    cout << "\t\tEnter your choice (1 or 2): ";
    int deliveryChoice = getValidIntInput();
    if (deliveryChoice == 1) {
        newBill.deliveryType = "Standard Delivery";
        newBill.deliveryCharge = 50.0;
    } else {
        newBill.deliveryType = "Express Delivery";
        newBill.deliveryCharge = 100.0;
    }

    system("cls");
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Bill                    -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tCustomer: " << newBill.billedTo << endl;
    cout << "\t\tInvoice Number: " << newBill.invoiceNumber << endl;
    cout << "\t\tDate: " << newBill.date << endl;
    cout << "\t\tPackage Type: " << newBill.packageType << endl;
    cout << "\t\tDelivery Type: " << newBill.deliveryType << endl;
    setColor(11);
    cout << "\n\t\tItems:" << endl;
    cout << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;

    double total = 0;
    setColor(15);
    for (const auto& item : newBill.items) {
        double itemTotal = item.price * item.quantity;
        cout << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << itemTotal << endl;
        total += itemTotal;
    }

    setColor(10);
    cout << "\n\t\tSubtotal: " << total << endl;
    cout << "\t\tDelivery Charge: " << newBill.deliveryCharge << endl;
    double grandTotal = total + newBill.deliveryCharge;
    int dis = discount(grandTotal);
    cout << "\t\tDiscount: " << dis <<" % "<< endl;
    grandTotal = grandTotal - (grandTotal * dis / 100);
    cout << "\t\tGrand Total: " << grandTotal << endl;
    setColor(14);
    cout << "\n\t\tPress any key to return to user menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    userMenu();
}

void accountantMenu() {
    system("cls");
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-    SnackSaga - Accountant Menu     -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11);
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Create Invoice  4. Main Menu    -" << endl;
    setColor(14);
    cout << "\t\t--------------------------------------" << endl;
    setColor(15);
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(3); break;
        case 2: searchFood(3); break;
        case 3: createInvoice(); break;
        case 4: mainMenu(); break;
        default: displayError();
    }
}

void createInvoice() {
    system("cls");
    Bill newInvoice;
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Create Invoice              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tEnter customer name: ";
    newInvoice.billedTo = getValidStringInput();
    cout << "\t\tEnter invoice number: ";
    newInvoice.invoiceNumber = getValidStringInput();
    cout << "\t\tEnter date (DD/MM/YYYY): ";
    newInvoice.date = getValidStringInput();

    char addMore;
    do {
        string itemIdentifier;
        cout << "\n\t\tEnter item name or ID to add to invoice: ";
        itemIdentifier = getValidStringInput();

        auto it = find_if(foodMenu.begin(), foodMenu.end(), [&itemIdentifier](const Food& f) { 
            return f.id == itemIdentifier || f.name == itemIdentifier; 
        });
        if (it != foodMenu.end()) {
            int quantity;
            cout << "\t\tEnter quantity: ";
            quantity = getValidIntInput();
            if (quantity <= it->quantity) {
                Food invoiceItem = *it;
                invoiceItem.quantity = quantity;
                newInvoice.items.push_back(invoiceItem);
                it->quantity -= quantity;
                setColor(10);
                cout << "\t\tItem added to invoice." << endl;
            } else {
                setColor(12);
                cout << "\t\tInsufficient quantity in stock. Available: " << it->quantity << endl;
            }
        } else {
            setColor(12);
            cout << "\t\tItem not found or out of stock." << endl;
        }

        setColor(15);
        cout << "\t\tAdd more items? (Y/N): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (addMore == 'Y' || addMore == 'y');

    setColor(15);
    cout << "\n\t\tChoose package type:" << endl;
    cout << "\t\t1. Normal Package" << endl;
    cout << "\t\t2. Super Package" << endl;
    cout << "\t\tEnter your choice (1 or 2): ";
    int packageChoice = getValidIntInput();
    newInvoice.packageType = (packageChoice == 1) ? "Normal Package" : "Super Package";

    cout << "\n\t\tChoose delivery type:" << endl;
    cout << "\t\t1. Standard Delivery (Rs. 50)" << endl;
    cout << "\t\t2. Express Delivery (Rs. 100)" << endl;
    cout << "\t\tEnter your choice (1 or 2): ";
    int deliveryChoice = getValidIntInput();
    if (deliveryChoice == 1) {
        newInvoice.deliveryType = "Standard Delivery";
        newInvoice.deliveryCharge = 50.0;
    } else {
        newInvoice.deliveryType = "Express Delivery";
        newInvoice.deliveryCharge = 100.0;
    }

    system("cls");
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Invoice                 -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15);
    cout << "\t\tCustomer: " << newInvoice.billedTo << endl;
    cout << "\t\tInvoice Number: " << newInvoice.invoiceNumber << endl;
    cout << "\t\tDate: " << newInvoice.date << endl;
    cout << "\t\tPackage Type: " << newInvoice.packageType << endl;
    cout << "\t\tDelivery Type: " << newInvoice.deliveryType << endl;
    setColor(11);
    cout << "\n\t\tItems:" << endl;
    cout << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;

    double total = 0;
    setColor(15);
    for (const auto& item : newInvoice.items) {
        double itemTotal = item.price * item.quantity;
        cout << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << itemTotal << endl;
        total += itemTotal;
    }

    setColor(10);
    cout << "\n\t\tSubtotal: " << total << endl;
    cout << "\t\tDelivery Charge: " << newInvoice.deliveryCharge << endl;
    double tax = total * 0.18;
    double grandTotal = total + tax + newInvoice.deliveryCharge;

    cout << "\t\tTax (10%): " << tax << endl;
    cout << "\t\tGrand Total: " << grandTotal << endl;

    setColor(14);
    cout << "\n\t\tPress any key to return to accountant menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    accountantMenu();
}

void exitProgram() {
    system("cls");
    setColor(14);
    cout << "\n\t\tThank you for using SnackSaga. Goodbye!....Do Visit Again" << endl;
    setColor(15);
    exit(0);
}

void displayHelp() {
    system("cls");
    setColor(14);
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Help Menu               -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11);
    cout << "\t\t1. Admin: Manage items and users" << endl;
    cout << "\t\t2. User: View items and buy products" << endl;
    cout << "\t\t3. Accountant: View items and create invoices" << endl;
    cout << "\t\t4. For technical support, contact: support@snacksaga.com" << endl;
    setColor(14);
    cout << "\n\t\tPress any key to return to main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    mainMenu();
}

void displayError() {
    system("cls");
    setColor(12);
    cout << "\t-----------------------------------------------------------------" << endl;
    cout << "\t-                           ERROR!!!                            -" << endl;
    cout << "\t-----------------------------------------------------------------" << endl;
    cout << "\t                        Invalid Entry!                           " << endl;
    cout << "\t-----------------------------------------------------------------" << endl;
    setColor(14);
    cout << "\t\tPress any key to return to the main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    mainMenu();
}
