#include "cell.h"
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
class Animal:public cell{
	public:
	Animal(int n):cell(n){	
	}
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
    	
	}
};

int main(){
	Animal a(2);
	a.set_genes();
	Animal b(2);
	b.set_genes();
	if(a==b){
		cout <<"hello";
	}

}

