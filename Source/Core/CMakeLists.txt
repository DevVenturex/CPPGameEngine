set(SOURCES
    Source/Core/Result.h
    Source/Core/Application.h
    Source/Core/Application.cpp
)

add_library(Core STATIC)

target_sources(Core PRIVATE ${SOURCES})

target_include_directories(Core PUBLIC Source)