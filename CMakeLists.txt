cmake_minimum_required(VERSION 3.22)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_DIR deps\\Windows\\SFML-2.5.1\\lib\\cmake\\SFML)
    include_directories(deps\\Windows\\SFML-2.5.1\\include)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio network system REQUIRED)

file(
        GLOB
        src_files
        "src/*.cpp"
)

file(
	GLOB
	dll_files
	"deps/Windows/SFML-2.5.1/bin/*"
)

add_executable(SpaceInvaders ${src_files})

target_link_libraries(SpaceInvaders sfml-graphics sfml-network sfml-audio sfml-system)

file(COPY "src/Assets" DESTINATION ".")
file(COPY ${dll_files} DESTINATION ".")
