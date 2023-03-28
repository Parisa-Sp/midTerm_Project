#ifndef MYFILE_H
#define MYFILE_H
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

bool is_palindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
    	switch(s[i]){
    		case 'A':
    			if(s[n-i-1] != 'T')
    				return false;
    			break;
    		case 'T':
    			if(s[n-i-1] != 'A')
    				return false;
    			break;
    		case 'C':
    			if(s[n-i-1] != 'G')
    				return false;
    			break;
    		case 'G':
    			if(s[n-i-1] != 'C')
    				return false;
    			break;	
		}
    }
    return true;
}

void find_palindromic_substrings(string dna) {
    int n = dna.length();
    for (int i = 0; i < n; i++) {
        for (int j = i+3; j <= n; j++) {
            string substr = dna.substr(i, j-i);
            if(is_palindrome(substr) && substr.length()%2==0){
            	cout << substr << endl;
			}
        }
    }
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
        cell(int n){
        	numberOfGenes = n;
        	
        }
        
        void add_gene(string DNA1) {
            DNARNA new_gene;
            new_gene.set_DNARNA("",DNA1);
            genes.push_back(new_gene);
        }
        void set_genes(){
        	for(int i = 0 ; i < numberOfGenes ;i++){
        		string dna;
        		cout << "Enter DNA of Chromosome "<< i<<":";
        		cin >> dna;
        		add_gene(dna);
			}
		}
		vector<DNARNA> get_genes(){
			return genes;
		}
        void deadCell(){
        	vector<DNARNA> goodGenes;
        	for (auto& gene : genes) {
        		int at=0,cg=0;
        		int notLinked = 0;
        		cout << gene.get_DNA1();
        		for(int i = 0 ; i < gene.get_DNA1().length() ; i++){
        			switch(gene.get_DNA1()[i]){
        				case 'A':
        					if(gene.get_DNA2()[i] == 'T'){
        						at++;
							}
							else{
								notLinked++;
							}
        					break;
        				case 'T':
        					if(gene.get_DNA2()[i] == 'A'){
        						at++;
							}
							else{
								notLinked++;
							}
        					break;
        				case 'C':
        					if(gene.get_DNA2()[i] == 'G'){
        						cg++;
							}
							else{
								notLinked++;
							}
        					break;
        				case 'G':
        					if(gene.get_DNA2()[i] == 'C'){
        						cg++;
							}
							else{
								notLinked++;
							}
        					break;
					}
        			if(notLinked < 5 && at / cg < 3)
        			{
        				goodGenes.push_back(gene);
        				
					}
				}
				
        	}
			genes = goodGenes;
		}
        void smallMutate(char oldChar, char newChar, int n,int m) {
            genes[m].smallMutate(oldChar, newChar,n);
        }
        
        void bigMutate(string S1,int n1, string S2,int n2) {
        int posD1 = -1;
        int posD2 = -1;
        posD1 = KMPSearch(genes[n1].get_DNA1(),S1);
        posD2 = KMPSearch(genes[n2].get_DNA2(),S2);
        if(posD1 != -1 && posD2 != -1)
        {
        	genes[n1].bigMutate(S1,S2);
			genes[n2].bigMutate(S2,S1);	
		}
    }
        void reverseMutate(string s1,int n){
        	genes[n].reverseMutate(s1);
	}
		void palindrom(int n){
			find_palindromic_substrings(genes[n].get_DNA1());
		}

};



#endif // MYFILE_H
