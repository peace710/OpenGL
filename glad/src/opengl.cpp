#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(){

    if (!glfwInit()){
        std::cout << "glfw init faiulre" << std::endl;
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* window = glfwCreateWindow(800,600,"OpenGLGlad",NULL,NULL);
    if (window == NULL){
        std::cout << "glfw create window faiulre" << std::endl;
        return 0;
    }

    glfwMakeContextCurrent(window);

    //使用glad加载所有当前版本的OpenGL函数
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "gladLoadGLLoader faiulre" << std::endl;
        return 0;
    }

    while (!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glClearColor(0.2f,0.3f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;

}


