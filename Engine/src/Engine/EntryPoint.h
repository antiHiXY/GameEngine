#pragma once

#ifdef ENGN_PLATFORM_WINDOWS 

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
    Engine::Log::Init();
    ENGN_CORE_WARN("Initialized Log!");
    ENGN_INFO("Hi!");

    auto app = Engine::CreateApplication();
    app->Run();
    delete app;
}

#endif 

