#include "MultilayerGraph.h"
#include "Timer.h"
//argc - number of arguments
//argv[0] - program
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
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	long peak_memory = usage.ru_maxrss;

	mlg.PrintStatistics();

	std::ofstream memory_file(DEFAULT_OUTFILE_PATH + infile_name, std::ios::app);
	if (memory_file.is_open()) {
		memory_file << "Peak memory usage: " << peak_memory << " KB" << std::endl;
		memory_file.close();
	}

	return 0;
}