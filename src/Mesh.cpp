#include "Mesh.h"


//Constructor for Mesh class
//Params: vertices - array of vertices
//        numVertices - number of vertices
//returns: none
Mesh::Mesh(float* vertices, const unsigned int& numVertices)
    : _vertices(vertices), _numVertices(numVertices){
    createVAO();
}


//Returns the array of vertices
//Params: none
//returns: array of vertices
float* Mesh::getVertices() {
    return _vertices;
}

//Returns the number of vertices
//Params: none
//returns: number of vertices
unsigned int Mesh::getNumVertices() {
    return _numVertices;
}


//Binds the VAO
//Params: none
//returns: none
void Mesh::bind() {
    glBindVertexArray(VAO);
}


//Unbinds the VAO
//Params: none
//returns: none
void Mesh::unbind() {
    glBindVertexArray(0);
}


//Creates the VAO
//Params: none
//returns: none
void Mesh::createVAO() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    bind();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, _numVertices * 3 * 4, _vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    unbind();
}


//Draws the mesh (doesnt handle any shaders... Done in model class)
//Params:: none
//returns: none
void Mesh::draw() {
    bind();
    glDrawArrays(GL_TRIANGLES, 0, _numVertices);
    unbind();
}

