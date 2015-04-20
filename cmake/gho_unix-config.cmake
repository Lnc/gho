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


# Determine if platform is UNIX or not

# GHO_UNIX_FOUND - Platform is UNIX
# GHO_UNIX_MACRO - Macro to define


set(GHO_UNIX_MACRO "gho_unix")

if (UNIX)
	
	set(GHO_UNIX_FOUND "TRUE")
	
	add_definitions("-D${GHO_UNIX_MACRO}")
	
	message(STATUS "Platform is UNIX")
	
else()
	
	set(GHO_UNIX_FOUND "FALSE")
	
	message(STATUS "Platform is not UNIX")
	
endif()
