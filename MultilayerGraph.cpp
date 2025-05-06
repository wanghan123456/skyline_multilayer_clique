#include "MultilayerGraph.h" //composed of undirected graph

void MultilayerGraph::LoadMLGraph(std::string& file_name) {
	infile_name = file_name;
	std::ifstream infile(DEFAULT_INFILE_PATH + file_name);
	std::ofstream outfile(DEFAULT_OUTFILE_PATH + file_name,std::ios::app);
	if (!infile.is_open()) {
		outfile << file_name << " " << "does not exists!" << std::endl;
	}
	infile >> l >> n >> m;

	slg_s.reserve(l); //reduce the frequency of memory reallocation
	Graph slg(n);
	for (int i = 0; i < l; i++) {
		slg_s.emplace_back(slg);
	}
	// load edge from file
	std::vector<mlg_edge> edge_buf;
	edge_buf.reserve(m);

	// undirected graph
	int lyr, uid, vid;
	for (int i = 0; i < m; i++) {
		infile >> lyr >> uid >> vid;
		if (uid > vid) { 
			int temp = uid;
			uid = vid;
			vid = temp;
		}
		if (uid == vid) { continue; } // remove self-loop edge
		edge_buf.emplace_back(mlg_edge(lyr - 1, uid - 1, vid - 1)); //align
	}
	m = edge_buf.size();

	sort(edge_buf.begin(), edge_buf.end());
	
	int lyr_index = 0; // layer
	int start_pos{ 0 };
	for (int i = 0; i < edge_buf.size(); i++) {
		if (edge_buf[i].GetLayer() != lyr_index) {
			int end_pos = i - 1;
			slg_s[lyr_index].LoadGraph(edge_buf, start_pos, end_pos, n, file_name);
			start_pos = i;
			lyr_index = edge_buf[i].GetLayer();
		}
		if (i == (edge_buf.size() - 1)) {
			slg_s[lyr_index].LoadGraph(edge_buf, start_pos, i, n, file_name);
		}
	}
	
	infile.close();
	outfile.close();
}

void MultilayerGraph::PrintStatistics(bool print_detail) {
	std::ofstream outfile(DEFAULT_OUTFILE_PATH + infile_name, std::ios::app);
	outfile << "Multilayer Graph: " << infile_name << std::endl;
	outfile << "layer number: " << this->l << " || " << "vertex number: " << this->n << " || " << "edge number: " << this->m << std::endl;
	outfile.close();

	for (int i = 0; i < this->l; i++) {
		slg_s[i].PrintStatistics(print_detail);
	}
}