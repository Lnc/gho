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

#include <gho/matrix/int.h>
#include <gho/matrix/lint.h>
#include <gho/matrix/llint.h>
#include <gho/matrix/mpz_t.h>
#include <gho/test.h>


int main(int argc, char** argv) {
  
  printf("\n");
  
  if (argc > 1) { printf("%s: argv are ignored\n", argv[0]); }

  int nb_fail = 0;
  
  ++nb_fail;
  {
    gho_matrix_int_t m = gho_matrix_int_create_n_m(3, 4);
    
    printf("After creation =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.nb_row == 3 && m.nb_col == 4,
                        "gho_matrix_int_create_n_m fails!\n\n");
    
    gho_matrix_int_destroy(&m);
  }
  printf("\n");
  
  nb_fail += 21;
  {
    gho_matrix_int_t m = gho_matrix_int_create();
    
    printf("After creation =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    printf("\n");
    
    gho_matrix_int_add_row_before(&m, 0);
    gho_matrix_int_add_col_before(&m, 0);
    m.array[0][0] = 1;
    
    printf("After add =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[0][0] == 1, "gho_matrix_int_add fails!\n");
    printf("\n");
    
    gho_matrix_int_add_row_after(&m, 0);
    gho_matrix_int_add_col_after(&m, 0);
    m.array[0][1] = 2;
    m.array[1][0] = 3;
    m.array[1][1] = 4;
    
    printf("After add =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[0][0] == 1, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[0][1] == 2, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[1][0] == 3, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[1][1] == 4, "gho_matrix_int_add fails!\n");
    printf("\n");
    
    gho_matrix_int_add_row_after(&m, 0);
    gho_matrix_int_add_col_after(&m, 0);
    
    printf("After add =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[0][0] == 1, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[0][2] == 2, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[2][0] == 3, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[2][2] == 4, "gho_matrix_int_add fails!\n");
    printf("\n");
    
    gho_matrix_int_add_row_after(&m, 2);
    gho_matrix_int_add_col_after(&m, 2);
    
    printf("After add =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[0][0] == 1, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[0][2] == 2, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[2][0] == 3, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[2][2] == 4, "gho_matrix_int_add fails!\n");
    printf("\n");
    
    gho_matrix_int_add_row_before(&m, 0);
    gho_matrix_int_add_col_before(&m, 0);
    
    printf("After add =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[1][1] == 1, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[1][3] == 2, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[3][1] == 3, "gho_matrix_int_add fails!\n");
    nb_fail -= gho_test(m.array[3][3] == 4, "gho_matrix_int_add fails!\n");
    printf("\n");
    
    gho_matrix_int_remove_row(&m, 2);
    gho_matrix_int_remove_col(&m, 2);
    
    printf("After remove =\n");
    gho_matrix_int_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.array[1][1] == 1, "gho_matrix_int_remove fails!\n");
    nb_fail -= gho_test(m.array[1][2] == 2, "gho_matrix_int_remove fails!\n");
    nb_fail -= gho_test(m.array[2][1] == 3, "gho_matrix_int_remove fails!\n");
    nb_fail -= gho_test(m.array[2][2] == 4, "gho_matrix_int_remove fails!\n");
    printf("\n");
    
    gho_matrix_int_destroy(&m);
  }
  printf("\n");
  
  #ifdef gho_with_gmp
  ++nb_fail;
  {
    gho_matrix_mpz_t m = gho_matrix_mpz_create_n_m(4, 3);
    
    printf("After creation =\n");
    gho_matrix_mpz_print(&m);
    printf("\n");
    
    nb_fail -= gho_test(m.nb_row == 4 && m.nb_col == 3,
                        "gho_matrix_mpz_create_n_m fails!\n\n");
    
    gho_matrix_mpz_destroy(&m);
  }
  printf("\n");
  #endif
  
  printf("%s ", argv[0]);
  printf("fails = %d\n", nb_fail);
  printf("\n");
  
  return nb_fail;
}
