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

#include <gho/vector/any.h>
#include <gho/vector/int.h>
#include <gho/vector/llint.h>
#include <gho/vector/size_t.h>
#include <gho/vector/start_and_size.h>
#include <gho/vector/string.h>
#include <gho/vector/uint.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  ++nb_fail;
  {
    gho_vector_int_t v = gho_vector_int_create();
    
    printf("After creation = ");
    gho_vector_int_print(&v);
    printf("\n");
    
    gho_vector_int_add_(&v, 21);
    gho_vector_int_add_(&v, 7);
    gho_vector_int_add_(&v, 42);
    gho_vector_int_add_(&v, 73);
    gho_vector_int_add_(&v, -1);
    gho_vector_int_add_(&v, -8);
    
    printf("After add      = ");
    gho_vector_int_print(&v);
    printf("\n");
    
    nb_fail -= gho_test(gho_vector_int_empty(&v) == false,
                        "gho_vector_int_add_ fails!\n");
    
    gho_vector_int_sort(&v);
    
    printf("After sort     = ");
    gho_vector_int_print(&v);
    printf("\n");
    
    for (size_t i = 0; i < v.size - 1; ++i) {
      if (v.array[i] > v.array[i + 1]) {
        nb_fail -= gho_test(false, "gho_vector_int_sort fails!\n");
      }
    }
    
    gho_vector_int_destroy(&v);
  }
  printf("\n");
  
  ++nb_fail;
  {
    gho_vector_string_t v = gho_vector_string_create();
    
    printf("After creation = ");
    gho_vector_string_print(&v);
    printf("\n");
    
    gho_vector_string_add_c_str(&v, "A");
    gho_vector_string_add_c_str(&v, "vector");
    gho_vector_string_add_c_str(&v, "of");
    gho_vector_string_add_c_str(&v, "string");
    
    printf("After add      = ");
    gho_vector_string_print(&v);
    printf("\n");
    
    nb_fail -= gho_test(gho_vector_string_empty(&v) == false,
                        "gho_vector_string_add_c_str fails!\n");
    
    gho_vector_string_sort(&v);
    
    printf("After sort     = ");
    gho_vector_string_print(&v);
    printf("\n");
    
    gho_vector_string_destroy(&v);
  }
  printf("\n");
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
