#include "animal.h"
#include "cell.h"
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;
vector<DNARNA> genes;
vector<Animal> animals;
vector<cell> cells;

int main(){
	while(true){
	cout.precision(3);
	system("CLS");
	int menu;
	DNARNA temp;
	string rnatemp;
	string dna1temp;
	string S1,S2;
	char char1,char2;
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
	cout << "7.create cell (auto):"<<endl;
	cout << "8.create cell (manual):"<<endl;
	cout << "9.get cell values"<<endl;
	cout << "10.dead cell:"<<endl;
	cout << "11.cell big mutation:"<<endl;
	cout << "12.cell small mutation:"<<endl;
	cout << "13.cell reverse mutation:"<<endl;
	cout << "14.cell palindrom:"<<endl;
	cout << "15.create Animal (auto):"<<endl;
	cout << "16.create Animal (manual):"<<endl;
	cout << "17.get animal values"<<endl;
	cout << "18.dead cell (Animal):"<<endl;
	cout << "19.similarity of animals:"<<endl;
	cout << "20.equality of animals:"<<endl;
	cout << "21.Asexual reproduction:"<<endl;
	cout << "22.sexual reproduction:"<<endl;
	cout << "23.danger of virus:"<<endl;
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
			genes[index].print_gene_Data();
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
			cout << "Enter char1:";
			cin >> char1;
			cout << "Enter char2:";
			cin >> char2;
			cout << "Enter number of mutation:";
			cin >> n;
			genes[index].smallMutate(char1,char2,n);
			genes[index].print_gene_Data();
			getch();
			break;
		case 5:
			cout << "Enter index number of gene:";
			cin >> index;
			cout << "Enter S1:";
			cin >> S1;
			cout << "Enter S2:";
			cin >> S2;
			genes[index].bigMutate(S1,S2);
			genes[index].print_gene_Data();
			getch();
			break;
		case 6:
			cout << "Enter index number of gene:";
			cin >> index;
			genes[index].reverseMutate("AT");
			genes[index].print_gene_Data();
			getch();
			break;
		case 7:
			cout <<"number of cromesoms:";
			cin >> index;
			tempCell.set_number_genes(index);
			tempCell.set_genes_auto();
			cells.push_back(tempCell);
			break;
		case 8:
			cout <<"number of cromesoms:";
			cin >> index;
			tempCell.set_number_genes(index);
			tempCell.set_genes_manual();
			cells.push_back(tempCell);
			break;
		case 9:
			cout << "Enter index number of cell:";
			cin >> index;
			cells[index].display_cell();
			getch();
			break;
		case 10:
			cout << "Enter index number of cell:";
			cin >> index;
			if (cells[index].deadCell())
				cells.erase(cells.begin()+index);
			break;
		case 11:
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
		case 12:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter char1:";
			cin >> char1;
			cout << "Enter char2:";
			cin >> char2;
			cout << "Enter n:";
			cin >> n;
			cout << "Enter m:";
			cin >> m;
			cells[index].smallMutate(char1,char2,n,m);
			break;	
		case 13:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter S1:";
			cin >> S1;
			cout << "Enter n:";
			cin >> n;
			cells[index].reverseMutate(S1,n);
			break;
		case 14:
			cout << "Enter index number of cell:";
			cin >> index;
			cout << "Enter n:";
			cin >> n;
			cells[index].palindrom(n);
			getch();
			break;
		case 15:
			cout <<"number of cromesoms of animal:";
			cin >> index;
			tempAnimal.set_number_genes(index);
			tempAnimal.set_genes_auto();
			animals.push_back(tempAnimal);
			break;
		case 16:
			cout <<"number of cromesoms of animal:";
			cin >> index;
			tempAnimal.set_number_genes(index);
			tempAnimal.set_genes_manual();
			animals.push_back(tempAnimal);
			break;
		case 17:
			cout << "Enter index number of animal:";
			cin >> index;
			animals[index].display_cell();
			getch();
			break;
		case 18:
			cout << "Enter index number of animal:";
			cin >> index;
			animals[index].deadCell();
			break;
		case 19:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			cout << animals[n].similarity(animals[m]) << endl;		
			getch();
			break;
		case 20:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			if(animals[n] == animals[m])
				cout <<"they are same animal"<<endl;
			else
				cout <<"they are not the same"<<endl;		
			getch();
			break;
		case 21:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			animals.push_back(animals[n].AsexualProduction());
			break;
		case 22:
			cout <<"Enter n-th animal's index':";
			cin >> n;
			cout <<"Enter m-th animal's index':";
			cin >> m;
			animals.push_back(animals[n]+animals[m]);
			break;
		case 23:
			cout <<"Enter RNA of virus:";
			cin >> rnatemp;
			tempVirus.set_DNARNA(rnatemp,"");
			cout <<"Enter n-th animal's index:";
			cin >> n;
			if(tempVirus.dangerous(animals[n]))
				cout <<"it's dangerous";
			else
				cout <<"it's not dangerous";
			getch();
			break;
		}
	}
}
