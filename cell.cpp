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

    void create_DNA2() {
        DNA2 = get_DNA_complement(DNA1);
    }
};

int main() {
    DNARNA myDNA("ATCGATCG", "CGCGCG");
    myDNA.create_DNA2();
    cout << "RNA: " << myDNA.get_RNA() << endl;
    cout << "DNA1: " << myDNA.get_DNA1() << endl;
    cout << "DNA2: " << myDNA.get_DNA2() << endl;
    return 0;
}
