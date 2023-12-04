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

	Model model1 = Model(_meshes[0], position, _shader);
	Model model2 = Model(_meshes[0], glm::vec3(position.x, position.y, position.z + 1), _shader);
	_modelsCube.push_back(model1);
	_modelsCube.push_back(model2);
}


//This function returns the models
//Params: none
//returns: _modelsCube
std::vector<Model> Scene::getModels() {
	return _modelsCube;
}