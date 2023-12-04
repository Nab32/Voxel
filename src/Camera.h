#pragma once
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "constant.h"


class Camera {
public:
	Camera(glm::vec3 position);
	glm::mat4 getView();
	void updateView();
	void updatePosition(glm::vec3 newPosition);
private:
	glm::mat4 _view;
	glm::vec3 _position;
};