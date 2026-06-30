/* 
2. A shop owner approaches you to develop software for managing their store. The system
should maintain records for three items: rice, meat, and potatoes. It must track how many units
of each item have been sold, how many remain in stock, and also store the price of each item,
which should be updatable when needed. How would you design a solution for this problem?
Write a complete C++ class that includes appropriate constructors, a destructor, necessary data
members, and member functions, friend function, friend class where required to handle these
requirements.20
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Forward declaration for the friend function
class Item;
void displayLowStockAlert(const Item items[], int size, int threshold);

// ============================================================
//  Class: Item
// ============================================================
class Item {
private:
    string itemName;
    int stockQuantity;
    int unitsSold;
    double unitPrice;

public:
    // 1. Default Constructor
    Item() {
        itemName = "";
        stockQuantity = 0;
        unitsSold = 0;
        unitPrice = 0.0;
    }

    // 2. Parameterized Constructor
    Item(string name, int initialStock, double price) {
        itemName = name;
        stockQuantity = initialStock;
        unitPrice = price;
        unitsSold = 0; // Fresh item starts with zero sales
    }

    // 3. Destructor
    ~Item() {
        // Automatically releases stack-allocated memory upon lifecycle termination
    }

    // 4. Core Member Functions
    void sellItem(int quantity) {
        if (quantity <= 0) {
            cout << "[ERROR] Invalid sales quantity request for " << itemName << ".\n";
            return;
        }
        
        if (stockQuantity >= quantity) {
            stockQuantity -= quantity;
            unitsSold += quantity;
            cout << "[SUCCESS] Sold " << quantity << " units of " << itemName << ".\n";
        } else {
            cout << "[REJECTED] Insufficient stock for " << itemName 
                 << ". Available: " << stockQuantity << ", Requested: " << quantity << ".\n";
        }
    }

    void restock(int quantity) {
        if (quantity > 0) {
            stockQuantity += quantity;
            cout << "[RESTOCK] Successfully added " << quantity << " units to " << itemName << ".\n";
        } else {
            cout << "[ERROR] Restock quantity must be positive.\n";
        }
    }

    void updatePrice(double newPrice) {
        if (newPrice >= 0.0) {
            double oldPrice = unitPrice;
            unitPrice = newPrice;
            cout << "[PRICE UPDATE] " << itemName << " updated from Rs. " 
                 << oldPrice << " to Rs. " << unitPrice << ".\n";
        } else {
            cout << "[ERROR] Price cannot be a negative value.\n";
        }
    }

    // Declaring explicit friendships as required by the problem statement
    friend class Shop;
    friend void displayLowStockAlert(const Item items[], int size, int threshold);
};

// ============================================================
//  Class: Shop (Friend Class)
// ============================================================
class Shop {
public:
    // Generates an administrative overview utilizing direct access to private attributes
    void generateManagementReport(const Item items[], int size) {
        double totalShopRevenue = 0.0;

        cout << "\n==================================================================\n";
        cout << setw(38) << right << "CENTRAL STORE MANAGEMENT REPORT\n";
        cout << "==================================================================\n";
        cout << left << setw(15) << "Item Name" 
             << setw(15) << "Stock Remaining" 
             << setw(12) << "Units Sold" 
             << setw(12) << "Unit Price" 
             << setw(12) << "Item Revenue" << endl;
        cout << "------------------------------------------------------------------\n";

        for (int i = 0; i < size; i++) {
            // Direct access to private members: items[i].itemName, items[i].stockQuantity, etc.
            double itemRevenue = items[i].unitsSold * items[i].unitPrice;
            totalShopRevenue += itemRevenue;

            cout << left << setw(15) << items[i].itemName
                 << setw(15) << items[i].stockQuantity
                 << setw(12) << items[i].unitsSold
                 << "Rs." << setw(9) << items[i].unitPrice
                 << "Rs." << setw(9) << itemRevenue << endl;
        }

        cout << "------------------------------------------------------------------\n";
        cout << right << setw(52) << "TOTAL ACCUMULATED REVENUE: Rs. " << totalShopRevenue << endl;
        cout << "==================================================================\n\n";
    }
};

// ============================================================
//  Friend Function: displayLowStockAlert
// ============================================================
// Standalone function acting as a bridge to extract and check private structural elements
void displayLowStockAlert(const Item items[], int size, int threshold) {
    cout << ">>> [SYSTEM AUDIT] SCANNING FOR LOW STOCK LEVELS (Threshold: " << threshold << " units) <<<\n";
    bool alertTriggered = false;

    for (int i = 0; i < size; i++) {
        if (items[i].stockQuantity < threshold) {
            cout << "  [ALERT] " << items[i].itemName << " is critically low! Only " 
                 << items[i].stockQuantity << " units remain in inventory.\n";
            alertTriggered = true;
        }
    }

    if (!alertTriggered) {
        cout << "  [STATUS] All inventory positions are healthy and well-stocked.\n";
    }
    cout << "------------------------------------------------------------------\n\n";
}

// ============================================================
//  Main Function: System Demonstration
// ============================================================
int main() {
    const int totalRecords = 3;
    
    // Instantiating the three mandatory items using our parameterized constructor
    Item inventory[totalRecords] = {
        Item("Rice", 150, 95.0),
        Item("Meat", 60, 750.0),
        Item("Potatoes", 200, 40.0)
    };

    // Instantiate management layer object
    Shop storeAdmin;

    // --- PHASE 1: Initial Inventory Balance Audit ---
    displayLowStockAlert(inventory, totalRecords, 70);

    // --- PHASE 2: Processing Active Customer Transactions ---
    cout << "=== PROCESSING SALES TRANSFERS ===\n";
    inventory[0].sellItem(40);  // Success: Selling Rice
    inventory[1].sellItem(15);  // Success: Selling Meat
    inventory[2].sellItem(250); // Failure: Request exceeds available Potato stock
    inventory[2].sellItem(50);  // Success: Selling remaining safe volume of Potatoes
    cout << "----------------------------------\n\n";

    // --- PHASE 3: Administrative Adjustments (Price & Stock) ---
    cout << "=== PROCESSING INVENTORY UPDATE MANIFESTS ===\n";
    // Updating the price of Rice when needed
    inventory[0].updatePrice(105.0);
    
    // Replenishing depleted stock
    inventory[1].restock(30);
    cout << "---------------------------------------------\n\n";

    // --- PHASE 4: Secondary Audit and Comprehensive Store Report Generation ---
    displayLowStockAlert(inventory, totalRecords, 70);
    storeAdmin.generateManagementReport(inventory, totalRecords);

    return 0;
}