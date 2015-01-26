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

#include <gho/int.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  nb_fail += 2;
  {
    int i = gho_int_create();

    printf("i =");
    gho_int_fprinti(stdout, &i, 1);
    printf("\n");
    
    nb_fail -= gho_test(i == 0, "gho_int_create fails!\n");
    
    i = 42;
    
    printf("i =");
    char* out = gho_c_str_create();
    gho_int_sprinti(&out, &i, 1);
    printf("%s", out);
    printf("\n");
    gho_c_str_destroy(&out);
    
    int c  = gho_int_copy(&i);
    printf("c = %i\n", c);
    
    printf("i == c = %i\n", i == c);
    
    nb_fail -= gho_test(i == c, "gho_int_copy fails!\n");
    
    gho_string_t s = gho_int_to_string(&i);
    printf("s = ");
    gho_string_print(&s);
    printf("\n");
    gho_string_destroy(&s);
    
    gho_int_destroy(&i);
    gho_int_destroy(&c);
  }
  printf("\n");
  
  // int gho_int_fread(FILE* file);
  {
    FILE* file = fopen("/proc/meminfo", "r");
    if (file != NULL) {
      gho_string_t tmp = gho_string_fread(file);
      gho_string_destroy(&tmp);
      printf("fread = %i\n", gho_int_fread(file));
    }
    fclose(file); file = NULL;
  }
  
  // int gho_int_sread(const char** c_str);
  nb_fail += 2;
  {
    const char* in = "21.73";
    int i = gho_int_sread(&in);
    printf("sread = %i | ", i);
    nb_fail -= gho_test(i == 21, "gho_int_sread fails!\n");
    printf("not read = %s\n", in);
    nb_fail -= gho_test(gho_c_str_equal(in, ".73"), "gho_int_sread fails!\n");
  }
  printf("\n");
  nb_fail += 2;
  {
    const char* in = "-73a";
    int i = gho_int_sread(&in);
    printf("sread = %i | ", i);
    nb_fail -= gho_test(i == -73, "gho_int_sread fails!\n");
    printf("not read = %s\n", in);
    nb_fail -= gho_test(gho_c_str_equal(in, "a"), "gho_int_sread fails!\n");
  }
  printf("\n");
  nb_fail += 2;
  {
    const char* in = "42";
    int i = gho_int_sread(&in);
    printf("sread = %i | ", i);
    nb_fail -= gho_test(i == 42, "gho_int_sread fails!\n");
    printf("not read = %s\n", in);
    nb_fail -= gho_test(gho_c_str_equal(in, ""), "gho_int_sread fails!\n");
  }
  printf("\n");
  
  // gho_uint gho_uint_sread(const char** c_str);
  nb_fail += 2;
  {
    const char* in = "21.73";
    unsigned int i = gho_uint_sread(&in);
    printf("sread = %i | ", i);
    nb_fail -= gho_test(i == 21, "gho_int_sread fails!\n");
    printf("not read = %s\n", in);
    nb_fail -= gho_test(gho_c_str_equal(in, ".73"), "gho_int_sread fails!\n");
  }
  printf("\n");
  nb_fail += 2;
  {
    const char* in = "42";
    unsigned int i = gho_uint_sread(&in);
    printf("sread = %i | ", i);
    nb_fail -= gho_test(i == 42, "gho_int_sread fails!\n");
    printf("not read = %s\n", in);
    nb_fail -= gho_test(gho_c_str_equal(in, ""), "gho_int_sread fails!\n");
  }
  printf("\n");
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
