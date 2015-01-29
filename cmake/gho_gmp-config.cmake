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


# Try to find the GMP library

# GHO_GMP_FOUND       - System has GMP library
# GHO_GMP_INCLUDE_DIR - The GMP include directory
# GHO_GMP_LIBRARY     - Library needed to use GMP

# GHO_GMP_MACRO       - System has not GMP library


find_library(GHO_GMP_LIBRARY gmp)
find_file(GHO_GMP_INCLUDE_DIR "gmp.h")

set(GHO_GMP_MACRO "gho_with_gmp")

if (GHO_GMP_LIBRARY AND GHO_GMP_INCLUDE_DIR)
	
	string(REPLACE "/gmp.h" "" GHO_GMP_INCLUDE_DIR ${GHO_GMP_INCLUDE_DIR})
	
	set(GHO_GMP_FOUND "TRUE")
	
	include_directories(${GHO_GMP_INCLUDE_DIR})
	
	add_definitions("-D${GHO_GMP_MACRO}")
	
	message(STATUS "Library GMP found =) ${GHO_GMP_INCLUDE_DIR} | ${GHO_GMP_LIBRARY}")
	
else()
	
	set(GHO_GMP_FOUND "FALSE")
	
	message(STATUS "Library GMP not found :(")
	
endif()
