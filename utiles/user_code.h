//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013
//
// GPL
//**************************************************************************

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#endif

#include <vector>

using namespace std;

void draw_cube();

void draw_vertices(vector<float> &Vertices);

void draw_caras_lineas(vector<float> &Vertices, vector<int> &Caras);

void draw_caras_ajedrez(vector<float> &Vertices, vector<int> &Caras);

void draw_caras_llenar(vector<float> &Vertices, vector<int> &Caras);

void rotacion_vertices(vector<float> &inicial, vector<float> &final);

void rotacion_caras(vector<int> &inicial, vector<int> &final, vector<float> &Vertices, vector<float> &Vertices_rotados);
