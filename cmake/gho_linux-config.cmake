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


# Determine if platform is Linux or not

# GHO_LINUX_FOUND - Platform is Linux
# GHO_LINUX_MACRO - Macro to define


set(GHO_LINUX_MACRO "gho_linux")

if ("${CMAKE_SYSTEM_NAME}" MATCHES ".*Linux.*")
	
	set(GHO_LINUX_FOUND "TRUE")
	
	add_definitions("-D${GHO_LINUX_MACRO}")
	
	message(STATUS "Platform is Linux")
	
else()
	
	set(GHO_LINUX_FOUND "FALSE")
	
	message(STATUS "Platform is not Linux")
	
endif()
