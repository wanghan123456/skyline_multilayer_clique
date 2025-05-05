#pragma once
#include"Header.h"
class Clique
{
public:
	Clique(int vtx_num){
		R.reserve(vtx_num);
		P.reserve(vtx_num);
		X.reserve(vtx_num);
		for (int i = 0; i < vtx_num; i++) {
			P.insert(i);
		}
	}
	~Clique() = default;

	void BKP(std::unordered_set<int>& R, std::unordered_set<int>& P, std::unordered_set<int>& X); //BK with pivot technique
	void UpdatePX(const int& vtx, std::unordered_set<int>& P, std::unordered_set<int>& X); //update P and X


private:
	std::unordered_set<int> R;
	std::unordered_set<int> P;
	std::unordered_set<int> X;

	int clique_num{ 0 };
};



