#include "Model.h"

Model::Model(Mesh* mesh, glm::vec3 position, Shader* shader)
	: _mesh(mesh), _position(position), _shader(shader) {
	_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	_scale = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Model::render() {
	std::cout << "HELLO" << std::endl;
}