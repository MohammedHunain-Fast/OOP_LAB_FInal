#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;


class WarehouseItem {
protected:
    string itemCode;
    string itemName;
    double basePrice;

public:
    WarehouseItem(string code, string name, double price)
        : itemCode(code), itemName(name), basePrice(price) {}

    virtual ~WarehouseItem() {}

    virtual double calculateStorageCost() const {
        return basePrice * 0.05;
    }

    virtual void display() const {
        cout << "Code: " << itemCode
             << " | Name: " << itemName
             << " | Base Price: Rs. " << basePrice << endl;
    }

    string getItemCode()  const { return itemCode;  }
    string getItemName()  const { return itemName;  }
    double getBasePrice() const { return basePrice; }

    friend ostream& operator<<(ostream& out, const WarehouseItem& item) {
        out << item.itemCode << " | " << item.itemName << " | Rs. " << item.basePrice;
        return out;
    }
};


class ElectronicsItem : public WarehouseItem {
private:
    int  warrantyMonths;
    bool requiresTemperatureControl;

public:
    ElectronicsItem(string code, string name, double price,
                    int warranty, bool tempControl)
        : WarehouseItem(code, name, price),
          warrantyMonths(warranty),
          requiresTemperatureControl(tempControl) {}

    double calculateStorageCost() const override {
        return basePrice * 0.08 + (requiresTemperatureControl ? 500.0 : 0.0);
    }

    void display() const override {
        cout << "Item " << itemCode
             << " | " << itemName
             << " | Base: Rs." << basePrice
             << " | Storage Cost: Rs." << calculateStorageCost()
             << " | Warranty: " << warrantyMonths << " months"
             << " | Temp Control: " << (requiresTemperatureControl ? "Yes" : "No")
             << endl;
    }
};


class PerishableItem : public WarehouseItem {
private:
    int    expiryDays;
    double storageTemp;   

public:
    PerishableItem(string code, string name, double price,
                   int expiry, double temp)
        : WarehouseItem(code, name, price),
          expiryDays(expiry),
          storageTemp(temp) {}

    double calculateStorageCost() const override {
        return basePrice * 0.12 + (expiryDays < 30 ? 1000.0 : 0.0);
    }

    void display() const override {
        cout << "Item " << itemCode
             << " | " << itemName
             << " | Base: Rs." << basePrice
             << " | Storage Cost: Rs." << calculateStorageCost()
             << " | Expiry Days: " << expiryDays
             << " | Temp: " << storageTemp << " C"
             << endl;
    }
};


template <typename T>
class Inventory {
private:
    T** items;
    int capacity;
    int count;

public:

    Inventory(int cap) : capacity(cap), count(0) {
        items = new T*[capacity];
    }
    ~Inventory() {
        delete[] items;
    }

    void addItem(T* item) {
        if (count >= capacity)
            throw runtime_error("Inventory is full. Cannot add more items.");
        items[count++] = item;
    }

    void removeItem(int index) {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index for removeItem.");
        for (int i = index; i < count - 1; i++)
            items[i] = items[i + 1];
        count--;
    }

    T* getItem(int index) const {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index for getItem.");
        return items[index];
    }

    int getCount() const { return count; }

    Inventory<T> operator+(const Inventory<T>& other) const {
        int newCap = count + other.count;
        Inventory<T> merged(newCap);
        for (int i = 0; i < count; i++)
            merged.addItem(items[i]);
        for (int i = 0; i < other.count; i++)
            merged.addItem(other.items[i]);
        return merged;
    }

    T* operator[](int index) const {
        return getItem(index);
    }
};


class InventoryFileManager {
public:
    static void saveToFile(const string& filename, Inventory<WarehouseItem>& inv) {
        ofstream file(filename);
        if (!file.is_open())
            throw runtime_error("Cannot open file for writing: " + filename);

        file << "=== WAREHOUSE INVENTORY REPORT ===" << endl;
        file << "Total Items: " << inv.getCount() << endl;

        for (int i = 0; i < inv.getCount(); i++) {
            WarehouseItem* item = inv[i];
            file << item->getItemCode()
                 << " | " << item->getItemName()
                 << " | Rs." << item->getBasePrice()
                 << " | StorageCost: Rs." << item->calculateStorageCost()
                 << endl;
        }

        file.close();
        cout << "File saved: " << filename << endl;
    }

    static void loadAndPrint(const string& filename) {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("Cannot open file for reading: " + filename);

        cout << "=== FILE CONTENTS ===" << endl;
        string line;
        while (getline(file, line))
            cout << line << endl;

        file.close();
    }
};



int main() {

    ElectronicsItem* e1 = new ElectronicsItem("E001", "Samsung TV 55\"", 85000, 24, true);
    ElectronicsItem* e2 = new ElectronicsItem("E002", "Dell Laptop",    120000, 12, false);
    PerishableItem*  p1 = new PerishableItem ("P001", "Fresh Milk",       200,  7,  4.0);
    PerishableItem*  p2 = new PerishableItem ("P002", "Frozen Beef",     1500, 60, -18.0);

    Inventory<WarehouseItem> invA(2);
    Inventory<WarehouseItem> invB(2);

    invA.addItem(e1);
    invA.addItem(e2);
    invB.addItem(p1);
    invB.addItem(p2);

    Inventory<WarehouseItem> merged = invA + invB;

    cout << "=== MERGED INVENTORY (" << merged.getCount() << " items) ===" << endl;
    for (int i = 0; i < merged.getCount(); i++) {
        cout << "Item " << (i + 1) << ": ";
        merged[i]->display();
    }
    cout << "\noperator<< demo: " << *e1 << endl;

    try {
        InventoryFileManager::saveToFile("warehouse_report.txt", merged);
        InventoryFileManager::loadAndPrint("warehouse_report.txt");
    }
    catch (const runtime_error& e) {
        cout << "FILE ERROR: " << e.what() << endl;
    }

    delete e1;
    delete e2;
    delete p1;
    delete p2;

    return 0;
}
