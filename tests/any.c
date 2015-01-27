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

#include <gho/any.h>
#include <gho/string.h>
#include <gho/int.h>
#include <gho/char.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  {
    gho_string_t s = gho_string_create_from_c_str("A gho_string");
    printf("string = "); gho_string_print(&s); printf("\n");
    
    gho_any_t a = gho_string_to_any(&s);
    printf("any    = "); gho_any_print(&a); printf("\n");
    
    gho_string_destroy(&s);
    gho_any_destroy(&a);
  }
  printf("\n");
  
  {
    const int i = 7;
    printf("int = "); gho_int_print(&i); printf("\n");
    
    gho_any_t a = gho_int_to_any(&i);
    printf("any = "); gho_any_print(&a); printf("\n");
    
    gho_any_destroy(&a);
  }
  printf("\n");
  
  {
    const char c = 'c';
    printf("char = "); gho_char_print(&c); printf("\n");
    
    gho_any_t a = gho_char_to_any(&c);
    printf("any  = "); gho_any_print(&a); printf("\n");
    
    gho_any_destroy(&a);
  }
  printf("\n");
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
