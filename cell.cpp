#include <iostream>
#include <string>

using namespace std;

class DNARNA {
public:
    string RNA;
    string DNA1;
    string DNA2;

    DNARNA(string rna, string dna1) {
        RNA = rna;
        DNA1 = dna1;
        DNA2 = "";
    }

    string get_RNA() {
        return RNA;
    }

    string get_DNA1() {
        return DNA1;
    }

    string get_DNA2() {
        return DNA2;
    }

    string get_DNA_complement(string rna) {
        string complement = "";
        for (int i = 0; i < rna.length(); i++) {
            if (rna[i] == 'A') {
                complement += 'T';
            }
            else if (rna[i] == 'T') {
                complement += 'A';
            }
            else if (rna[i] == 'C') {
                complement += 'G';
            }
            else if (rna[i] == 'G') {
                complement += 'C';
            }
        }
        return complement;
    }
	void print_RNA_complement(){
		cout <<"RNA complement:" << get_DNA_complement(RNA) << endl;;
	}
    void create_DNA2() {
        DNA2 = get_DNA_complement(DNA1);
    }
    
    void smallMutate(char oldChar, char newChar, int n) {
    	int temp = n;
        for (int i = 0; i < RNA.length() && temp > 0; i++) {
            if (RNA[i] == oldChar) {
                RNA[i] = newChar;
                temp--;
            }
        }
        temp = n;
        char newCharC;
        switch(newChar){
        	case 'A':
        		newCharC = 'T';
        		break;
        	case 'T':
        		newCharC = 'A';
        		break;
        	case 'C':
        		newCharC = 'G';
        		break;
        	case 'G':
        		newCharC = 'C';
        		break;
		}
        for (int i = 0; i < DNA1.length() && temp > 0; i++) {
            if (DNA1[i] == oldChar) {
                DNA1[i] = newChar;
                DNA2[i] = newCharC;
                temp--;
            }
            else if(DNA2[i] == oldChar){
            	DNA2[i] = newChar;
                DNA1[i] = newCharC;
                temp--;
			}
        }
    }

};

int main() {
    DNARNA myDNA("ATCGATCG", "ACGGCCTAA");
    myDNA.create_DNA2();
    myDNA.smallMutate('A','C',2);
    cout << "RNA: " << myDNA.get_RNA() << endl;
    cout << "DNA1: " << myDNA.get_DNA1() << endl;
    cout << "DNA2: " << myDNA.get_DNA2() << endl;
    return 0;
}
