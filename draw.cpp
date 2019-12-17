#include <glad/glad.h>
#include <GLFW/glfw3.h>

void draw () {
  //vertices for triangle
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  //create object for vertices data buffer
  unsigned int dataBuffer;
  glGenBuffers(1, &dataBuffer);

  //bind object to dataBuffer
  glBindBuffer(GL_ARRAY_BUFFER, dataBuffer);

  //push data
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


}