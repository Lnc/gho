// Copyright © 2015 Inria, Written by Lénaïc Bagnères, lenaic.bagneres@inria.fr

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

#include <gho/now.h>
#include <gho/sleep.h>


int main() {

  long double start_seconds = gho_now_seconds();
  long double start_milliseconds = gho_now_milliseconds();
  
  printf("gho_sleep(1);\n");
  gho_sleep(1);
  
  printf("gho_millisleep(200);\n");
  gho_millisleep(200);
  
  long double end_seconds = gho_now_seconds();
  long double end_milliseconds = gho_now_milliseconds();
  
  printf("\n");
  printf("Seconds      = %Lf\n", end_seconds - start_seconds);
  printf("Microseconds = %Lf\n", end_milliseconds - start_milliseconds);
  
  return 0;
}
