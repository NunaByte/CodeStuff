#CMakeLists.txt
cmake_minimum_required (VERSION 3.6)
project(example)

add_executable(DiscordBot source.cpp)

#Add these two lines
add_subdirectory(deps/sleepy-discord)
target_link_libraries(DiscordBot/deps sleepy-discord)