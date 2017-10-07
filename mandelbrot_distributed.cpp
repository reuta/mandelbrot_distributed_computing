#include <iostream>
#include <math.h>
#include <fstream>
#include <mpi.h>
#include "complex.hpp"

using namespace std;

int brot(Complex z, Complex c, int x) {
	for (int i = 0; i < x; i++) {
		z = z * z + c;
		if (abs(z) > 2) {
			return i + 1;
		}
	}

	return 0;
}

struct xy {
	int x;
	int y;
	xy() {

	}
	xy(int xx, int xy) {
		x=xx;
		y=xy;
	}
}

void mandelbrot(int l, ofstream & datei) {
	if (world_rank == 0) { // hauptprozess
		datei << "P1" << endl << l << " " << l;
		double b = 4 / (double) l;
        for (double y = 0; y < l; y++) {
			datei << endl;
			for (double x = 0; x < l; x++) {
				m xy(x,y);
				MPI_Send(&m, sizeof(xy), 1, MPI_BYTE, ((int) x % 5) + 1, 0);
				datei << MPI_Recv(&t, 1, MPI_LONG_DOUBLE, ((int) x % 5) + 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		    }
		}
	}
	else if (world_rank != 0) { // falls nicht hauptprozess
		int x, y;
		MPI_Recv(&m, 1, MPI_BYTE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		Complex coord((x * b) - 2, (b * y) - 2);
		Complex z(0, 0);
		int t = (brot(z, coord, 50) == 0 ? 1 : 0); // errechnen des pixelfarbwerts (1 oder 0)
		MPI_Send(&t, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD); // zurückgeben des errechneten werts
	}

}
int main(int argc, char * argv[]) {
	// initialisieren von MPI
    MPI_Init(NULL, NULL);
	int world_rank, world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_SIZE(MPI_COMM_WORLD, &world_size);
	
    if (world_size < 2) {
		fprintf("Fehler: Zu wenig Prozesse!\n");
	}
	if (world_rank == 0) { // falls hauptprozess
		ofstream datei;
		datei.open(argv[1]);
		mandelbrot(1000, datei);
		datei.close();
		fprintf("Rendern abgeschlossen!\n");
	}
	return 0;
}
