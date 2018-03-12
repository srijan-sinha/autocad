#ifndef GLUT_H
#define GLUT_H
#include <GL/glut.h>
#endif

#ifndef IO_H
#define IO_H
#include <iostream>
#endif

#include "elements3d.h"
/*#include "input3d.h"
#include "output3d.h"
#include "output2d.h"
*/
using namespace std;

int main()
{
	cout<<"Hello World"<<endl;
	Vertex3d v = Vertex3d(1,1,1,"A");
	vector<double> vect;
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    v.rotate(vect,90);
    
	return 0;
};