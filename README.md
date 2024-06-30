# DSA-project--AdventureAccess
This is a C++ application that manages reservations for an amusement park. The system allows users to make, change, and delete reservations, as well as view guests for a specific date.

## Features

- **Make Reservation**: Add a new reservation for a specific date.
- **Change Reservation Date**: Modify the date of an existing reservation.
- **Delete Reservation**: Remove a reservation from the system.
- **View Guests**: Print the list of guests for a specific date.

## Requirements

- C++ compiler

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/amusement-park-reservation-system.git
   ```
2. **Navigate to the Project Directory**:
   ```bash
   cd amusement-park-reservation-system
   ```
3. **Compile the Code**:
   ```bash
   g++ -o reservation_system reservation_system.cpp
   ```
4. **Run the Application**:
   ```bash
   ./reservation_system
   ```

## Usage

The system reads input from a file named `amusement.dat`. The file should contain the following:

1. An integer representing the reservation limit per date.
2. A series of commands with the necessary data.

Example `amusement.dat` file content:
```
3
1 20240701 JohnDoe
1 20240701 JaneSmith
2 20240701 JohnDoe 20240702
3 20240701 JaneSmith
4 20240702
5
```

### Commands

- `1 date name`: Make a reservation for `name` on `date`.
- `2 old_date name new_date`: Change the reservation date for `name` from `old_date` to `new_date`.
- `3 date name`: Delete the reservation for `name` on `date`.
- `4 date`: Print the list of guests for `date`.
- `5`: Exit the program.

## File Structure

- `reservation_system.cpp`: Main program file.

## Functions

- `Node* create_node()`: Creates a new node for the linked list.
- `int count(int date)`: Counts the number of reservations for a specific date.
- `void print_guests(int date)`: Prints the list of guests for a specific date.
- `void enqueue(int date, const std::string& name)`: Adds a reservation to the queue.
- `void make_reservation()`: Reads data from the file and makes a reservation.
- `void change_date_reservation()`: Changes the date of an existing reservation.
- `void delete_reservation()`: Deletes a reservation.
- `int main()`: Main function that reads commands from the file and executes them.

## Example

Given the example `amusement.dat` file:
```
3
1 20240701 JohnDoe
1 20240701 JaneSmith
2 20240701 JohnDoe 20240702
3 20240701 JaneSmith
4 20240702
5
```

The program will:
1. Set the reservation limit to 3.
2. Make a reservation for JohnDoe on 20240701.
3. Make a reservation for JaneSmith on 20240701.
4. Change JohnDoe's reservation from 20240701 to 20240702.
5. Delete JaneSmith's reservation on 20240701.
6. Print the guests for 20240702 (output will be "20240702 : JohnDoe ").
7. Exit the program.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

- **GitHub**: [suchin kumar](https://github.com/Suchinkumar)
- **Email**: allifpotter@gmail.com

## Acknowledgements

- Thanks to the open-source community for providing valuable resources and tools.
