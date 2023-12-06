#include "Camera.h"

//Constructor for camera
//Params: position - the initial position of the camera
//returns: none
Camera::Camera(glm::vec3 position)
	: _cameraPosition(position){
	_view = glm::mat4(1.0f);
	_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	_cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    WorldUp = _cameraUp;
    Yaw = -90.0f;
    Pitch = 0.0f;
    MouseSensitivity = 0.1f;
	updateView();
}

//sends back the view of the camera
//Params: none
//returns: _view
glm::mat4 Camera::getView() {
	return _view;
}

glm::vec3 Camera::getPosition() {
    return _cameraPosition;
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
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        _cameraPosition += _cameraUp * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        _cameraPosition -= _cameraUp * cameraSpeed;
	updateView();
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    _cameraFront = glm::normalize(front);
    // also re-calculate the Right and Up vector
    glm::vec3 Right = glm::normalize(glm::cross(_cameraFront, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    _cameraUp = glm::normalize(glm::cross(Right, _cameraFront));
    updateView();
}