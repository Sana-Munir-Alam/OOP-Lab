#include <iostream>
using namespace std;

class Circle {
private:
    double Radius;
	const double PI = 3.14159265358979323846;
public:
	Circle(){	//Default Constructor
		Radius = 0;
	}
    Circle(double R) : Radius(R) {	// Paramatrized Constructor
        if (R < 0) {
            throw invalid_argument("Radius cannot be a negative value.");
        }
    }
    double GetArea() const {
        return PI * Radius * Radius;
    }
    double GetPerimeter() const {
        return 2 * PI * Radius;
    }
};

int main(int argc, char *argv[]) {
	if (argc < 2) {
        cerr << "Error: Please Provide the Radius!!" << endl;
        return 1;
    }
	try{
		double Radius = stod(argv[1]);
		Circle circle(Radius);
		
		cout.precision(3); 
		cout << "Area of the circle: " << fixed << circle.GetArea() << endl;
		cout << "Perimeter of the circle: " << fixed << circle.GetPerimeter() << endl;

	}catch(const invalid_argument& e){
		cerr << e.what() << endl;
		return 1;
	}
    return 0;
}
