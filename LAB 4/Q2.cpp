#include <iostream>
#include <cmath>
using namespace std;

class Polynomials{
	private:
		double *Coefficients;
		int Degree;
	public:
		Polynomials() : Degree(0){	// Default Constructor
			Coefficients = new double[1];
			Coefficients[0] = 0.0;
		}
		
		Polynomials(int Deg, const double Coeff[]) : Degree(Deg){	// Paramatrized Constructor
			Coefficients = new double[Deg + 1];
			for (int i = 0; i <= Deg; i++){
				Coefficients[i] = Coeff[i];
			}
		}
		
		Polynomials(const Polynomials& other) : Degree(other.Degree){ // Copy Constructor
			Coefficients = new double[Degree + 1];
			for (int i = 0; i <= Degree; i++){
				Coefficients[i] = other.Coefficients[i];
			}
		}
		
		Polynomials(Polynomials&& other) noexcept : Degree(other.Degree), Coefficients(other.Coefficients) { // Move Constructor
	        other.Coefficients = nullptr;
	        other.Degree = 0;
	    }
	    
	    ~Polynomials(){ // Destructor
	    	delete[] Coefficients;
		}
		
		int GetDegree() const{
			return Degree;
		}
		double Evaluate(double x) const{
			double Result = 0.0;
			for (int i = 0; i <= Degree; i++){
				Result += Coefficients[i] * pow (x,i);
			}
			return Result;
		}
		Polynomials Add(const Polynomials& other) const {
			int MaxDegree = max(Degree, other.Degree);
			double* ResultCoeffs = new double[MaxDegree + 1];
	
			for (int i = 0; i <= MaxDegree; ++i) {
				double coeff1 = (i <= Degree) ? Coefficients[i] : 0.0;
				double coeff2 = (i <= other.Degree) ? other.Coefficients[i] : 0.0;
				ResultCoeffs[i] = coeff1 + coeff2;
			}
			// ResultCoeff is not sufficient as it doesn't include the polynomial structure hence a new object caleed RESULT was created
			Polynomials Result(MaxDegree, ResultCoeffs); //A new object being created using the parametrized constructor
			delete[] ResultCoeffs; //A new object being created using the parametrized constructor
			return Result; // This is a fully constructed polynomial
		}
		Polynomials Multiply(const Polynomials& other) const {
			int ResultDegree = Degree + other.Degree;
			double* ResultCoeffs = new double[ResultDegree + 1]();
	
			for (int i = 0; i <= Degree; ++i) {
				for (int j = 0; j <= other.Degree; ++j) {
					ResultCoeffs[i + j] += Coefficients[i] * other.Coefficients[j];
				}
			}
			// ResultCoeff is not sufficient as it doesn't include the polynomial structure hence a new object caleed RESULT was created
			Polynomials Result(ResultDegree, ResultCoeffs); //A new object being created using the parametrized constructor
			delete[] ResultCoeffs;	
			return Result; // This is a fully constructed polynomial
		}
		void Print() const {
			for (int i = Degree; i >= 0; --i) {
				cout << Coefficients[i];
				if (i != 0) {
					cout << "x^" << i << " + ";
				}
			}
			cout << endl;
		}
};
int main(){
	double coeffs1[] = {1.0, 2.0, 3.0}; // 1 + 2x + 3x^2
    Polynomials p1(2, coeffs1);
	cout << "Initiallising p1" << endl;
	cout << "Polynomial p1: ";
    p1.Print();

    cout << endl << endl <<"Copying p1 to p2" << endl;
    Polynomials p2 = p1;
    cout << "Polynomial p2 (copy of p1): ";
    p2.Print();

    cout << endl << endl <<"Moving p1 to p3" << endl;
    Polynomials p3 = move(p1);
    cout << "Polynomial p3 (moved from p1): ";
    p3.Print();

	cout << endl << endl <<"Evaluate p3 at x = 2" << endl;
    cout << "p3 evaluated at x = 2: " << p3.Evaluate(2) << endl;

	cout << endl << endl <<"Add p2 and p3" << endl;
    Polynomials p4 = p2.Add(p3);
    cout << "Polynomial p4 (p2 + p3): ";
    p4.Print();

	cout << endl << endl <<"Multiplying p2 and p3" << endl;
    Polynomials p5 = p2.Multiply(p3);
    cout << "Polynomial p5 (p2 * p3): ";
    p5.Print();
	return 0;
}
