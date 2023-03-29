#ifndef MYFILE_H
#define MYFILE_H
#include "cell.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;
random_device rd;
mt19937 g(rd());
double get_similarity(const vector<string>& v1, const vector<string>& v2) {
    vector<string> common;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(common));
    
    double sim = (double)common.size() / max(v1.size(), v2.size()) * 100.0;
    return sim;
}
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

class Animal:public cell{
	public:
	Animal(int n):cell(n){	
	}
	friend class virus;
	float similarity(Animal temp){
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
	bool operator==(Animal& other) {
		if(similarity(other) >= 70){
			return true;
		}
		return false;
    }
    Animal AsexualProduction(){
    	vector<string> dnas;
    	for (auto& gene : get_genes()) {
			dnas.push_back(gene.get_DNA1());
			dnas.push_back(gene.get_DNA1());
		}
		shuffle(dnas.begin(), dnas.end(), g);
		Animal born(get_genes().size());
		for (int i = 0 ; i < get_genes().size();i++){
			born.add_gene(dnas[i]);
		}
    	return born;
	}
	Animal operator+(Animal& other){
		vector<string> dnas;
		Animal born(get_genes().size());
		Animal a = AsexualProduction();
		Animal b = other.AsexualProduction();
		if(get_genes().size()%2 == 1){
			return born;
		}
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
class virus:public DNARNA{
	public:
	virus(string rna){
		set_DNARNA(rna,"");
	}
	bool dangerous(Animal temp){
		vector<string> DNA1s;
		vector<string> DNA2s;
		for (auto& gene : temp.get_genes()) {
			DNA1s.push_back(gene.get_DNA1());
			DNA2s.push_back(gene.get_DNA2());	
		}
		string rna1 = longest_common_substring(DNA1s);
		string rna2 = longest_common_substring(DNA2s);
		return rna1 == get_RNA() || rna2 == get_RNA();
	}
};
#endif // MYFILE_H
