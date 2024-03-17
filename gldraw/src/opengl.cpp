#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <assert.h>
#include "wrapper/checkError.h"
#include "app/app.h"

GLuint vao,program;

void onResize(int width, int height){
    std::cout << "onResize width = " << width << " ,height = " << height << std::endl;
    GL_CALL(glViewport(0,0,width,height));
}

void onKey(int key, int scancode, int action, int mods){
    std::cout << "onKey:" << key << "," << scancode << "," << action << "," << mods << std::endl;
}

void prepareSingleBuffer(){
    //定义位置信息
    float position[] = {
        -0.5f , -0.5f , 0.0f,
        0.5f , -0.5f , 0.0f,
        0.0f , 0.5f , 0.0f
    };
    
    GLuint posVbo = 0;
    //生成位置vbo
    GL_CALL(glGenBuffers(1,&posVbo));
    //绑定位置vbo
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,posVbo));
    //填充位置vbo数据
    GL_CALL(glBufferData(GL_ARRAY_BUFFER,sizeof(position),position,GL_STATIC_DRAW));


    float color[] = {
        1.0f , 0.0f , 0.0f,
        0.0f , 1.0f , 0.0f,
        0.0f , 0.0f , 1.0f
    };
    
    GLuint colorVbo = 0;
    GL_CALL(glGenBuffers(1,&colorVbo));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,colorVbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER,sizeof(color),color,GL_STATIC_DRAW));

    //生成vao并且绑定
    vao = 0;
    GL_CALL(glGenVertexArrays(1,&vao));
    GL_CALL(glBindVertexArray(vao));

    //描述位置信息，只有绑定了vbo，下面的属性描述才会与此vbo相关
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,posVbo));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0));

    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,colorVbo));
    //索引位置要基于之前的累加
    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0));

    //解绑定vao
    GL_CALL(glBindVertexArray(0));
}

void prepareInterLeaveBuffer(){
    float vertex[] = {
        -0.5f , -0.5f , 0.0f, 1.0f , 0.0f , 0.0f ,
        0.5f , -0.5f , 0.0f, 0.0f , 1.0f , 0.0f ,
        0.0f , 0.5f , 0.0f, 0.0f , 0.0f , 1.0f 
    };

    GLuint vbo = 0;
    GL_CALL(glGenBuffers(1,&vbo));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,vbo));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW));

    vao = 0;
    GL_CALL(glGenVertexArrays(1,&vao));
    GL_CALL(glBindVertexArray(vao));

    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,vbo));
    GL_CALL(glEnableVertexAttribArray(0));
    GL_CALL(glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)0));

    GL_CALL(glEnableVertexAttribArray(1));
    GL_CALL(glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)(3 * sizeof(float))));

    GL_CALL(glBindVertexArray(0));
}

void prepareShader(){
    const char* vertexShaderSource = 
    "#version 460 core\n"
    "layout (location=0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
    "}\0";

    const char* fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
    "}\n\0";

    //创建shader程序
    GLuint vertex,fragmnet;
    vertex =  glCreateShader(GL_VERTEX_SHADER);
    fragmnet = glCreateShader(GL_FRAGMENT_SHADER);

    //为shader程序输入shader代码
    glShaderSource(vertex,1,&vertexShaderSource,NULL);
    glShaderSource(fragmnet,1,&fragmentShaderSource,NULL);

    int success = 0;
    //用于承接错误的数组
    char infoLog[1024];


    //执行shader代码编译
    glCompileShader(vertex);
    //检查vertex编译结果
    glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
    if (!success){
        glGetShaderInfoLog(vertex,1024,NULL,infoLog);
        std::cout << "Error:SHADER COMPILE ERROR[vertex] " << "\n" << infoLog << std::endl;
    }

    glCompileShader(fragmnet);
    //检查fragmnet编译结果
    glGetShaderiv(fragmnet,GL_COMPILE_STATUS,&success);
    if (!success){
        glGetShaderInfoLog(fragmnet,1024,NULL,infoLog);
        std::cout << "Error:SHADER COMPILE ERROR[fragment] " << "\n" << infoLog << std::endl;
    }

    //创建program容器
    program = 0;
    program = glCreateProgram();

    //将vs与fs编译好的结果放到program容器
    glAttachShader(program,vertex);
    glAttachShader(program,fragmnet);

    //执行program的链接操作，形成可执行shader
    glLinkProgram(program);

    //检查链接结果
    glGetProgramiv(program,GL_LINK_STATUS,&success);
      if (!success){
        glGetProgramInfoLog(program,1024,NULL,infoLog);
        std::cout << "Error:SHADER LINK ERROR " << "\n" << infoLog << std::endl;
    }

    //清理
    glDeleteShader(vertex);
    glDeleteShader(fragmnet);

    // glDeleteProgram(program);
}

void render(){
    //清理画布
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    //设置使用的shader程序
    glUseProgram(program);
    //绑定绘制的vao
    glBindVertexArray(vao);
    //执行绘制操作
    glDrawArrays(GL_TRIANGLES,0,3);
}

int main(){
    if (!sApp->init()){
        std::cout << " init error " << std::endl;
        return 0;
    }

    sApp->setResizeCallback(onResize);
    sApp->setOnKeyCallback(onKey);

    GL_CALL(glViewport(0,0,800,600));
    GL_CALL(glClearColor(0.5f,0.2f,0.3f,1.0f));

    prepareShader();
    // prepareSingleBuffer();
    prepareInterLeaveBuffer();

    while (sApp->update()){
       render();
    }
    
    sApp->destroy();
    return 0;
}




