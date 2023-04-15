#include "cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;
random_device rd;
mt19937 g(rd());
// optimal alignment distance algorithm
int optimal_string_alignment_distance(string s1, string s2) {
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    for (int i = 0; i <= s1.length(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= s2.length(); j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    return dp[s1.length()][s2.length()];
}
//get similarity of two vector of string
double get_similarity(const vector<string>& v1, const vector<string>& v2) {
	vector<int> size;
	vector<double> sim_collection;
    int size_sum = 0; 
	double weight_avg = 0;
    for (int i = 0 ; i < min(v1.size() , v2.size()) ; i++) {
		double k = (double)(max(v1[i].length(),v2[i].length())-optimal_string_alignment_distance(v1[i],v2[i]))/max(v1[i].length(),v2[i].length())*100;
		sim_collection.push_back(k);
		size.push_back(max(v1[i].length() , v2[i].length()));
		weight_avg += size[i] * sim_collection[i];
        size_sum += size[i];
	}
    double sim = (double)weight_avg / size_sum;
    return sim;
}
//return longest common substring of a vector of strings
string longest_common_substring(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    string result;
    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = i + 1; j <= strs[0].size(); j++) {
            string substring = strs[0].substr(i, j - i);
            bool found = true;
            for (int k = 1; k < strs.size(); k++) {
                if (strs[k].find(substring) == string::npos) {
                    found = false;
                    break;
                }
            }
            if (found && substring.size() > result.size()) {
                result = substring;
            }
        }
    }
    return result;
}
//animal class inherit cell
class Animal:public cell{
	public:
	Animal(int n):cell(n){	
	}
	friend class virus;
	//return similarity of two animals with checking their similarity of genes
	double similarity(Animal temp){
		vector<string> a;
		vector<string> b;
		for (auto& gene : get_genes()) {
			a.push_back(gene.get_DNA1());
		}
		for (auto& gene : temp.get_genes()) {
			b.push_back(gene.get_DNA1());
		}
		return get_similarity(a,b);
	}
	//dead cell function that delete bad chromosomes
    void deadCell(){
			int n=0;
			vector<DNARNA> good_genes;
        	for (auto& gene : get_genes()) {
        		int at=0,cg=0;
        		int notLinked = 0;
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
                }
        		if(notLinked < 5 && at / cg < 3){
                    good_genes.push_back(gene);
					n++;
				}
        	}
			set_genes(good_genes);
			set_number_genes(n);
		}
	//overriding == operator with checking the similarity of two animals and if its more than 70% return true otherwise return false
	bool operator==(Animal& other) {
		if(similarity(other) >= 70){
			return true;
		}
		return false;
    }
    //Asexual Reproduction that pick n random of their genes
    Animal AsexualProduction(){
		Animal born(get_genes().size());
		while (similarity(born) < 70){
			vector<string> dnas;
			for (auto& gene : get_genes()) {
				dnas.push_back(gene.get_DNA1());
				dnas.push_back(gene.get_DNA1());
			}
			shuffle(dnas.begin(), dnas.end(), g);
			for (int i = 0 ; i < get_genes().size();i++){
				born.add_gene(dnas[i]);
			}
		}
    	return born;
	}
	//sexual Reproduction that pick n random of two animal genes
	Animal operator+(Animal& other){
		vector<string> dnas;
		Animal born(get_genes().size());
		Animal a = AsexualProduction();
		Animal b = other.AsexualProduction();
		for (auto& gene : a.get_genes()) {
			dnas.push_back(gene.get_DNA1());
			
		}
		for (auto& gene : b.get_genes()) {
			dnas.push_back(gene.get_DNA1());
			
		}
		shuffle(dnas.begin(), dnas.end(), g);
		for (int i = 0 ; i < a.get_genes().size();i++){
			born.add_gene(dnas[i]);
		}
        return born;
    }
};
//virus class that just contain RNA
class virus:public DNARNA{
	public:
	virus(string rna){
		set_DNARNA(rna,"");
	}
	//check if a virus is dangerous for a animal by checking the longest common substring of genes of them with rna of virus
	bool dangerous(Animal temp){
		vector<string> DNA1s;
		vector<string> DNA2s;
		for (auto& gene : temp.get_genes()) {
			DNA1s.push_back(gene.get_DNA1());
			DNA2s.push_back(gene.get_DNA2());	
		}
		string rna1 = longest_common_substring(DNA1s);
		string rna2 = longest_common_substring(DNA2s);
		if (rna1 == get_RNA() || rna2 == get_RNA()){
			return true;
		}
		else if (KMPSearch(get_RNA(),rna1) != -1 || KMPSearch(get_RNA(),rna2) != -1){
			return true;
		}
		else
			return false;
	}
};