#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh {
    public:
        //Mesh(const char* path);
        Mesh(float* vertices, const unsigned int& numVertices);
        float* getVertices();
        unsigned int getNumVertices();
        void bind();
        void unbind();
        void createVAO();
    private:
        float* _vertices;
        unsigned int VBO, VAO;
        unsigned int _numVertices;
};