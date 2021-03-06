#include "common/common.hpp"
#include "sw4.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 320; 

	double (*up_0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*up_1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*up_2)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*um_0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*um_1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*um_2)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*u_0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*u_1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*u_2)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*rho)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double *strx = (double *) getRandom1DArray<double>(320);
	double *stry = (double *) getRandom1DArray<double>(320);
	double *strz = (double *) getRandom1DArray<double>(320);
	double *dcx = (double *) getRandom1DArray<double>(320);
	double *dcy = (double *) getRandom1DArray<double>(320);
	double *dcz = (double *) getRandom1DArray<double>(320);
	double *cox = (double *) getRandom1DArray<double>(320);
	double *coy = (double *) getRandom1DArray<double>(320);
	double *coz = (double *) getRandom1DArray<double>(320);
	double (*up_gold_0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*up_gold_1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*up_gold_2)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	memcpy(up_0, up_gold_0, sizeof(double)*N*N*N);
	memcpy(up_1, up_gold_1, sizeof(double)*N*N*N);
	memcpy(up_2, up_gold_2, sizeof(double)*N*N*N);

	sw4_gold ((double*)up_gold_0, (double*)up_gold_1, (double*)up_gold_2, (double*)u_0, (double*)u_1, (double*)u_2, (double*)um_0, (double*)um_1, (double*)um_2, (double*)rho, (double*)strx, (double*)stry, (double*)strz,  (double*)dcx, (double*)dcy, (double*)dcz, (double*)cox, (double*)coy, (double*)coz, N);
	host_code ((double*)up_0, (double*)up_1, (double*)up_2, (double*)u_0, (double*)u_1, (double*)u_2, (double*)um_0, (double*)um_1, (double*)um_2, (double*)rho, (double*)strx, (double*)stry, (double*)strz,  (double*)dcx, (double*)dcy, (double*)dcz, (double*)cox, (double*)coy, (double*)coz, N, N, N);


	double error_0 = checkError3D<double> (N, N, (double*)up_0, (double*)up_gold_0, 2, N-2, 2, N-2, 2, N-2);
	printf("[Test] RMS Error : %e\n",error_0);
	if (error_0 > TOLERANCE)
		return -1;
	double error_1 = checkError3D<double> (N, N, (double*)up_1, (double*)up_gold_1, 2, N-2, 2, N-2, 2, N-2);
	printf("[Test] RMS Error : %e\n",error_1);
	if (error_1 > TOLERANCE)
		return -1;
	double error_2 = checkError3D<double> (N, N, (double*)up_2, (double*)up_gold_2, 2, N-2, 2, N-2, 2, N-2);
	printf("[Test] RMS Error : %e\n",error_2);
	if (error_2 > TOLERANCE)
		return -1;

	delete[] strx;
	delete[] stry;
	delete[] strz;
	delete[] cox;
	delete[] coy;
	delete[] coz;
	delete[] dcx;
	delete[] dcy;
	delete[] dcz;
	delete[] um_0;
	delete[] um_1;
	delete[] um_2;
	delete[] u_0;
	delete[] u_1;
	delete[] u_2;
	delete[] rho;
	delete[] up_0;
	delete[] up_1;
	delete[] up_2;
	delete[] up_gold_0;
	delete[] up_gold_1;
	delete[] up_gold_2;
}
