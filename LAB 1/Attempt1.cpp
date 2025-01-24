#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	float Array[argc - 1];
	//Copying from one array to other
	for (int i = 0; i < argc-1; i++){
		Array[i] = stof(argv[i+1]);
	}
	
	float Max = 0;
	float Max2 = 0;
	for (int i = 0; i < argc-1 ; i++){
		if (Array[i] > Max){
			Max2 = Max;
			Max = Array[i];
		}else if ((Array[i] != Max) && (Max2 < Array[i])){
			Max2 = Array[i];
		}
	}
	cout <<"The Second Highest Number is: "<< Max2;
	return 0;
}