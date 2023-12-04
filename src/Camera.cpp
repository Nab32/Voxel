#include "Camera.h"

//Constructor for camera
//Params: position - the initial position of the camera
//returns: none
Camera::Camera(glm::vec3 position)
	: _cameraPosition(position){
	_view = glm::mat4(1.0f);
	_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	_angleX = 0;
	_angleY = 0;
	_angleZ = 0;
	fov = 45.0f;
	yaw = -90.0f;
	pitch = 0.0f;
	lastX = 800.0f / 2.0;
	lastY = 600.0 / 2.0;
	firstMouse = true;
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
	_view = glm::lookAt(_cameraPosition, _cameraPosition + _cameraFront, _cameraUp);
}


//Updates the current position of the camera
//Params: newPosition - the new position
//returns: none
void Camera::updatePosition(glm::vec3 newPosition) {
	_cameraPosition = newPosition;
	updateView();
}


//Handles all inputs related to the camera
//Params: None
//returns: nothing
void Camera::cameraInputs(GLFWwindow* window) {
	float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    const float cameraSpeed = 5.5f * deltaTime; // adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        _cameraPosition += cameraSpeed * _cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        _cameraPosition -= cameraSpeed * _cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        _cameraPosition -= glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        _cameraPosition += glm::normalize(glm::cross(_cameraFront, _cameraUp)) * cameraSpeed;
	updateView();
}