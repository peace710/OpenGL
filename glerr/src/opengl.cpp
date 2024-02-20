#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"

void window_size_change_callback(GLFWwindow* window, int width, int height){
    std::cout << "window_size_change_callback width = " << width << " ,height = " << height << std::endl;
}

int main(){
    if (!glfwInit()){
        std::cout << "glfwInit failure" << std::endl;
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800,600,"OpenGL err",NULL,NULL);
    if (!window){
        std::cout << "glfwCreateWindow failure" << std::endl;
        return 0;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "gladLoadGLLoader failure" << std::endl;
        return 0;
    }


    GL_CALL(glViewport(0,0,400,300));
    GL_CALL(glClearColor(0.5f,0.2f,0.3f,1.0f));

    glfwSetWindowSizeCallback(window,window_size_change_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        // GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
        GL_CALL(glClear(-1));
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}




