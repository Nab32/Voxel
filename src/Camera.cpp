#include "Camera.h"


//Constructor for camera
//Params: position - the initial position of the camera
//returns: none
Camera::Camera(glm::vec3 position)
	: _position(position){
	_view = glm::mat4(1.0f);
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
	_view = glm::translate(_view, _position);
}


//Updates the current position of the camera
//Params: newPosition - the new position
//returns: none
void Camera::updatePosition(glm::vec3 newPosition) {
	_position = newPosition;
	updateView();
}