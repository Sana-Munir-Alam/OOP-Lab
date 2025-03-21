#include <iostream>
using namespace std;

class Fraction{
	private:
		int Numerator;
		int Denominator;
	public:
		Fraction(int Nume, int Deno) : Numerator(Nume), Denominator(Deno){
			// Paramatrized constructor
			if (Denominator < 0){
				// We are simply shifting the negative sign to 
				Numerator = -Numerator;
				Numerator = -Denominator;
			}
		}
		void FindGCD(){
			int Min;
			if (Numerator < Denominator){
				Min = Numerator;
			}else {
				Min = Denominator;
			}
		    while (Min > 1) {
		        if (Numerator % Min == 0 && Denominator % Min == 0){
		        	break;
				}
				Min--;
		    }
		    cout << "Reduced Numerator: " << Numerator / Min << endl;
		    cout << "Reduced Denominator: " << Denominator / Min << endl;
		}
		Fraction operator*(Fraction const& other){
			return Fraction(Numerator * other.Numerator, Denominator * other.Denominator)
		}
		Fraction operator/(Fraction const& other){
			return Fraction(Numerator * other.Denominator, Denominator * other.Numerator)
		}
		Fraction operator-(Fraction const& other){
			return Fraction(((Numerator * other.Denominator)-(other.Numerator * Denominator)) Denominator * other.Denominator)
		}
		
		Fraction operator+(Fraction const& other){
			return Fraction(((Numerator * other.Denominator)+(other.Numerator * Denominator)) Denominator * other.Denominator)
		}
		

int main(){
	
}
