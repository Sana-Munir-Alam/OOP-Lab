#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class User {
    public:
        string user_id;
        string first_name;
        string last_name;
        string address;
        string email;

        User(string id, string fn, string ln, string addr, string mail) : user_id(id), first_name(fn), last_name(ln), address(addr), email(mail) {}

        string serialize() const {
            return user_id + "," + first_name + "," + last_name + "," + address + "," + email;
        }

        static User deserialize(const string& line) {
            stringstream ss(line);
            string id, fn, ln, addr, mail;
            getline(ss, id, ',');
            getline(ss, fn, ',');
            getline(ss, ln, ',');
            getline(ss, addr, ',');
            getline(ss, mail, ',');
            return User(id, fn, ln, addr, mail);
        }
};

class Product {
    public:
        string product_id;
        string product_name;
        string description;
        int price;

        Product(string id, string name, string desc, int pr) : product_id(id), product_name(name), description(desc), price(pr) {}

        string serialize() const {
            return product_id + "," + product_name + "," + description + "," + to_string(price);
        }

        static Product deserialize(const string& line) {
            stringstream ss(line);
            string id, name, desc, price_str;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, desc, ',');
            getline(ss, price_str, ',');
            return Product(id, name, desc, stoi(price_str));
        }
};

class Order {
    public:
        string order_id;
        string user_id;
        string product_id;
        int total_paid;

        Order(string oid, string uid, string pid, int tp) : order_id(oid), user_id(uid), product_id(pid), total_paid(tp) {}

        string serialize() const {
            return order_id + "," + user_id + "," + product_id + "," + to_string(total_paid);
        }

        static Order deserialize(const string& line) {
            stringstream ss(line);
            string oid, uid, pid, paid;
            getline(ss, oid, ',');
            getline(ss, uid, ',');
            getline(ss, pid, ',');
            getline(ss, paid, ',');
            return Order(oid, uid, pid, stoi(paid));
        }
};

void writeDummyData() {
    ofstream userFile("users.txt");
    userFile << User("U01", "Linus", "Richard", "Edward", "linus@linux.org").serialize() << endl;
    userFile << User("U02", "Ada", "Christopher", "Brandon", "ada@history.net").serialize() << endl;
    userFile.close();

    ofstream productFile("products.txt");
    productFile << Product("P01", "Kernel Book", "A deep dive into Linux", 500).serialize() << endl;
    productFile << Product("P02", "C++ Primer", "Guide to modern C++", 450).serialize() << endl;
    productFile.close();

    ofstream orderFile("orders.txt");
    orderFile << Order("O01", "U01", "P01", 500).serialize() << endl;
    orderFile << Order("O02", "U02", "P02", 450).serialize() << endl;
    orderFile.close();
}

vector<User> loadUsers() {
    vector<User> users;
    ifstream inFile("users.txt");
    string line;
    while (getline(inFile, line)) {
        users.push_back(User::deserialize(line));
    }
    return users;
}

vector<Product> loadProducts() {
    vector<Product> products;
    ifstream inFile("products.txt");
    string line;
    while (getline(inFile, line)) {
        products.push_back(Product::deserialize(line));
    }
    return products;
}

vector<Order> loadOrders() {
    vector<Order> orders;
    ifstream inFile("orders.txt");
    string line;
    while (getline(inFile, line)) {
        orders.push_back(Order::deserialize(line));
    }
    return orders;
}

void queryProductsByUser(const string& first_name) {
    vector<User> users = loadUsers();
    vector<Product> products = loadProducts();
    vector<Order> orders = loadOrders();

    string target_user_id = "";

    // Find user by first name
    for (const auto& user : users) {
        if (user.first_name == first_name) {
            target_user_id = user.user_id;
            break;
        }
    }

    if (target_user_id == "") {
        cout << "User not found!" << endl;
        return;
    }

    // Find orders by user
    vector<string> product_ids;
    for (const auto& order : orders) {
        if (order.user_id == target_user_id) {
            product_ids.push_back(order.product_id);
        }
    }

    // Link product IDs to names
    cout << "\nProducts purchased by " << first_name << ":\n";
    for (const auto& pid : product_ids) {
        for (const auto& product : products) {
            if (product.product_id == pid) {
                cout << "- " << product.product_name << endl;
            }
        }
    }
}

int main() {
    writeDummyData();

    string user_name = "Linus";
    queryProductsByUser(user_name);

    return 0;
}
