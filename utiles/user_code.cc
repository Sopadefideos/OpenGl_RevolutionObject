//**************************************************************************
// Codigo del usuario
//
// Domingo Martin Perandres 2013
//
// GPL
//**************************************************************************

#include "user_code.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "vertex.h"
#include "file_ply_stl.hpp"
using namespace std;

//**************************************************************************
// Funcion para dibujar los vertices de un cubo unidad
//***************************************************************************

void draw_cube()
{
    GLfloat Vertices[8][3]= {{-0.5,-0.5,0.5},{0.5,-0.5,0.5},{0.5,0.5,0.5},{-0.5,0.5,0.5},{-0.5,-0.5,-0.5},{0.5,-0.5,-0.5},{0.5,0.5,-0.5},{-0.5,0.5,-0.5}};
    
    glColor3f(0,1,0);
    glPointSize(4);
    
    glBegin(GL_POINTS);
    for (unsigned i=0;i<8;i++){
        glVertex3fv((GLfloat *) &Vertices[i]);
    }
    
    glEnd();
}

//**************************************************************************
// Funcion para dibujar vertices
//***************************************************************************

void draw_vertices(vector<float> &Vertices)
{
    glPointSize(4);
    glColor3f(1.0,0.0,0.0);
    glBegin (GL_POINTS);
    for (int j=0; j<Vertices.size(); j+=3){
        GLfloat x, y, z;
        x=Vertices[j];
        y=Vertices[j+1];
        z=Vertices[j+2];
        glVertex3f(x, y, z);
    }
    glEnd();
}

void draw_caras_lineas(vector<float> &Vertices, vector<int> &Caras)
{
    //draw_vertices(Vertices);
    glColor3f(0,1,0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //GL_FILL
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Caras.size(); i++) {
        GLfloat x, y, z;
        int indice;
        indice = Caras[i]*3;
        x=*(GLfloat *) &Vertices[indice];
        y=*(GLfloat *) &Vertices[indice+1];
        z=*(GLfloat *) &Vertices[indice+2];
        glVertex3f(x, y, z);
    }
    glEnd();
}


void draw_caras_ajedrez(vector<float> &Vertices, vector<int> &Caras)
{
    //draw_vertices(Vertices);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //GL_FILL
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Caras.size(); i++) {
        GLfloat x, y, z;
        int indice;
        indice = Caras[i]*3;
        if((i % 3 == 0) && (i % 2 == 0)){
            glColor3f(0,0,1);
        }else if((i % 3 == 0) && (i % 2 == 1)){
            glColor3f(0,1,0);
        }
        x=*(GLfloat *) &Vertices[indice];
        y=*(GLfloat *) &Vertices[indice+1];
        z=*(GLfloat *) &Vertices[indice+2];
        glVertex3f(x, y, z);
    }
    glEnd();
}

void draw_caras_llenar(vector<float> &Vertices, vector<int> &Caras)
{
    //draw_vertices(Vertices);
    glColor3f(0,1,0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //GL_FILL
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Caras.size(); i++) {
        GLfloat x, y, z;
        int indice;
        indice = Caras[i]*3;
        x=*(GLfloat *) &Vertices[indice];
        y=*(GLfloat *) &Vertices[indice+1];
        z=*(GLfloat *) &Vertices[indice+2];
        glVertex3f(x, y, z);
    }
    glEnd();
}


//**************************************************************************
// Funcion rota para los vertices
//***************************************************************************

void rotacion_vertices(vector<float> &inicial, vector<float> &final){
    int n = 50;
    
    final.push_back(0);
    final.push_back(-1.4);
    final.push_back(0);
    for (int i = 0; i < n; i++){
        double angulo = (2 * M_PI * i) / (float)n;
        for (int j = 0; j < inicial.size(); j+=3){
            float x, y, z;
            x=inicial[j];
            y=inicial[j+1];
            z=inicial[j+2];
            float xF, yF, zF;
            yF=y;
            xF=x*cos(angulo) + z*sin(angulo);
            zF=-x*sin(angulo) + z*cos(angulo);
            final.push_back(xF);
            final.push_back(yF);
            final.push_back(zF);
        }
    }
    final.push_back(0);
    final.push_back(1.4);
    final.push_back(0);
    
}

void rotacion_caras(vector<int> &inicial, vector<int> &final, vector<float> &Vertices, vector<float> &Vertices_rotados){
   int n = 50;
    int tam = Vertices.size()/3;
    cout<<"tam: "<<tam<<endl;
    for (int j = 0; j < tam - 1; j++) {
      int up, left, right;
        up = j;
        left = up + 1;
        right = left + tam;
      for (int i = 0; i < n; i++) {
          final.push_back(up);
          final.push_back(left);
          final.push_back(right);
          cout<<up<<"   "<<left<<"   "<<right<<"   "<<endl;
          final.push_back(right);
          final.push_back(right-1);
          final.push_back(up);
          cout<<right<<"   "<<right-1<<"   "<<up<<"   "<<endl;
        up += tam;
        left = right;
        right += tam;
      }
    }
    
    int up = 0, left = 1, right = left + tam;
    for (int i = 1; i < n; i++) {
        final.push_back(up);
        final.push_back(left);
        final.push_back(right);

      left = right;
      right += tam;
    }
    int tam2 = Vertices_rotados.size()/3;
    up = tam2 - 1, left = up - 1,
    right = left - tam;
    for (int i = 1; i < n; i++) {
        final.push_back(up);
        final.push_back(left);
        final.push_back(right);
      left = right;
      right -= tam;
    }
    
}
