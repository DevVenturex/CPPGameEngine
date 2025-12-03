#include "WindowService.h"

namespace Core
{
    WindowService::WindowService()
    {
        glfwInit();
        CreateWindow();
    }

    WindowService::~WindowService()
    {
        glfwTerminate();
    }

    void WindowService::OnUpdate()
    {
        GetWindow(m_PrimaryWindow)->OnUpdate();
    }

    void WindowService::CreateWindow()
    {
        auto window = std::make_unique<DefaultWindow>();
        if (m_PrimaryWindow == nullptr)
        {
            m_PrimaryWindow = window->GetHandle();
        }
        m_Windows.push_back(std::move(window));
    }

    Window *WindowService::GetWindow(GLFWwindow *windowId) const
    {
        for (auto& window : m_Windows)
        {
            if (auto result = dynamic_cast<Window*>(window.get()))
            {
                return result;
            }
        }
        return nullptr;
    }

    Window *WindowService::GetPrimaryWindow() const
    {
        return GetWindow(m_PrimaryWindow);
    }

    bool WindowService::ShouldPrimaryWindowClose() const
    {
        return glfwWindowShouldClose(m_PrimaryWindow);
    }

    void WindowService::DestroyPrimaryWindow()
    {
        GetWindow(m_PrimaryWindow)->Destroy();
        m_PrimaryWindow = nullptr;
    }
    
    DefaultWindow::DefaultWindow()
    {
        m_Handle = glfwCreateWindow(640, 480, "Default Window", nullptr, nullptr);
        glfwMakeContextCurrent(m_Handle);
    }
    
    DefaultWindow::~DefaultWindow()
    {
        Destroy();
    }
    
    void DefaultWindow::OnUpdate()
    {
        glfwPollEvents();
    }
    
    void DefaultWindow::Destroy()
    {
        glfwDestroyWindow(m_Handle);
        m_Handle = nullptr;
    }
    
    GLFWwindow *DefaultWindow::GetHandle() const
    {
        return m_Handle;
    }
    
    bool DefaultWindow::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Handle);
    }
}