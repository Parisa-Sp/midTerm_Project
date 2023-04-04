#include "animal.h"
#include <string.h>
#include <conio.h>
#include<stdlib.h>

using namespace std;
vector<DNARNA> genes;
vector<Animal> animals;
vector<cell> cells;

void print_gene_Data(DNARNA a){
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
	string S1,S2;
	int n,m;
	cell tempCell(2);
	Animal tempAnimal(2);
	virus tempVirus("ATAT");
	int index;
	cout << "1.Create a gene"<<endl;
	cout << "2.Get gene values"<<endl;
	cout << "3.make RNA complement of a gene:"<<endl;
	cout << "4.small mutation on gene:"<<endl;
	cout << "5.big mutation on gene:"<<endl;
	cout << "6.reverse mutation on gene:"<<endl;
	cout << "7.create cell:"<<endl;
	cout << "8.death cell:"<<endl;
	cout << "9.cell big mutation:"<<endl;
	cout << "10.cell small mutation:"<<endl;
	cout << "11.cell reverse mutation:"<<endl;
	cout << "12.cell palindrom:"<<endl;
	cout << "13.create Animal:"<<endl;
	cout << "14.similarity of animals:"<<endl;
	cout << "15.equality of animals:"<<endl;
	cout << "16.Asexual reproduction:"<<endl;
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
			genes[index].smallMutate('A','C',2);
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
		case 7:
			cout <<"number of cromesoms:";
			cin >> index;
			tempCell.set_number_genes(index);
			tempCell.set_genes();
			cells.push_back(tempCell);
			break;
		case 8:
			cout << "Enter index number of cell:";
			cin >> index;
			cells[index].deadCell();
			break;
		case 9:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter S1:";
			cin >> S1;
			cout << "Enter n:";
			cin >> n;
			cout << "Enter S2:";
			cin >> S2;
			cout << "Enter m:";
			cin >> m;
			cells[index].bigMutate(S1,n,S2,m);
			break;	
		case 10:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter n:";
			cin >> n;
			cout << "Enter m:";
			cin >> m;
			cells[index].smallMutate('A','C',n,m);
			break;	
		case 11:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter S1:";
			cin >> S1;
			cout << "Enter n:";
			cin >> n;
			cells[index].reverseMutate(S1,n);
			break;
		case 12:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter n:";
			cin >> n;
			cells[index].palindrom(n);
			getch();
			break;
		case 13:
			cout <<"number of cromesoms of animal:";
			cin >> index;
			tempAnimal.set_number_genes(index);
			tempAnimal.set_genes();
			animals.push_back(tempAnimal);
			break;
		case 14:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			animals[n].similarity(animals[m]);			
			getch();
		case 15:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			if(animals[n] == animals[m])
				cout <<"they are same animal"<<endl;
			else
				cout <<"they are not the same"<<endl;		
			getch();
		case 16:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			animals.push_back(animals[n].AsexualProduction());
			break;
		case 17:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			animals.push_back(animals[n]+animals[m]);
			break;
		case 18:
			cout <<"Enter RNA of virus:";
			cin >> rnatemp;
			tempVirus.set_DNARNA(rnatemp,"");
			cout <<"Enter n-th animal's index':";
			cin >> n;
			if(tempVirus.dangerous(animals[n]))
				cout <<"it's dangerous";
			else
				cout <<"its not dangerous";
		
			
	}
		
	}
	
}
