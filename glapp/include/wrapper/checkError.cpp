#include "checkError.h"
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <assert.h>

/**
 * #define GL_NO_ERROR 0
 * #define GL_INVALID_ENUM 0x0500
 * #define GL_INVALID_VALUE 0x0501
 * #define GL_INVALID_OPERATION 0x0502
 * #define GL_OUT_OF_MEMORY 0x0505
 */
void checkError(){
    GLenum error = glGetError();
    std::string msg = "";
    if (error == GL_NO_ERROR){
        return;
    }
    switch (error)
    {
    case GL_INVALID_ENUM:
        msg = "INVALID_ENUM";
        break;
    case GL_INVALID_VALUE:
        msg = "INVALID_VALUE";
        break;
    case GL_INVALID_OPERATION:
        msg = "INVALID_OPERATION";
        break;
    case GL_OUT_OF_MEMORY:
        msg = "OUT_OF_MEMORY";
        break;
    default:
        msg = "UNKNOW";
        break;
    }
    std::cout << "check error = " << error << " , msg = " << msg << std::endl; 
    assert(false);
}
