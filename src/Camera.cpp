#include "Camera.h"

//Constructor for camera
//Params: position - the initial position of the camera
//returns: none
Camera::Camera(glm::vec3 position, Window* window)
	: _position(position), _window(window){
	_view = glm::mat4(1.0f);
	_angleX = 0;
	_angleY = 0;
	_angleZ = 0;
	updateView();
}

//sends back the view of the camera
//Params: none
//returns: _view
glm::mat4 Camera::getView() {
	return _view;
}


//Updates the view matrix of the camera
//Params: none
//returns: none
void Camera::updateView() {
	_view = glm::mat4(1.0f);
	_view = glm::translate(_view, _position);
	_view = glm::rotate(_view, glm::radians(_angleX), glm::vec3(1.0f, 0.0f, 0.0f));
	_view = glm::rotate(_view, glm::radians(_angleY), glm::vec3(0.0f, 1.0f, 0.0f));
	_view = glm::rotate(_view, glm::radians(_angleZ), glm::vec3(0.0f, 0.0f, 1.0f));
}


//Updates the current position of the camera
//Params: newPosition - the new position
//returns: none
void Camera::updatePosition(glm::vec3 newPosition) {
	_position = newPosition;
	updateView();
}


//Handles all inputs related to the camera
//Params: None
//returns: nothing
void Camera::cameraInputs() {
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		updatePosition(glm::vec3(_position.x, _position.y, _position.z + 0.1f));
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		updatePosition(glm::vec3(_position.x, _position.y, _position.z - 0.1f));
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		updatePosition(glm::vec3(_position.x + 0.1f, _position.y, _position.z));
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		updatePosition(glm::vec3(_position.x - 0.1f, _position.y, _position.z));
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
		_angleX -= 0.5f;
		updateView();
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
		_angleX += 0.5f;
		updateView();
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {
		_angleY += 0.5f;
		updateView();
	}
	if (glfwGetKey(_window->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
		_angleY -= 0.5f;
		updateView();
	}
}