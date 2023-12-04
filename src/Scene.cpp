#include "Scene.h"

Scene::Scene(Shader* shader)
	: _shader(shader) {
	currentMesh = 0;
}

void Scene::createCube(float* vertices, unsigned int numVertices) {
	Mesh cube = Mesh(vertices, numVertices);
	_meshes.push_back(cube);
}

void Scene::generateModels() {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);

	Model currentModel = Model(_meshes[0], position, _shader);
	_modelsCube.push_back(currentModel);
}

std::vector<Model> Scene::getModels() {
	return _modelsCube;
}