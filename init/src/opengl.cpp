#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window,int width,int hegiht){
    std::cout << "framebuffer_size_callback:" << width << "," << hegiht << std::endl;
}

/**
 * key:字母按键码
 * scancode: 物理按键码
 * action: 按下或抬起
 * mods: 是否有shift或ctrl
*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    std::cout << "key_callback:" << key << "," << scancode << "," << action << "," << mods << std::endl;
    if (key == GLFW_KEY_W){

    }

    if (action == GLFW_PRESS){

    }

    if (action == GLFW_RELEASE){

    }

    if (mods == GLFW_MOD_CONTROL){

    }

    if (mods == GLFW_MOD_ALT){

    }

    if (mods == GLFW_MOD_SHIFT){
        
    }
}

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800,600,"OpenGL",NULL,NULL);

    if (window == NULL){
        std::cout << "create window failure" << std::endl;
        return 0;
    }

    glfwMakeContextCurrent(window);
    //注册窗体大小变化回调
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    //注册窗体按键响应回调
    glfwSetKeyCallback(window,key_callback);


    while (!glfwWindowShouldClose(window)){

        /* Swap front and back buffers */
        glfwSwapBuffers(window);


        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;

}


