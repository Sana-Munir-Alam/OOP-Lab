#include <iostream>
using namespace std;

class Polynomials{
	private:
		double *Coefficients
		int Degree;
		int Size;
	public:
		Polynomials(){	// Default Constructor
			Size = 1;
			Degree = 0;
			Coeffcient = new *double[Size];
			for (int i = 0; i < Size; i++){
				Coefficients = 0;
			}
		}
		
		Polynomials(int Degree, int Size){	// Paramatrized Constructor
			this->Degree = Degree;
			this->Size = Size;
			Coefficients = new *double[Size];
			for (int i = 0; i < Size; i++){
				Coefficients = 0;
			}	.
		}
		
		Polynomials(const Polynomials& other){ // Copy Constructor
			this->Degree = other.Degree;
			this -> Size = other.Size;
			Coeffcient = new *double[Size];
			for (int i = 0; i < Size; i++){
				Coefficients[i] = other.Coefficients[i];
			}
		}
		
		Polynomial(Polynomial&& other) noexcept : Size(other.Size), Degree(other.Degree), Coefficients(other.Coefficients) { // Move Constructor
	        other.Coefficients = nullptr;
	        other.Degree = 0;
	        other.Size = 0;
	    }
	    
	    ~Polynomials(){ // Delete Constructor
	    	delete[] Coefficients;
		}
		
		int GetDegree(){
			return Degree;
		}
		double Evaluate(double x){
			
		}
};
int main(){
	
	return 0;
}
