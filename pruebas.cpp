#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>
#include "lorentz.h"

using namespace std;

int main() 
{

	int i=8;
	vector vector1(1,6,2,1);
	vector vector2(2,1,2,8);
	vector vector3(3,5,3,1);
	vector vector4(4,4,1,6);
	lorentz_vector l1(vector1,"mu");
	lorentz_vector l2(vector2,"alpha");
	lorentz_vector l3(vector3,"mu");
	lorentz_vector l4(vector4,"alpha");

	lorentz_vector terna[4] = {l1,l2,l3,l4};
	cout << contract(terna,4) << endl;
	cout << (vector1*vector3)*(vector2*vector4) << endl;
	return 0;


	
}
