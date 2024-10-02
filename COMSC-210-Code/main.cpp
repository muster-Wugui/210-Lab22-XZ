// COMSC-210 | Lab 16 | Xiao Zhang

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

    // Partial constructor (default green and blue to 0)
    Color(int red);

    int getR() const;
    
    void setR(int red);

    int getG() const;
    
    void setG(int green);

    int getB() const;
    
    void setB(int blue);

    void show() const;
};

void showColors(const Color& c1, const Color& c2, const Color& c3);

int main() {
    // Using the parameterized constructor
    Color redC(255, 0, 0);
    
    // Using the default constructor
    Color defaultC;

    // Using the partial constructor
    Color partialR(128);

    // Using the parameterized constructor for custom the color
    Color custom(50, 100, 150);

    // Outputing the color values
    showColors(redC, defaultC, partialR);

    cout << "Custom Color:"<<endl;
    custom.show();

    return 0;
}

// default constructor
Color::Color() : r(0), g(0), b(0) {}

// Parameterized constructor
Color::Color(int red, int green, int blue) {
    setR(red);
    setG(green);
    setB(blue);
}

// Partial constructor, initializing only red
Color::Color(int red) : r(0), g(0), b(0) {
    setR(red);
}

int Color::getR() const {
    return r;
}

void Color::setR(int red) {
    if (red >= MIN && red <= MAX)
        r = red;
    else
        cerr << "Error: " << red << "\n";
}

int Color::getG() const {
    return g;
}

void Color::setG(int green) {
    if (green >= MIN && green <= MAX)
        g = green;
    else
        cerr << "Error: " << green << "\n";
}

int Color::getB() const {
    return b;
}

void Color::setB(int blue) {
    if (blue >= MIN && blue <= MAX)
        b = blue;
    else
        cerr << "Error: " << blue << "\n";
}

// Prints the RGB values
void Color::show() const {
    cout << "Color: (" << setw(3) << r << ", " << setw(3) << g << ", " << setw(3) << b << ")\n";
}

// Prints out a few Color objects
void showColors(const Color& c1, const Color& c2, const Color& c3) {
    cout << "Here are the colors:\n";
    c1.show();
    c2.show();
    c3.show();
}
