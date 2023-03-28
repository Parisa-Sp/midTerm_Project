#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int KMPSearch(string text, string pattern) {
    vector<int> pi = prefix_function(pattern);
    int n = text.length();
    int m = pattern.length();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
        	return i - m + 1;
        }
    }
    return -1;
}

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
    return str;
}

class DNARNA {
private:
    string RNA;
    string DNA1;
    string DNA2;
public:
    

    void set_DNARNA(string rna, string dna1)
    {
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
    void bigMutate(string S1, string S2) {
        int posR = KMPSearch(RNA,S1);
        if (posR != -1) {
            RNA.replace(posR, S1.length(), S2);
        }
        int posD1 = -1;
        int posD2 = -1;
        posD1 = KMPSearch(DNA1,S1);
        posD2 = KMPSearch(DNA2,S1);
        if(posD1 != -1 && posD2 != -1)
        {
        	if(posD1 < posD2){
            	DNA1.replace(posD1, S1.length(), S2);
        		DNA2 = get_DNA_complement(DNA1);
			}
			else{
				DNA2.replace(posD2, S1.length(), S2);
        		DNA1 = get_DNA_complement(DNA2);
			}	
		}
		else if (posD1 != -1){
			DNA1.replace(posD1, S1.length(), S2);
        	DNA2 = get_DNA_complement(DNA1);
		}
		else if (posD2 != -1){
			DNA2.replace(posD2, S1.length(), S2);
        	DNA1 = get_DNA_complement(DNA2);
		}
    }
    void reverseMutate(string s1){
    	string s2 = reverseString(s1);
    	bigMutate(s1,s2);
    	
	}
};
class cell: public DNARNA {
    private:
        vector<DNARNA> genes;
        int numberOfGenes;
    public:
        cell(){
        }
        void add_gene(string DNA1) {
            DNARNA new_gene;
            new_gene.set_DNARNA("",DNA1);
            genes.push_back(new_gene);
        }
        void smallMutate(char oldChar, char newChar, int n,int m) {
            genes[m].smallMutate(oldChar, newChar,n);
        }
        
        void reverseMutate(string s1,int n){
        	genes[n].reverseMutate(s1);
	}
        






};
int main() {
    DNARNA myDNA;
    myDNA.set_DNARNA("ATCGATCG", "AAGTCTCAGT");
    myDNA.create_DNA2();
    myDNA.bigMutate("TCAG","ATC");
    cout << "RNA: " << myDNA.get_RNA() << endl;
    cout << "DNA1: " << myDNA.get_DNA1() << endl;
    cout << "DNA2: " << myDNA.get_DNA2() << endl;
    return 0;
}
