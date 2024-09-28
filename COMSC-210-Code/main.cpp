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

void showColors(const Color& c1, const Color& c2, const Color& c3);

int main() {
    Color redColor(255, 0, 0);
    Color greenColor(0, 255, 0);
    Color blueColor(0, 0, 255);

    // Showing the color values
    showColors(redColor, greenColor, blueColor);

    return 0;
}


// Default constructor
Color::Color() : r(0), g(0), b(0) {}

// Parameterized constructor
Color::Color(int red, int green, int blue) {
    setR(red);
    setG(green);
    setB(blue);
}

// Getter and Setter for Red
int Color::getR() const {
    return r;
}

void Color::setR(int red) {
    if (red >= MIN && red <= MAX)
        r = red;
    else
        cerr << "Error: " << red << "\n";
}

// Getter and Setter for Green
int Color::getG() const {
    return g;
}

void Color::setG(int green) {
    if (green >= MIN && green <= MAX)
        g = green;
    else
        cerr << "Error: " << green << "\n";
}

// Getter and Setter for Blue
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
