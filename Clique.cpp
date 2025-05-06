#include "Clique.h"

void Clique::BKP(std::unordered_set<int>& R, std::unordered_set<int>& P, std::unordered_set<int>& X) {
	if (P.size() == 0 ) {
		if (X.size() == 0) {
			clique_num++;
		}
		return;
	}

	std::vector<int> P_vec(P.begin(), P.end());
	for (const int& vtx : P_vec) {
		std::unordered_set<int> R_new(R);
		std::unordered_set<int> P_new(P);
		std::unordered_set<int> X_new(X);
		
		UpdatePX(vtx, R_new, P_new, X_new);
		BKP(R_new, P_new, X_new);
		P.erase(vtx);
		X.insert(vtx);
	}
}

void Clique::UpdatePX(const int& vtx, std::unordered_set<int>& R, std::unordered_set<int>& P, std::unordered_set<int>& X) {
	const auto& adj_lst = graph.GetAdjList();
	const auto& neighbors = adj_lst[vtx];
	std::unordered_set<int> new_R(R);
	std::unordered_set<int> new_P;
	std::unordered_set<int> new_X;

	new_R.insert(vtx);

	for (int neighbor : neighbors) {
		if (R.find(neighbor) == R.end()) {
			if (P.find(neighbor) != P.end()) {
				new_P.insert(neighbor);
			}
			else {
				new_X.insert(neighbor);
			}
		}
	}
	R = new_R;
	P = new_P;
	X = new_X;
}

void Clique::MCE() {

	BKP(this->R, this->P, this->X);
}

void Clique::PrintStatistics(bool print_detail) {
	std::ofstream outfile(DEFAULT_OUTFILE_PATH + infile_name, std::ios::app);
	outfile << "Maximal Clique count: " << clique_num << std::endl;
	outfile.close();
}