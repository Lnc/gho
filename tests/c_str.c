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

#include <gho/c_str.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  nb_fail += 3;
  {
    char* c_str = gho_c_str_create();
    
    nb_fail -= gho_test(
      gho_c_str_size(c_str) == 0,
      "gho_c_str_create fails (size != 0)\n"
    );
    
    nb_fail -= gho_test(
      gho_c_str_empty(c_str),
      "gho_c_str_create fails (empty != true)\n"
    );
    
    nb_fail -= gho_test(
      gho_c_str_equal(c_str, ""),
      "gho_c_str_create fails\n"
    );
    
    gho_c_str_destroy(&c_str);
  }
  
  nb_fail += 3;
  nb_fail += 2;
  {
    char* c_str = gho_c_str_create_from_c_str("Created from C string");
    
    nb_fail -= gho_test(
      gho_c_str_size(c_str) == 21,
      "gho_c_str_create_from_c_str fails (size != 21)\n"
    );
    
    nb_fail -= gho_test(
      gho_c_str_empty(c_str) == false,
      "gho_c_str_create_from_c_str fails (empty != false)\n"
    );
    
    nb_fail -= gho_test(
      gho_c_str_equal(c_str, "Created from C string"),
      "gho_c_str_create_from_c_str fails\n"
    );
    
    printf("gho_c_str_fprinti =");
    gho_c_str_fprinti(stdout, c_str, 1);
    printf("\n");
    
    gho_c_str_reset(&c_str);
    
    nb_fail -= gho_test(
      gho_c_str_size(c_str) == 0,
      "gho_c_str_reset fails (size != 0)\n"
    );
    
    nb_fail -= gho_test(
      gho_c_str_equal(c_str, ""),
      "gho_c_str_reset fails\n"
    );
    
    gho_c_str_destroy(&c_str);
  }
  printf("\n");
  
  nb_fail += 2;
  {
    char* c_str = gho_c_str_create_from_c_str("Test ");
    
    gho_c_str_add_char(&c_str, 'a');
    gho_c_str_add_char(&c_str, 'd');
    gho_c_str_add_char(&c_str, 'd');
    
    nb_fail -= gho_test(
      gho_c_str_equal(c_str, "Test add"),
      "gho_c_str_add_char fails\n"
    );
    
    gho_c_str_remove_last(&c_str);
    gho_c_str_remove_last(&c_str);
    gho_c_str_remove_last(&c_str);
    gho_c_str_add(&c_str, "remove");
    
    nb_fail -= gho_test(
      gho_c_str_equal(c_str, "Test remove"),
      "gho_c_str_add_char fails\n"
    );
    
    gho_c_str_destroy(&c_str);
  }
  
  {
    printf("// Read \"/etc/resolv.conf\" (if exists) by words:\n");
    FILE* file = fopen("/etc/resolv.conf", "r");
    if (file != NULL) {
      while (feof(file) == 0) {
        char* c_str = gho_c_str_fread(file);
        printf("\""); gho_c_str_print(c_str); printf("\"\n");
        gho_c_str_destroy(&c_str);
      }
      printf("\n");
    }
    fclose(file);
  }
  
  {
    printf("// Read \"/etc/resolv.conf\" (if exists) by lines:\n");
    FILE* file = fopen("/etc/resolv.conf", "r");
    if (file != NULL) {
      while (feof(file) == 0) {
        char* c_str = gho_c_str_get_line(file);
        printf("\""); gho_c_str_print(c_str); printf("\"\n");
        gho_c_str_destroy(&c_str);
      }
      printf("\n");
    }
    fclose(file);
  }
  
  {
    const char* const in = "String";
    const char* begin = in;
    const char* const end = in + gho_c_str_size(in);
    printf("// Read:\n");
    while (begin != end) {
      char* c_str = gho_c_str_sread(&begin);
      printf("\""); gho_c_str_print(c_str); printf("\"\n");
      gho_c_str_destroy(&c_str);
    }
  }
  printf("\n");
  
  {
    const char* const in = "A C string";
    const char* begin = in;
    const char* const end = in + gho_c_str_size(in);
    printf("// Read:\n");
    while (begin != end) {
      char* c_str = gho_c_str_sread(&begin);
      printf("\""); gho_c_str_print(c_str); printf("\"\n");
      gho_c_str_destroy(&c_str);
    }
  }
  printf("\n");
  
  {
    const char* const in = "A C string\nAn another C string";
    const char* begin = in;
    const char* const end = in + gho_c_str_size(in);
    printf("// Read:\n");
    while (begin != end) {
      char* c_str = gho_c_str_get_line_from_c_str(&begin);
      printf("\""); gho_c_str_print(c_str); printf("\"\n");
      gho_c_str_destroy(&c_str);
    }
  }
  printf("\n");
  
  {
    const char* const in = "A C string|An another C string";
    const char* begin = in;
    const char* const end = in + gho_c_str_size(in);
    printf("// Read:\n");
    while (begin != end) {
      char* c_str = gho_c_str_get_line_from_c_str_delimiter(&begin, '|');
      printf("\""); gho_c_str_print(c_str); printf("\"\n");
      gho_c_str_destroy(&c_str);
    }
  }
  printf("\n");
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
