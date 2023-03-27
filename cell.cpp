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


};
