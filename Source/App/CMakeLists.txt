set(SOURCES
    Source/Main.cpp
)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_link_libraries(${PROJECT_NAME} Core)
target_include_directories(${PROJECT_NAME} PRIVATE Source)