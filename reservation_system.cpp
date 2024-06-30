#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct Node {
    int date;
    std::string name;
    Node* next;
};

std::ifstream file;

int limit;

Node* queue_front = nullptr;
Node* queue_rear = nullptr;

Node* create_node();
int count(int date);
void print_guests(int date);
void enqueue(int date, const std::string& name);
void make_reservation();
void change_date_reservation();
void delete_reservation();

int main() {
    file.open("amusement.dat");

    if (!file) {
        std::cout << "FILE does not exist\n";
        return 1;
    }

    file >> limit;

    while (file) {
        int choice;
        file >> choice;
        switch (choice) {
            case 1:
                make_reservation();
                break;
            case 2:
                change_date_reservation();
                break;
            case 3:
                delete_reservation();
                break;
            case 4: {
                int date;
                file >> date;
                print_guests(date);
                break;
            }
            case 5:
                return 0;
            default:
                std::cout << "Code " << choice << " invalid\n";
        }
    }

    file.close();
    return 0;
}

Node* create_node() {
    Node* n = new Node;
    n->next = nullptr;
    return n;
}

int count(int date) {
    int ctr = 0;
    for (Node* temp = queue_front; temp != nullptr; temp = temp->next) {
        if (temp->date == date)
            ctr++;
    }
    return ctr;
}

void enqueue(int date, const std::string& name) {
    Node* new_node = create_node();
    new_node->date = date;
    new_node->name = name;
    new_node->next = nullptr;

    if (queue_front == nullptr) {
        queue_front = new_node;
        queue_rear = new_node;
    } else {
        queue_rear->next = new_node;
        queue_rear = new_node;
    }
}

void make_reservation() {
    int date_buf;
    std::string name_buf;

    file >> date_buf;
    file >> name_buf;

    if (count(date_buf) >= limit) {
        std::cout << "SORRY, QUOTA OVER\n";
    } else {
        enqueue(date_buf, name_buf);
    }
}

void change_date_reservation() {
    int old_date_buf, new_date_buf;
    std::string name_buf;

    file >> old_date_buf;
    file >> name_buf;
    file >> new_date_buf;

    for (Node* temp = queue_front; temp != nullptr; temp = temp->next) {
        if (temp->date == old_date_buf && temp->name == name_buf)
            temp->date = new_date_buf;
    }
}

void delete_reservation() {
    int date_buf;
    std::string name_buf;

    file >> date_buf;
    file >> name_buf;

    Node* temp = queue_front;
    Node* prev = nullptr;

    while (temp != nullptr && !(temp->date == date_buf && temp->name == name_buf)) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return; // Not found

    if (prev == nullptr) {
        // Deleting the front node
        queue_front = temp->next;
    } else {
        prev->next = temp->next;
    }

    if (temp == queue_rear) {
        queue_rear = prev;
    }

    delete temp;
}

void print_guests(int date) {
    int ctr = 0;
    std::cout << date << " : ";
    for (Node* temp = queue_front; temp != nullptr; temp = temp->next) {
        if (temp->date == date) {
            ctr++;
            std::cout << temp->name << " ";
        }
    }
    if (ctr == 0) {
        std::cout << "NO GUESTS";
    }
    std::cout << "\n";
}