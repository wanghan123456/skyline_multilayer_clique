#include "MultilayerGraph.h"
#include "Timer.h"
#include "Clique.h"
//argc - argument count
//argv[0] - program name
//argv[1] - infile path
//argv[2] - outfile path
int main(int argc, char* argv[]) {
	Timer timer;
	MultilayerGraph mlg;
	std::string infile_name = argv[1];
	infile_name = infile_name + ".txt";
	mlg.LoadMLGraph(infile_name);
	timer.Stop();
	
	// get peak memeory
	//struct rusage usage;
	//getrusage(RUSAGE_SELF, &usage);
	//long peak_memory = usage.ru_maxrss;

	mlg.PrintStatistics(true);

	/*std::ofstream memory_file(DEFAULT_OUTFILE_PATH + infile_name, std::ios::app);
	if (memory_file.is_open()) {
		memory_file << "Peak memory usage: " << peak_memory << " KB" << std::endl;
		memory_file.close();
	}*/

	if (mlg.GetL() > 0) {
		for (int i = 0; i < mlg.GetL(); i++) {
			const Graph& graph = mlg.GetGraph(i);
			Clique clique(mlg.GetN(), graph, infile_name);
			clique.MCE();
			clique.PrintStatistics();
		}
	}

	return 0;
}