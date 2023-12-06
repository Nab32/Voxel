#include "Scene.h"

//Cube vertices
float cubeVert[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f
};


//Constructor for scene class
//Params: shader - the shader to be used
//returns: none
Scene::Scene(Shader* shader)
	: _shader(shader) {
	currentMesh = 0;
}

//This function creates a cube mesh
//Params: none
//returns: none
void Scene::createCube() {
	Mesh* cube = new Mesh(cubeVert, 36);
	_meshes.push_back(cube);
}


//This function generates the models
//Params: none
//returns: none
void Scene::generateModels() {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 1; j++){
            for (int z = 0; z < 32; z++){
                _modelsCube.push_back(Model(_meshes[currentMesh], glm::vec3(position.x + (float)i, position.y + (float)j, position.z + (float)z), _shader));
            }
        }
    }
}


//This function returns the models
//Params: none
//returns: _modelsCube
std::vector<Model> Scene::getModels() {
	return _modelsCube;
}