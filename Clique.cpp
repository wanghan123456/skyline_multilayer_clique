#include "Clique.h"

void Clique::BKP(std::unordered_set<int> R, std::unordered_set<int> P, std::unordered_set<int> X) {
	if (P.size() == 0 ) {
		if (X.size() == 0) {
			clique_num++;
		}
		return;
	}

	for (const auto& vtx : P) {
		
		/*
		update 
		*/

		BKP(R, P, X);
		P.erase(vtx);
		X.insert(vtx);
	}
	
}

void Clique::UpdatePX() {

}