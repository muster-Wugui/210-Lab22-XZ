// COMSC-210 | Lab 20 | Xiao Zhang
#include <iostream>
#include <iomanip>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For seeding rand()

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double *prices;
public:
    // Default constructor: random legs and random prices
    Chair() {
        prices = new double[SIZE];

        legs = (rand() % 2) + 3; // Randomly choose 3 or 4 legs
        
        // Randomly assign prices between $100.00 and $999.99
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
        }
    }

    // Parameter constructor
    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }


    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    // Destructor
    ~Chair() {
        delete[] prices;
    }
};

int main() {
    srand(time(0));  // Seed for random number generation
    cout << fixed << setprecision(2);

    // Creating pointer to first chair object using the default constructor
    Chair *chairPtr = new Chair;
    chairPtr->print();

    // Creating dynamic chair object with parameter constructor
    double prices1[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices1);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // Creating dynamic array of chair objects using default constructor
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }

    delete[] collection;
    return 0;
}
