#include <stdio.h>
#include <driver/uart.h>

#include "constants.h"
#include "constdecl.h"

OVERRIDE_CONST_TRUE(test_override_true);
OVERRIDE_CONST_FALSE(test_override_false);

void app_main()
{
  printf("\n\n\n\n\n\nstarting tests\n");

  printf("test: %d\n", config_test());

  printf("test_true(%d): %d == %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_TRUE
       , config_test_true() == CONSTANT_TRUE);
  printf("test_true(%d): %d < %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_TRUE
       , config_test_true() < CONSTANT_TRUE);
  printf("test_true(%d): %d <= %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_TRUE
       , config_test_true() <= CONSTANT_TRUE);
  printf("test_true(%d): %d > %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_TRUE
       , config_test_true() > CONSTANT_TRUE);
  printf("test_true(%d): %d >= %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_TRUE
       , config_test_true() >= CONSTANT_TRUE);
  printf("test_true(%d): %d < %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_FALSE
       , config_test_true() < CONSTANT_FALSE);
  printf("test_true(%d): %d <= %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_FALSE
       , config_test_true() <= CONSTANT_FALSE);
  printf("test_true(%d): %d > %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_FALSE
       , config_test_true() > CONSTANT_FALSE);
  printf("test_true(%d): %d >= %d: %d\n"
       , config_test_true(), config_test_true(), CONSTANT_FALSE
       , config_test_true() >= CONSTANT_FALSE);

  printf("test_false(%d): %d == %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_FALSE
       , config_test_false() == CONSTANT_FALSE);
  printf("test_false(%d): %d < %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_FALSE
       , config_test_false() < CONSTANT_FALSE);
  printf("test_false(%d): %d <= %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_FALSE
       , config_test_false() <= CONSTANT_FALSE);
  printf("test_false(%d): %d > %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_FALSE
       , config_test_false() > CONSTANT_FALSE);
  printf("test_false(%d): %d >= %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_FALSE
       , config_test_false() >= CONSTANT_FALSE);
  printf("test_false(%d): %d < %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_TRUE
       , config_test_false() < CONSTANT_TRUE);
  printf("test_false(%d): %d <= %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_TRUE
       , config_test_false() <= CONSTANT_TRUE);
  printf("test_false(%d): %d > %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_TRUE
       , config_test_false() > CONSTANT_TRUE);
  printf("test_false(%d): %d >= %d: %d\n"
       , config_test_false(), config_test_false(), CONSTANT_TRUE
       , config_test_false() >= CONSTANT_TRUE);

  printf("test_override_true(%d): %d == %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_TRUE
       , config_test_override_true() == CONSTANT_TRUE);
  printf("test_override_true(%d): %d < %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_TRUE
       , config_test_override_true() < CONSTANT_TRUE);
  printf("test_override_true(%d): %d <= %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_TRUE
       , config_test_override_true() <= CONSTANT_TRUE);
  printf("test_override_true(%d): %d > %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_TRUE
       , config_test_override_true() > CONSTANT_TRUE);
  printf("test_override_true(%d): %d >= %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_TRUE
       , config_test_override_true() >= CONSTANT_TRUE);
  printf("test_override_true(%d): %d < %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_FALSE
       , config_test_override_true() < CONSTANT_FALSE);
  printf("test_override_true(%d): %d <= %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_FALSE
       , config_test_override_true() <= CONSTANT_FALSE);
  printf("test_override_true(%d): %d > %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_FALSE
       , config_test_override_true() > CONSTANT_FALSE);
  printf("test_override_true(%d): %d >= %d: %d\n"
       , config_test_override_true(), config_test_override_true(), CONSTANT_FALSE
       , config_test_override_true() >= CONSTANT_FALSE);

  printf("test_override_false(%d): %d == %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_TRUE
       , config_test_override_false() == CONSTANT_TRUE);
  printf("test_override_false(%d): %d < %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_TRUE
       , config_test_override_false() < CONSTANT_TRUE);
  printf("test_override_false(%d): %d <= %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_TRUE
       , config_test_override_false() <= CONSTANT_TRUE);
  printf("test_override_false(%d): %d > %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_TRUE
       , config_test_override_false() > CONSTANT_TRUE);
  printf("test_override_false(%d): %d >= %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_TRUE
       , config_test_override_false() >= CONSTANT_TRUE);
  printf("test_override_false(%d): %d < %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_FALSE
       , config_test_override_false() < CONSTANT_FALSE);
  printf("test_override_false(%d): %d <= %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_FALSE
       , config_test_override_false() <= CONSTANT_FALSE);
  printf("test_override_false(%d): %d > %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_FALSE
       , config_test_override_false() > CONSTANT_FALSE);
  printf("test_override_false(%d): %d >= %d: %d\n"
       , config_test_override_false(), config_test_override_false(), CONSTANT_FALSE
       , config_test_override_false() >= CONSTANT_FALSE);

}