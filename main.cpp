#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm> // Add this for std::find and std::find_if
#include <windows.h> // Add this for Windows console colors

using namespace std;

// Function to set console text color
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
};

vector<Food> foodMenu;
vector<string> users = {"Prasad", "Pavani", "Shrihar", "Sanket", "Samay"};

void initializeMenu();
void mainMenu();
void adminLogin();
void adminMenu();
void userLogin();
void accountantLogin();
void displayFoodList();
void searchFood();
void addUser();
void searchUser();
void addProduct();
void userMenu();
void generateBill();
void accountantMenu();
void createInvoice();
void exitProgram();
void displayHelp();
void displayError();
int getValidIntInput(); // Function to check for valid integer input
double getValidDoubleInput(); // Function to check for valid double input
string getValidStringInput(); // Function to check for valid string input

int main() {
    initializeMenu();
    mainMenu();
    return 0;
}

void initializeMenu() {
    foodMenu = {
        {"Butter Cake", "11", 1500, 50},
        {"Chocolate Cake", "12", 3000, 50},
        {"Apple Cake", "13", 1000, 50},
        {"Pol Cake", "14", 1250, 50},
        {"Vegetable Roll", "15", 50, 50},
        {"Samosa", "16", 50, 50},
        {"Seeni Sambol Bun", "17", 50, 50},
        {"Fish Bun", "18", 50, 50},
        {"Egg Bun", "19", 50, 50},
        {"Chicken Cutlet", "20", 50, 50},
        {"Chicken Roll", "21", 60, 50},
        {"Egg Roll", "22", 45, 50},
        {"Chicken Pie", "23", 70, 50},
        {"Beer", "24", 150, 50},
        {"Coffee", "25", 15, 50},
        {"Plain Tea", "26", 10, 50},
        {"Milk Tea", "29", 20, 50},
        {"Normal Package", "30", 15000, 50},
        {"Super Package", "31", 20000, 50}
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
            setColor(12); // Light Red
            cout << "\t\tInvalid input. Please enter a number: ";
            setColor(15); // White
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
            setColor(12); // Light Red
            cout << "\t\tInvalid input. Please enter a number: ";
            setColor(15); // White
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
            setColor(12); // Light Red
            cout << "\t\tInvalid input. Please enter a non-empty string: ";
            setColor(15); // White
        }
    }
}

void mainMenu() {
    system("cls");
    setColor(14); // Yellow
    cout << "\n\t\t-----------------------------------------" << endl;
    cout << "\t\t-\t\tSnackSaga\t\t- " << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << "\t\t-\t1. Admin \t2. User\t\t-" << endl;
    cout << "\t\t-\t3. Accountant \t4. Help\t\t-" << endl;
    cout << "\t\t-\t5. Exit \t\t\t-" << endl;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
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
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-            Admin Login                -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tUsername: ";
    username = getValidStringInput();
    cout << "\t\tPassword: ";
    password = getValidStringInput();

    if (username == "Jayesh" && password == "1234") {
        adminMenu();
    } else {
        setColor(12); // Light Red
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
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-       SnackSaga - Admin Menu       -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Search User     4. Add User     -" << endl;
    cout << "\t\t- 5. Add Product     6. Main Menu    -" << endl;
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(); break;
        case 2: searchFood(); break;
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
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-            User Login                 -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tUsername: ";
    username = getValidStringInput();

    auto it = find(users.begin(), users.end(), username);
    if (it != users.end()) {
        userMenu();
    } else {
        setColor(12); // Light Red
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
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-         Accountant Login              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tUsername: ";
    username = getValidStringInput();
    cout << "\t\tPassword: ";
    password = getValidStringInput();

    if (username == "Saidatta" && password == "1234") {
        accountantMenu();
    } else {
        setColor(12); // Light Red
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

void displayFoodList() {
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Food Menu List              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    setColor(15); // White
    for (const auto& food : foodMenu) {
        cout << setw(5) << food.id << setw(20) << food.name << setw(10) << food.price << endl;
    }
    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to the previous menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    // This function is called from multiple menus, so we need to determine which menu to return to
    if (cin.rdbuf()->in_avail() == 0) {  // Check if input buffer is empty
        accountantMenu();  // Return to accountant menu if called from there
    } else {
        userMenu();  // Otherwise, return to user menu
    }
}

void searchFood() {
    system("cls");
    string searchTerm;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Search Food Item            -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter food name or ID to search: ";
    searchTerm = getValidStringInput();

    auto it = find_if(foodMenu.begin(), foodMenu.end(), [&searchTerm](const Food& food) {
        return food.name == searchTerm || food.id == searchTerm;
    });

    if (it != foodMenu.end()) {
        setColor(10); // Light Green
        cout << "\n\t\tFood Item Found:" << endl;
        cout << "\t\tID: " << it->id << endl;
        cout << "\t\tName: " << it->name << endl;
        cout << "\t\tPrice: " << it->price << endl;
    } else {
        setColor(12); // Light Red
        cout << "\n\t\tFood item not found." << endl;
    }

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to user menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    userMenu();
}

void addUser() {
    system("cls");
    string newUser;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-             Add New User              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter new username: ";
    newUser = getValidStringInput();

    if (std::find(users.begin(), users.end(), newUser) == users.end()) {
        users.push_back(newUser);
        setColor(10); // Light Green
        cout << "\n\t\tUser added successfully!" << endl;
    } else {
        setColor(12); // Light Red
        cout << "\n\t\tUser already exists!" << endl;
    }

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void searchUser() {
    system("cls");
    string searchTerm;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-             Search User               -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter username to search: ";
    searchTerm = getValidStringInput();

    auto it = find(users.begin(), users.end(), searchTerm);
    if (it != users.end()) {
        setColor(10); // Light Green
        cout << "\n\t\tUser found: " << *it << endl;
    } else {
        setColor(12); // Light Red
        cout << "\n\t\tUser not found." << endl;
    }

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void addProduct() {
    system("cls");
    Food newFood;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Add New Product             -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter product name: ";
    newFood.name = getValidStringInput();
    cout << "\t\tEnter product ID: ";
    newFood.id = getValidStringInput();
    cout << "\t\tEnter product price: ";
    newFood.price = getValidDoubleInput();
    cout << "\t\tEnter product quantity: ";
    newFood.quantity = getValidIntInput();

    foodMenu.push_back(newFood);
    setColor(10); // Light Green
    cout << "\n\t\tProduct added successfully!" << endl;

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to admin menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    adminMenu();
}

void userMenu() {
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-       SnackSaga - User Menu        -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Generate Bill   4. Main Menu    -" << endl;
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(); break;
        case 2: searchFood(); break;
        case 3: generateBill(); break;
        case 4: mainMenu(); break;
        default: displayError();
    }
}

void generateBill() {
    system("cls");
    Bill newBill;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Generate Bill               -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter customer name: ";
    newBill.billedTo = getValidStringInput();
    cout << "\t\tEnter invoice number: ";
    newBill.invoiceNumber = getValidStringInput();
    cout << "\t\tEnter date (DD/MM/YYYY): ";
    newBill.date = getValidStringInput();

    char addMore;
    do {
        string itemId;
        cout << "\n\t\tEnter item ID to add to bill: ";
        itemId = getValidStringInput();

        auto it = find_if(foodMenu.begin(), foodMenu.end(), [&itemId](const Food& f) { return f.id == itemId; });
        if (it != foodMenu.end()) {
            int quantity;
            cout << "\t\tEnter quantity: ";
            quantity = getValidIntInput();
            if (quantity <= it->quantity) {
                Food billItem = *it;
                billItem.quantity = quantity;
                newBill.items.push_back(billItem);
                it->quantity -= quantity;
                setColor(10); // Light Green
                cout << "\t\tItem added to bill." << endl;
            } else {
                setColor(12); // Light Red
                cout << "\t\tInsufficient quantity in stock." << endl;
            }
        } else {
            setColor(12); // Light Red
            cout << "\t\tItem not found." << endl;
        }

        setColor(15); // White
        cout << "\t\tAdd more items? (Y/N): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (addMore == 'Y' || addMore == 'y');

    // Display the bill
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Bill                    -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tCustomer: " << newBill.billedTo << endl;
    cout << "\t\tInvoice Number: " << newBill.invoiceNumber << endl;
    cout << "\t\tDate: " << newBill.date << endl;
    setColor(11); // Light Cyan
    cout << "\n\t\tItems:" << endl;
    cout << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;

    double total = 0;
    setColor(15); // White
    for (const auto& item : newBill.items) {
        double itemTotal = item.price * item.quantity;
        cout << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << itemTotal << endl;
        total += itemTotal;
    }

    setColor(10); // Light Green
    cout << "\n\t\tTotal Amount: " << total << endl;

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to user menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    userMenu();
}

void accountantMenu() {
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    cout << "\t\t-    SnackSaga - Accountant Menu     -" << endl;
    cout << "\t\t--------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << "\t\t- 1. View all items  2. Search Items -" << endl;
    cout << "\t\t- 3. Create Invoice  4. Main Menu    -" << endl;
    setColor(14); // Yellow
    cout << "\t\t--------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\t Enter your option: ";

    int choice = getValidIntInput();

    switch (choice) {
        case 1: displayFoodList(); break;
        case 2: searchFood(); break;
        case 3: createInvoice(); break;
        case 4: mainMenu(); break;
        default: displayError();
    }
}

void createInvoice() {
    system("cls");
    Bill newInvoice;
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-           Create Invoice              -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tEnter customer name: ";
    newInvoice.billedTo = getValidStringInput();
    cout << "\t\tEnter invoice number: ";
    newInvoice.invoiceNumber = getValidStringInput();
    cout << "\t\tEnter date (DD/MM/YYYY): ";
    newInvoice.date = getValidStringInput();

    char addMore;
    do {
        string itemId;
        cout << "\n\t\tEnter item ID to add to invoice: ";
        itemId = getValidStringInput();

        auto it = find_if(foodMenu.begin(), foodMenu.end(), [&itemId](const Food& f) { return f.id == itemId; });
        if (it != foodMenu.end()) {
            int quantity;
            cout << "\t\tEnter quantity: ";
            quantity = getValidIntInput();
            if (quantity <= it->quantity) {
                Food invoiceItem = *it;
                invoiceItem.quantity = quantity;
                newInvoice.items.push_back(invoiceItem);
                it->quantity -= quantity;
                setColor(10); // Light Green
                cout << "\t\tItem added to invoice." << endl;
            } else {
                setColor(12); // Light Red
                cout << "\t\tInsufficient quantity in stock." << endl;
            }
        } else {
            setColor(12); // Light Red
            cout << "\t\tItem not found." << endl;
        }

        setColor(15); // White
        cout << "\t\tAdd more items? (Y/N): ";
        cin >> addMore;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (addMore == 'Y' || addMore == 'y');

    // Display the invoice
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Invoice                 -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(15); // White
    cout << "\t\tCustomer: " << newInvoice.billedTo << endl;
    cout << "\t\tInvoice Number: " << newInvoice.invoiceNumber << endl;
    cout << "\t\tDate: " << newInvoice.date << endl;
    setColor(11); // Light Cyan
    cout << "\n\t\tItems:" << endl;
    cout << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;

    double total = 0;
    setColor(15); // White
    for (const auto& item : newInvoice.items) {
        double itemTotal = item.price * item.quantity;
        cout << setw(20) << item.name << setw(10) << item.price << setw(10) << item.quantity << setw(10) << itemTotal << endl;
        total += itemTotal;
    }

    setColor(10); // Light Green
    cout << "\n\t\tTotal Amount: " << total << endl;

    // Additional accounting details
    double tax = total * 0.1; // Assuming 10% tax
    double grandTotal = total + tax;

    cout << "\t\tTax (10%): " << tax << endl;
    cout << "\t\tGrand Total: " << grandTotal << endl;

    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to accountant menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    accountantMenu();
}

void exitProgram() {
    system("cls");
    setColor(14); // Yellow
    cout << "\n\t\tThank you for using SnackSaga. Goodbye!....Do Visit Again" << endl;
    setColor(15); // White
    exit(0);
}

void displayHelp() {
    system("cls");
    setColor(14); // Yellow
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-               Help Menu               -" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    setColor(11); // Light Cyan
    cout << "\t\t1. Admin: Manage items and users" << endl;
    cout << "\t\t2. User: View items and generate bills" << endl;
    cout << "\t\t3. Accountant: View items and create invoices" << endl;
    cout << "\t\t4. For technical support, contact: support@snacksaga.com" << endl;
    setColor(14); // Yellow
    cout << "\n\t\tPress any key to return to main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    mainMenu();
}

void displayError() {
    system("cls");
    setColor(12); // Light Red
    cout << "\t-----------------------------------------------------------------" << endl;
    cout << "\t-                           ERROR!!!                            -" << endl;
    cout << "\t-----------------------------------------------------------------" << endl;
    cout << "\t                        Invalid Entry!                           " << endl;
    cout << "\t-----------------------------------------------------------------" << endl;
    setColor(14); // Yellow
    cout << "\t\tPress any key to return to the main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    mainMenu();
}
