cmake_minimum_required(VERSION 3.2)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CID "GNU")
	elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CID "MSVC")
	else ()
		message(FATAL_ERROR "you compiler is ${CMAKE_CXX_COMPLER_ID} which is not work use MSVC or GCC instead.")
	endif()
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/deps/Windows/SFML-2.5.1/${CID}/lib/cmake/SFML")
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
	"deps/Windows/SFML-2.5.1/${CID}/bin/*.dll"
)

add_executable(SpaceInvaders ${src_files})

target_link_libraries(SpaceInvaders sfml-graphics sfml-network sfml-audio sfml-system)

file(COPY "src/Assets" DESTINATION ".")
file(COPY ${dll_files} DESTINATION ".")
