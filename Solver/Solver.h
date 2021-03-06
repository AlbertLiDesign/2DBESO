#pragma once

#include <iostream>
#include <string>
#include <vector>

#define EIGEN_USE_MKL_ALL
#include <Eigen/Eigen>
#include <Eigen/PardisoSupport>
#include <Eigen/CholmodSupport>

#include <unsupported/Eigen/SparseExtra>
#include <cholmod.h>
#include<time.h> 

extern "C" __declspec(dllexport) void Assembly_Solve(int num_freeDofs, int num_allDofs, int num_triplets, 
	int* free_dofs, int* ik, int* jk, double* vk, double* F, double* U);

extern "C" __declspec(dllexport) void PreFE(int nelx, int nely, int* ik, int* jk);

extern "C" __declspec(dllexport) double TransposeMultiply(int rows, int cols, double* A, double* U);

extern "C" __declspec(dllexport) void GetRowSum(int coo_length, int rows, int* ih, int* jh, double* vh, double* sh);
extern "C" __declspec(dllexport) void Flt(int dc_length, double* dc, double* sh);