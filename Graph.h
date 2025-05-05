#pragma once
#include "Header.h"
struct edge {
public:
	edge(int s_, int t_) :s(s_), t(t_) {}
	edge() = default;
	~edge() = default;

	bool operator <(edge& other) {
		return s < other.s || (s == other.s && t < other.t);
	}

private:
	int s{ -1 };
	int t{ -1 };
};

struct mlg_edge {
public:
	mlg_edge() = default;
	mlg_edge(int l_, int s_, int t_) :l(l_), s(s_), t(t_) {}
	~mlg_edge() = default;

	bool operator <(mlg_edge& other) {
		return l < other.l || (l == other.l && s < other.s) || (l == other.l && s == other.s && t < other.t);
	}

	int GetLayer() const {
		return l;
	}

	int GetS() const {
		return s;
	}
	int GetT() const {
		return t;
	}


private:
	int l{ -1 };
	int s{ -1 };
	int t{ -1 };
};


class Graph
{
public:
	Graph() = default;
	Graph(int n_) : n(n_) {}
	Graph(int n_, int m_) :n(n_), m(m_) {}
	~Graph() = default;

	void LoadGraph(std::vector<mlg_edge>& edge_buf, int& start_pos, int& end_pos, const int num_vtx, std::string& file_name);

	void PrintStatistics(bool print_detail = false);

	const std::vector<std::vector<int>>& GetAdjList() const {
		return adj_lst;
	}
	
private:
	int n{ 0 };
	int m{ 0 };
	int layer_id{ -1 };
	std::string out_file;
	std::vector<std::vector<int>> adj_lst;
	std::vector<int> vtx_deg;
	std::vector<bool> vtx_exist;
	int max_deg{ 0 };
	int degeneracy{ 0 };

};

