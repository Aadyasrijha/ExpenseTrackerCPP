#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Expense {
    std::string category;
    double amount;
    std::string date;
};

class ExpenseTracker {
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const std::string& category, double amount, const std::string& date) {
        expenses.push_back({category, amount, date});
        std::cout << "Expense added successfully!\n";
    }

    void viewExpenses() const {
        if (expenses.empty()) {
            std::cout << "No expenses recorded yet.\n";
            return;
        }

        std::cout << std::setw(15) << "Category" << std::setw(10) << "Amount" << std::setw(15) << "Date" << "\n";
        std::cout << "-----------------------------------------\n";
        for (const auto& expense : expenses) {
            std::cout << std::setw(15) << expense.category 
                      << std::setw(10) << expense.amount 
                      << std::setw(15) << expense.date << "\n";
        }
    }

    void totalByCategory(const std::string& category) const {
        double total = 0.0;
        for (const auto& expense : expenses) {
            if (expense.category == category) {
                total += expense.amount;
            }
        }

        std::cout << "Total expenses for category '" << category << "': " << total << "\n";
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        std::cout << "\nExpense Tracker\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View All Expenses\n";
        std::cout << "3. View Total by Category\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string category, date;
                double amount;

                std::cout << "Enter category: ";
                std::cin >> category;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::cin >> date;

                tracker.addExpense(category, amount, date);
                break;
            }
            case 2:
                tracker.viewExpenses();
                break;
            case 3: {
                std::string category;
                std::cout << "Enter category: ";
                std::cin >> category;
                tracker.totalByCategory(category);
                break;
            }
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
