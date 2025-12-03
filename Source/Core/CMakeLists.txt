set(SOURCES
    Source/Core/Result.h
    Source/Core/Application.h
    Source/Core/Application.cpp
    Source/Core/Service.h
    Source/Core/WindowService.h
    Source/Core/WindowService.cpp
    Source/Core/ServiceLocator.h
    Source/Core/ServiceLocator.cpp
    Source/Core/Window.h
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

target_include_directories(Core PUBLIC Source)