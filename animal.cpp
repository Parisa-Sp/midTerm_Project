#include "cell.h"

class Animal:public cell{
	public:
	Animal(int n):cell(n){
		
	}
};

int main(){
	Animal(2);
}
