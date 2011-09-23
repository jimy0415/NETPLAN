// --------------------------------------------------------------
//    NETSCORE Version 2
//    global.h -- Definition of global variables and functions
//    2009-2011 (c) Eduardo Ibanez
// --------------------------------------------------------------

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "step.h"
#include "index.h"

// Type definitions
typedef vector<string> VectorStr;
typedef vector<VectorStr> MatrixStr;

enum HeaderOption { H_Default, H_Prep, H_Post, H_PostNsga, H_Time, H_Benders,
                    H_Nsga, H_NsgaParallel, H_Completed, H_Elapsed };
struct GlobalStep;

// Global parameters ******************************************************************************
struct GlobalParam {
	GlobalParam();
	
	// Node parameters
	vector<string> NodeProp, NodeDefault;
	
	// Arc parameters
	vector<string> ArcProp, ArcDefault;
	
	// Transportation variables
	string TransStep, TransDummy;
	vector<string> TransInfra, TransComm;
	
	// Common parameters
	string DefStep;
	
	// Steps
	GlobalStep *s;
};


// Step variables *********************************************************************************
struct GlobalStep {
	GlobalStep(string text, vector<string>& shrs);
	
	vector<int> NextStep, Col, Hours, Length, Year;
	vector<string> Text, YearString;
	vector<bool> isFirstYear;
	string Chars, YearChar;
	int NumYears, MaxPos;
};


// Global variables
extern string SName;
extern Step SLength;
extern bool useDCflow;
extern string StorageCode, DCCode, TransCoal;
extern int Npopsize, Nngen, Nobj, Nevents;
extern string Npcross_real, Npmut_real, Neta_c, Neta_m, Npcross_bin, Npmut_bin, Nstages;
extern double Np_start;
extern vector<string> ArcProp, StepHours, SustObj, SustMet;
extern int NodePropOffset, ArcPropOffset, outputLevel;
// Store indices to recover data after optimization
extern Index IdxNode, IdxUd, IdxRm, IdxArc, IdxInv, IdxCap, IdxUb, IdxEm, IdxDc, IdxNsga;

// Print error messages
void printError(const string& selector, const char* fileinput);
void printError(const string& selector, const string& field);

// Print header at the beginning of execution
void printHeader(HeaderOption selector);

// Remove comments and end of line characters
void CleanLine(char* line);

// Convert a value to a string
template <class T>
string ToString(T t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

#endif  // _GLOBAL_H_
