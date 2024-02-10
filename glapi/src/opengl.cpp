#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void window_size_change_callback(GLFWwindow* window, int width, int height){
    std::cout << "window_size_change_callback :"<< width << "," << height << std::endl;
    glViewport(0,0,width,height);
}

int main(void)
{

    if (!glfwInit()){
        std::cout << "glfw init failure" << std::endl;
        return 0;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800,600,"Opengl Api",NULL,NULL);
    if (window == NULL){
        std::cout << "create window failure" << std::endl;
        return 0;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "gladLoadGLLoader failure" << std::endl;
        return 0;
    }

    glfwSetWindowSizeCallback(window,window_size_change_callback);

    glViewport(0,0,400,300);
    glClearColor(0.5f,0.2f,0.2f,1.0f);

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;

}


