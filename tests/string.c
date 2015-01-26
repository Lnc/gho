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

#include <gho/string.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  ++nb_fail;
  {
    gho_string_t string = gho_string_create();
    
    nb_fail -= gho_test(
      gho_string_equal_c_str(&string, ""),
      "gho_string_create fails\n"
    );
    
    gho_string_destroy(&string);
  }
  
  ++nb_fail;
  ++nb_fail;
  {
    gho_string_t string = gho_string_create_from_c_str("Created from C string");
    
    nb_fail -= gho_test(
      gho_string_equal_c_str(&string, "Created from C string"),
      "gho_string_create_from_c_str fails\n"
    );
    
    printf("gho_string_fprinti =");
    gho_string_fprinti(stdout, &string, 1);
    printf("\n");
    
    gho_string_reset(&string);
    
    nb_fail -= gho_test(
      gho_string_equal_c_str(&string, ""),
      "gho_string_reset fails\n"
    );
    
    gho_string_destroy(&string);
  }
  printf("\n");
  
  ++nb_fail;
  {
    gho_string_t string = gho_string_create();
    gho_string_t string_moved = gho_string_create_from_c_str("To be moved");
    
    gho_string_absorb_(&string, &string_moved);
    
    nb_fail -= gho_test(
      gho_string_equal_c_str(&string, "To be moved"),
      "gho_string_absorb_ fails\n"
    );
    
    gho_string_destroy(&string);
  }
  
  ++nb_fail;
  {
    gho_string_t string = gho_string_create();
    gho_c_str_t string_moved = gho_c_str_create_from_c_str("To be moved");
    
    gho_string_absorb_c_str_(&string, &string_moved);
    
    nb_fail -= gho_test(
      gho_string_equal_c_str(&string, "To be moved"),
      "gho_string_absorb_c_str_ fails\n"
    );
    
    gho_string_destroy(&string);
  }
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
