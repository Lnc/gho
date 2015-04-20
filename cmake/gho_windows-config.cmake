# Copyright © 2014, 2015 Lénaïc Bagnères, hnc@singularity.fr
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


# Determine if platform is WINDOWS or not

# GHO_WINDOWS_FOUND - Platform is WINDOWS
# GHO_WINDOWS_MACRO - Macro to define


set(GHO_WINDOWS_MACRO "gho_windows")

if (WIN32 OR WIN64)
	
	set(GHO_WINDOWS_FOUND "TRUE")
	
	add_definitions("-D${GHO_WINDOWS_MACRO}")
	
	link_libraries(shlwapi)
	
	message(STATUS "Platform is Windows :(")
	
else()
	
	set(GHO_WINDOWS_FOUND "FALSE")
	
	message(STATUS "Platform is not Windows =)")
	
endif()
