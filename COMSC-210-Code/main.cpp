// COMSC-210 | Lab 14 | Xiao Zhang

#include <iostream>
#include <iomanip>

using namespace std;


const int MIN = 0;
const int MAX = 255;

class Color {
private:
    int r, g, b; // red, green, blue

public:
    // Default constructor
    Color();
    
    // Parameterized constructor
    Color(int red, int green, int blue);

    // Getters and setters
    int getR() const;
    void setR(int red);

    int getG() const;
    void setG(int green);

    int getB() const;
    void setB(int blue);

    // Prints the RGB values
    void show() const;
};

