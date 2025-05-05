#include "Clique.h"

void Clique::BKP(std::unordered_set<int>& R, std::unordered_set<int>& P, std::unordered_set<int>& X) {
	if (P.size() == 0 ) {
		if (X.size() == 0) {
			clique_num++;
		}
		return;
	}

	for (const auto& vtx : P) {
		R.insert(vtx);
		P.erase(vtx);
		std::unordered_set<int> P_new(P);
		std::unordered_set<int> X_new(X);
		UpdatePX(vtx, P_new, X_new);
		BKP(R, P, X);
		R.erase(vtx);
		X.insert(vtx);
	}
}

void Clique::UpdatePX(const int& vtx, std::unordered_set<int>& P, std::unordered_set<int>& X) {

}