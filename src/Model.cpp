#include "Model.h"


//Constructor for model
//Params: mesh - mesh object
//		: position - a vec3 position of the object
//		: shader - a pointer towards a shader object
//returns: nothing
Model::Model(Mesh mesh, glm::vec3 position, Shader* shader)
	: _mesh(mesh), _position(position), _shader(shader) {
	_model = glm::mat4(1.0f);
	_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	_scale = glm::vec3(0.0f, 0.0f, 0.0f);
}

//Updates the model with the current position
//Params: none
//returns: nothing
void Model::updateModel() {
	_model = glm::translate(_model, _position);
}

//Updates the position
//Params: newPosition - the new position
//returns: nothing
void Model::changePosition(glm::vec3 newPosition) {
	_position = newPosition;
}

//Renders the model to the screen
//Params: none
//return: nothing
void Model::render() {
	updateModel();
	_shader->setMat4("model", _model);
	_mesh.draw();
}