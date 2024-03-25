#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "app.h"
#include "iostream"

App* App::mInstance = nullptr;

App* App::getInstance(){
    if (mInstance == nullptr){
        mInstance = new App();
    }
    return mInstance;
}

App::App(){

}

App::~App(){

}

bool App::init(const int& width,const int& height){
    mWidth = width;
    mHeight = height;


    if (!glfwInit()){
        std::cout << "glfwInit failure" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    mWindow = glfwCreateWindow(mWidth,mHeight,"OpenGL APP",NULL,NULL);
    if (!mWindow){
        std::cout << "glfwCreateWindow failure" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(mWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "gladLoadGLLoader failure" << std::endl;
        return false;
    }

    glfwSetWindowSizeCallback(mWindow,onWindowSizeCallback);
    glfwSetKeyCallback(mWindow,onWindowKeyCallback);
    glfwSetWindowUserPointer(mWindow,this);
    
    return true;
}

bool App::update(){
    if (!mWindow){
        std::cout << "update mWindow is null" << std::endl;
        return false;
    }
    
    if (glfwWindowShouldClose(mWindow)){
        std::cout << "update mWindow should close" << std::endl;
        return false;
    }

    glfwPollEvents();
    glfwSwapBuffers(mWindow);
    return true;
}

void App::destroy(){
    glfwTerminate();
}

void App::setResizeCallback(OnResizeCallback callback){
    mOnResizeCallback = callback;
}

void App::onWindowSizeCallback(GLFWwindow* window, int width, int height){
    App* self = (App*)glfwGetWindowUserPointer(window);
    if (self->mOnResizeCallback != nullptr){
        self->mOnResizeCallback(width,height);
    }
}

void App::setOnKeyCallback(OnKeyCallback callback){
    mOnKeyCallback = callback;
}

void App::onWindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
 App* self = (App*)glfwGetWindowUserPointer(window);
    if (self->mOnKeyCallback != nullptr){
        self->mOnKeyCallback(key, scancode, action, mods);
    }
}