#include "animal.cpp"
#include <string.h>
#include <conio.h>
#include<stdlib.h>
using namespace std;
vector<DNARNA> genes;
vector<Animal> animals;

print_gene_Data(DNARNA a){
	cout << "RNA:" << a.get_RNA()<<endl;;
	cout << "DNA1:" << a.get_DNA1()<<endl;
	cout << "DNA2:" << a.get_DNA2()<<endl;
}

int main(){
	while(true){
	system("CLS");
	int menu;
	DNARNA temp;
	string rnatemp;
	string dna1temp;
	int index;
	cout << "1.Create a gene"<<endl;
	cout << "2.Get gene values"<<endl;
	cout << "3.make RNA complement of a gene:"<<endl;
	cout << "4.small mutation on gene:"<<endl;
	cout << "5.big mutation on gene:"<<endl;
	cout << "6.reverse mutation on gene:"<<endl;
	cout << "Enter the menu number:";
	cin >> menu;
	switch(menu){
		case 1:
			
			cout <<"Enter the RNA value:";
			cin >> rnatemp;
			cout <<"Enter first DNA value:";
			cin >> dna1temp;
			temp.set_DNARNA(rnatemp,dna1temp);
			temp.create_DNA2();
			genes.push_back(temp);
			break;
		case 2:
			
			cout << "Enter index number of gene:";
			cin >> index;
			print_gene_Data(genes[index]);
			getch();
			break;
		case 3:
			cout << "Enter index number of gene:";
			cin >> index;
			genes[index].print_RNA_complement();
			getch();
			break;
		case 4:
			cout << "Enter index number of gene:";
			cin >> index;
			genes[index].smallMutate('A','C','0');
			print_gene_Data(genes[index]);
			getch();
			break;
		case 5:
			cout << "Enter index number of gene:";
			cin >> index;
			genes[index].bigMutate("AT","CG");
			print_gene_Data(genes[index]);
			getch();
			break;
		case 6:
			cout << "Enter index number of gene:";
			cin >> index;
			genes[index].reverseMutate("AT");
			print_gene_Data(genes[index]);
			getch();
			break;
			
			
	}
		
	}
	
}
