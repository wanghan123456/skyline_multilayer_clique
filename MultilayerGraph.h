#pragma once
#include "Graph.h"


class MultilayerGraph
{
public:
	MultilayerGraph() = default;
	MultilayerGraph(int l_, int n_, int m_) :l(l_), n(n_), m(m_) {}
	~MultilayerGraph() = default;

	[[nodiscard]] int GetN() const {
		return n;
	}

	[[nodiscard]] int GetM() const {
		return n;
	}

	[[nodiscard]] int GetL() const {
		return l;
	}

	void LoadMLGraph(std::string& file_name);

	void PrintStatistics(bool print_detail = false);

private:
	int l{ -1 }; 
	int n{ -1 };
	int m{ -1 };
	std::string infile_name;
	std::vector<Graph> slg_s;
};

