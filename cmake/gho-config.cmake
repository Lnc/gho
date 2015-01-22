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


# Try to find the gho library

# GHO_FOUND       - System has gho library
# GHO_INCLUDE_DIR - The gho include directory


find_file(GHO_INCLUDE_DIR "gho/gho.h")

if (GHO_INCLUDE_DIR)
	
	set(GHO_FOUND "TRUE")
	
	message(STATUS "Library gho found =) ${GHO_INCLUDE_DIR}")
	
else()
	
	set(GHO_FOUND "FALSE")
	
	message(STATUS "Library gho not found :(")
	
endif()
