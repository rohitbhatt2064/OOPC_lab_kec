/* 
3. Design a C++ program that demonstrates the use of friend classes for coordinate conversion.
Create a class Cartesian to represent a point in Cartesian coordinates (  ,  ).
Create another class Polar to represent a point in Polar coordinates (  ,  ).
Implement a mechanism to convert a point from Cartesian to Polar form and vice versa.
Use friend classes so that each class can access the private data members of the other for
conversion purposes.
Write a complete program that includes:
Appropriate constructors and destructors.
Member functions to input and display coordinates.
Conversion functions using the friend class relationship.
A demonstration in main() showing conversion in both directions.10
 */

#include <iostream>
#include <cmath> // Standard for math functions like sqrt and atan2

using namespace std;

// 1. Forward Declaration of Polar class so Cartesian can declare it as a friend
class Polar;

// ============================================================
//  Class: Cartesian
// ============================================================
class Cartesian {
private:
    float x;
    float y;

public:
    // Default Constructor
    Cartesian() {
        x = 0.0;
        y = 0.0;
    }

    // Parameterized Constructor
    Cartesian(float x_val, float y_val) {
        x = x_val;
        y = y_val;
    }

    // Destructor
    ~Cartesian() {}

    // Member functions to input and display
    void input() {
        cout << "Enter X coordinate: ";
        cin >> x;
        cout << "Enter Y coordinate: ";
        cin >> y;
    }

    void display() const {
        cout << "Cartesian (x, y) = (" << x << ", " << y << ")" << endl;
    }

    // Conversion function declarations (implemented below both classes)
    void convertToPolar(Polar& p) const;

    // Granting friendship to class Polar
    friend class Polar;
};

// ============================================================
//  Class: Polar
// ============================================================
class Polar {
private:
    float r; // radius
    float t; // theta in radians

public:
    // Default Constructor
    Polar() {
        r = 0.0;
        t = 0.0;
    }

    // Parameterized Constructor
    Polar(float radius, float theta) {
        r = radius;
        t = theta;
    }

    // Destructor
    ~Polar() {}

    // Member functions to input and display
    void input() {
        cout << "Enter radius (r): ";
        cin >> r;
        cout << "Enter theta (t in radians): ";
        cin >> t;
    }

    void display() const {
        cout << "Polar (r, theta) = (" << r << ", " << t << " rad)" << endl;
    }

    // Conversion function declarations (implemented below both classes)
    void convertToCartesian(Cartesian& c) const;

    // Granting friendship to class Cartesian
    friend class Cartesian;
};

// ============================================================
//  Friend Class Conversion Implementations
// ============================================================

// Cartesian directly updates private members of Polar (r, t)
void Cartesian::convertToPolar(Polar& p) const {
    p.r = sqrt(x * x + y * y);
    p.t = atan2(y, x); // atan2 safely handles all quadrants automatically
}

// Polar directly updates private members of Cartesian (x, y)
void Polar::convertToCartesian(Cartesian& c) const {
    c.x = r * cos(t);
    c.y = r * sin(t);
}

// ============================================================
//  Main Demonstration Function
// ============================================================
int main() {
    cout << "--- 1. Cartesian to Polar Conversion ---" << endl;
    Cartesian c1(25.0, 25.0);
    Polar p1; // Empty polar object to hold the converted value

    c1.display();
    c1.convertToPolar(p1); // Cartesian accesses Polar's private members to set them
    p1.display();

    cout << "\n--- 2. Polar to Cartesian Conversion ---" << endl;
    // 45 degrees is approx 0.7854 radians
    Polar p2(35.355, 0.7854); 
    Cartesian c2; // Empty cartesian object to hold the converted value

    p2.display();
    p2.convertToCartesian(c2); // Polar accesses Cartesian's private members to set them
    c2.display();

    cout << "\n--- 3. Interactive Testing ---" << endl;
    Cartesian c3;
    Polar p3;
    
    c3.input();
    c3.convertToPolar(p3);
    p3.display();

    return 0;
}