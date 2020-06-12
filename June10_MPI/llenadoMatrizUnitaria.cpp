#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include "mpi.h"

int main(int argc, char **argv) 
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int N = 0;
  if (0 == pid) {
    std::printf("Por favor escriba el total de elementos N:\n");
    std::scanf("%d", &N);
  }
  
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

  double tstart = MPI_Wtime();
  //Lo que hace cada proceso
  int tam = N/np;
  int imin = tam*pid;
  
  std::string fname = std::to_string(pid) + ".txt";
  std::ofstream fout(fname, std::ofstream::out);
  int z = 0;
  for ( int ii = imin; ii < imin + tam; ++ii){
    for ( int jj = 0; jj < N; ++jj){
      if ( jj != ii ) z = 0;
      else z = 1;
      
      fout << z << " ";
    }
    fout << "\n";
  }
  fout.close();
  
  double tend = MPI_Wtime();
  std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  
  //El pid 0 unifica la informacion
  if (0 == pid) {
    std::ofstream outFile("matriz.txt", std::ofstream::out);
    for ( int ii = 0; ii < np; ++ii){
      std::string nameFile = std::to_string(ii) + ".txt";
      std::ifstream inFile( nameFile , std::ofstream::out );
      std::string line = "";
      while( getline(inFile, line ) ){
	outFile << line  << "\n";
      }
      inFile.close();
    }
    outFile.close();
  }
  
  MPI_Finalize();
  
  return 0;
}
