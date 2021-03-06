# Copyright © 2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


cmake_minimum_required(VERSION 2.6)


# Release / Debug flags

	if (RELEASE STREQUAL "FALSE" OR RELEASE STREQUAL "DEBUG")
		set(RELEASE "FALSE")
	else()
		set(RELEASE "TRUE")
	endif()

	if (RELEASE)
		set(CMAKE_C_FLAGS "-O3 -DNDEBUG -march=native -ffast-math")
	else()
		set(CMAKE_C_FLAGS "-Og -g3")
	endif()

# General C++ flags
	# General
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -std=c99 -pedantic")
	# Thread support
	if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
	else()
		link_libraries(pthread)
		message(STATUS "Your compiler id \"${CMAKE_C_COMPILER_ID}\" is not GNU, OpenMP is disabled")
	endif()


# Get local directory where .cmake are
	set(FIND_PACKAGE_LOCAL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Get gho_include
	message(STATUS "---")
	execute_process(COMMAND "git" "submodule" "init")
	execute_process(COMMAND "git" "submodule" "update")

# GMP
	message(STATUS "---")
	find_package(gho_gmp PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Linux
	message(STATUS "---")
	find_package(gho_linux PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# OS X
	message(STATUS "---")
	find_package(gho_os_x PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# UNIX
	message(STATUS "---")
	find_package(gho_unix PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# Windows
	message(STATUS "---")
	find_package(gho_windows PATHS "${FIND_PACKAGE_LOCAL_PATH}" NO_DEFAULT_PATH)

# gho
	message(STATUS "---")
	set(gho_INCLUDE "./include")
	message(STATUS "Include gho = ${gho_INCLUDE}")
	include_directories("${gho_INCLUDE}")


# Build gho doxygen
	message(STATUS "---")
	find_package(Doxygen)
	if (DOXYGEN_FOUND)
		file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/doxygen")
		message(STATUS "Doxygen found =) ${DOXYGEN_EXECUTABLE}")
		add_custom_target(
			doxygen
			${DOXYGEN_EXECUTABLE}
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
			COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
	else()
		message(STATUS "Doxygen not found :(")
	endif()


# Compiler log
	message(STATUS "---")
	message(STATUS "C compiler = ${CMAKE_C_COMPILER}")
	if (RELEASE)
		message(STATUS "Release mode")
	else()
		message(STATUS "Debug mode")
	endif()
	message(STATUS "C flags    = ${CMAKE_C_FLAGS}")


# Executables & tests
	
	enable_testing()
	message(STATUS "---")
	
	# Valgrind
	find_program(VALGRIND_EXE NAMES valgrind)
	
	# Tests
	file(
		GLOB_RECURSE
		tests
		tests/*.c
	)
	foreach(test_source ${tests})
	
		# Get test name and source
		string(REPLACE ".c" "" test_name ${test_source})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests/" "test__" test_name ${test_name})
		
		message(STATUS "Add test ${test_name}")
		
		# Executable
		add_executable(${test_name} "${test_source}")
		if (GHO_GMP_FOUND)
			target_link_libraries(${test_name} ${GHO_GMP_LIBRARY})
		endif()
		
		# Test
		if (VALGRIND_EXE)
			add_test(${test_name} "${VALGRIND_EXE}" "./${test_name}")
		else()
			add_test(${test_name} "./${test_name}")
		endif()
		
	endforeach()


# Install
	# .h
	install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")
	# .cmake
	install(FILES cmake/gho-config.cmake DESTINATION lib/gho)
	install(FILES cmake/gho_gmp-config.cmake DESTINATION lib/gho_gmp)
	# Doxygen
	install(DIRECTORY build/doxygen DESTINATION share/gho)


# Little help
	message(STATUS "---")
	message(STATUS "You can execute:")
	message(STATUS "    make         # To compile gho tests")
	message(STATUS "    make test    # To execute tests")
	message(STATUS "    make install # To install library, include and CMake module")
	message(STATUS "                 # If you need root access:")
	message(STATUS "                 #     sudo make install")
	message(STATUS "                 #     su -c \"make install\"")
	if (DOXYGEN_FOUND)
		message(STATUS "    make doxygen # To generate the Doxygen")
	endif()

	message(STATUS "---")
