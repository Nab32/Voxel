#pragma once
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "constant.h"
#include "Window.h"


class Camera {
public:
	Camera(glm::vec3 position, Window* window);
	glm::mat4 getView();
	void updateView();
	void updatePosition(glm::vec3 newPosition);
	void cameraInputs();
private:
	Window* _window;
	glm::mat4 _view;
	float _angleX, _angleY, _angleZ;
	glm::vec3 _position;
};