#include "Graph.h"


void Graph::LoadGraph(std::vector<mlg_edge>& edge_buf, int& start_pos, int& end_pos, const int num_vtx, std::string& file_name) {
	//initiate 
	this->n = num_vtx;
	adj_lst.reserve(n);
	vtx_deg.resize(n, 0);
	vtx_exist.resize(n, true);
	this->out_file = file_name;

	for (int i = start_pos; i <= end_pos; i++) {
		int u = edge_buf[i].GetS();
		int v = edge_buf[i].GetT();
		if (start_pos > 0 && u == edge_buf[i - 1].GetS() && v == edge_buf[i - 1].GetT()) { continue; } //remove deplicated edges

		this->m = this->m + 1;
		adj_lst[u].emplace_back(v);
		adj_lst[v].emplace_back(u);
		vtx_deg[u]++;
		vtx_deg[v]++;

		if (vtx_deg[u] > max_deg) {
			max_deg = vtx_deg[u];
		}
		if (vtx_deg[v] > max_deg) {
			max_deg = vtx_deg[v];
		}
	}
}

void Graph::PrintStatistics(bool print_detail) {
	if (this->m == 0) { return; }

	std::ofstream outfile(DEFAULT_OUTFILE_PATH + this->out_file, std::ios::app);
	outfile << "vertex number: " << this->n << " || " << "edge number: " << this->m << " || " << "max degree: " << this->max_deg << std::endl;
	outfile.close();
}