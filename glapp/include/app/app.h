#pragma once

#include <cstdint>

#define sApp App::getInstance()

using OnResizeCallback = void(*)(int,int);
using OnKeyCallback = void(*)(int,int,int,int);

class GLFWwindow;

class App{
    public:
        ~App();

        bool init(const int& width = 800,const int& height = 600);

        bool update();

        void destroy();

        void setResizeCallback(OnResizeCallback callback);

        void setOnKeyCallback(OnKeyCallback callback);

        static void onWindowSizeCallback(GLFWwindow* window, int width, int height);

        static void onWindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        static App* getInstance();

        uint32_t getWidth() const { return mWidth; }

        uint32_t getHeight() const { return mHeight;}

    private:
        static App* mInstance;

        uint32_t mWidth{0};

        uint32_t mHeight{0};

        GLFWwindow* mWindow{nullptr};

        OnResizeCallback mOnResizeCallback{nullptr};

        OnKeyCallback mOnKeyCallback{nullptr};

        App();
};