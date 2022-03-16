cmake_minimum_required(VERSION 3.22)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

if(UNIX)
    find_package(SFML COMPONENTS graphics audio network system REQUIRED)
elseif(WIN32)
    include_directories(deps/Windows/SFML-2.5.1/bin)
    include_directories(deps/Windows/SFML-2.5.1/include)
    include_directories(deps/Windows/SFML-2.5.1/lib)
endif()

file(
        GLOB
        src_files
        "src/*.cpp"
)

add_executable(SpaceInvaders ${src_files})

target_link_libraries(SpaceInvaders sfml-graphics sfml-network sfml-audio sfml-system)

file(COPY "src/Assets" DESTINATION ".")
