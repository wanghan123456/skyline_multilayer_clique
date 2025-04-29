#include "MultilayerGraph.h"
#include "Timer.h"
//argv - number of arguments
//argc[0] - program
//argc[1] - infile path
//argc[2] - outfile path
int main(int argv, char* argc[]) {
	Timer timer;
	MultilayerGraph mlg;
	std::string infile_name = argc[1];
	infile_name = infile_name + ".txt";
	mlg.LoadMLGraph(infile_name);
	timer.Stop();
	mlg.PrintStatistics();
	return 0;
}