// Copyright © 2014-2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <stdio.h>
#include <stdlib.h>

#include <gho/math.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  ++nb_fail;
  nb_fail -= gho_test(gho_min(1u, 7u) == 1, "gho_min(1u, 7u) fails!\n\n");
  
  ++nb_fail;
  nb_fail -= gho_test(gho_min(1, -7) == -7, "gho_min(1, -7) fails!\n\n");
  
  ++nb_fail;
  nb_fail -= gho_test(gho_max(7u, 6u) == 7, "gho_max(7u, 6u) fails!\n\n");
  
  ++nb_fail;
  nb_fail -= gho_test(gho_max(1, -7) == 1, "gho_max(1, -7) fails!\n\n");
  
  ++nb_fail;
  nb_fail -= gho_test(gho_ceil_div(5, 2) == 3, "gho_ceil_div(5, 2) fails!\n\n");
  
  ++nb_fail;
  nb_fail -= gho_test(gho_floor_div(5, 2) == 2, "gho_floor_div(5, 2) fails!\n\n");
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
