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
	float MouseSensitivity;
	float Yaw;
	float Pitch;
	

	Camera(glm::vec3 position);
	glm::mat4 getView();
	void updateView();
	void updatePosition(glm::vec3 newPosition);
	void cameraInputs(GLFWwindow* window);
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	void updateCameraVectors();
	glm::vec3 getPosition();
private:
	glm::mat4 _view;
	float _angleX, _angleY, _angleZ;
	glm::vec3 _cameraPosition;
	glm::vec3 _cameraFront;
	glm::vec3 _cameraUp;
	glm::vec3 WorldUp;
};