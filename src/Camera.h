#pragma once
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "constant.h"
#include "Window.h"

extern float deltaTime, lastFrame;

class Camera {
public:
	Camera(glm::vec3 position);
	glm::mat4 getView();
	void updateView();
	void updatePosition(glm::vec3 newPosition);
	void cameraInputs(GLFWwindow* window);
private:
	glm::mat4 _view;
	float _angleX, _angleY, _angleZ;
	glm::vec3 _cameraPosition;
	glm::vec3 _cameraFront;
	bool firstMouse = true;
	float yaw;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch;
	float lastX;
	float lastY;
	float fov;
	glm::vec3 _cameraUp;
};