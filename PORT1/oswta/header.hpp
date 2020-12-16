#ifndef OSWTA_OSWTA_H
#define OSWTA_OSWTA_H
#include <string>
#include <vector>
using namespace std; // STD::VACCINE

double Bounded_Both_Ends(double, double, string);
long Bounded_Both_Ends(long, long, string);
char char_In_Middle(char, char, string);
long List_Menu_Choices_Long(vector<long> &, string);
double Bounded_Lower_Range(double, string);
long Bounded_Lower_Range(long, string);
char char_Lower_Bound(char, string);
double List_Menu_Choices_Double(vector<double> &, string);
double Bounded_Upper_Range(double, string);
long Bounded_Upper_Range(long, string);
char char_Upper_Bound(char, string);
double List_Menu_Choices_Char(vector<char> &, string);
#endif
