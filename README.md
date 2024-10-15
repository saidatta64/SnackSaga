# SnackSaga

SnackSaga is a console-based food ordering and management system implemented in C++. It provides functionality for administrators, users, and accountants to manage food items, place orders, and generate invoices.

## Features

- **User Roles**: Admin, User, and Accountant
- **Admin Functions**: 
  - View all food items
  - Search for specific food items
  - Add new users
  - Search for users
  - Add new food products
- **User Functions**:
  - View all food items
  - Search for specific food items
  - Place orders and generate bills
- **Accountant Functions**:
  - View all food items
  - Search for specific food items
  - Create invoices
- **Color-coded console interface** for better user experience
- **Input validation** to ensure data integrity

## Setup

1. Ensure you have a C++ compiler installed on your system.
2. Clone this repository or download the source code.
3. Compile the `DS.cpp` file using your C++ compiler.
   ```
   g++ DS.cpp -o SnackSaga
   ```
4. Run the compiled executable.
   ```
   ./SnackSaga
   ```

## Usage

Upon running the program, you'll be presented with a main menu:

1. Admin
2. User
3. Accountant
4. Help
5. Exit

Select the appropriate option and follow the on-screen prompts.

### Admin Login
- Username: Jayesh
- Password: 1234

### Accountant Login
- Username: Saidatta
- Password: 1234

### User Login
Users can log in with any of the following usernames:
- Prasad
- Pavani
- Shrihar
- Sanket
- Samay

## Project Structure

The project is contained in a single file `DS.cpp`, which includes all the necessary functions and data structures.

[A class diagram or system architecture diagram could be added here to visualize the structure of the program]

## Data Structures Used

- `struct Food`: Represents a food item with name, ID, price, and quantity.
- `struct Bill`: Represents a bill or invoice with customer details, items, and delivery information.
- `vector<Food>`: Used to store the food menu.
- `vector<string>`: Used to store user names.

## Future Improvements

- Implement data persistence (file I/O or database integration)
- Add more robust error handling and logging
- Implement a graphical user interface (GUI)
- Add unit tests for critical functions

## Contributing

Contributions to SnackSaga are welcome! Please feel free to submit a Pull Request.

## License

[Add your chosen license here]

## Contact

For support or queries, please contact: support@snacksaga.com
