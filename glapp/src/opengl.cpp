#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"
#include "app/app.h"

void onResize(int width, int height){
    std::cout << "onResize width = " << width << " ,height = " << height << std::endl;
}

void onKey(int key, int scancode, int action, int mods){
    std::cout << "onKey:" << key << "," << scancode << "," << action << "," << mods << std::endl;
}

int main(){
    if (!sApp->init()){
        std::cout << " init error " << std::endl;
        return 0;
    }

    sApp->setResizeCallback(onResize);
    sApp->setOnKeyCallback(onKey);

    GL_CALL(glViewport(0,0,400,300));
    GL_CALL(glClearColor(0.5f,0.2f,0.3f,1.0f));

    while (sApp->update()){
        GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    }
    
    sApp->destroy();
    return 0;
}




