# 1 == 1 is broken!

When declaring a constant using the DECLARE_CONST(var) and DEFAULT_CONST_TRUE(var) in different files the test of
```
if (config_var() == CONSTANT_TRUE) {
  // do something
}
```
will not enter the if block when the value is actually equal!

## output:

When executing the test code the following output is observed on the esp32:
```
test: 1
test_true(1): 1 == 1: 0
test_true(1): 1 < 1: 0
test_true(1): 1 <= 1: 1
test_true(1): 1 > 1: 0
test_true(1): 1 >= 1: 1
test_true(1): 1 < 2: 1
test_true(1): 1 <= 2: 1
test_true(1): 1 > 2: 0
test_true(1): 1 >= 2: 0
test_false(2): 2 == 2: 1
test_false(2): 2 < 2: 0
test_false(2): 2 <= 2: 1
test_false(2): 2 > 2: 0
test_false(2): 2 >= 2: 1
test_false(2): 2 < 1: 0
test_false(2): 2 <= 1: 0
test_false(2): 2 > 1: 1
test_false(2): 2 >= 1: 1
test_override_true(1): 1 == 1: 0
test_override_true(1): 1 < 1: 0
test_override_true(1): 1 <= 1: 1
test_override_true(1): 1 > 1: 0
test_override_true(1): 1 >= 1: 1
test_override_true(1): 1 < 2: 1
test_override_true(1): 1 <= 2: 1
test_override_true(1): 1 > 2: 0
test_override_true(1): 1 >= 2: 0
test_override_false(2): 2 == 1: 0
test_override_false(2): 2 < 1: 0
test_override_false(2): 2 <= 1: 0
test_override_false(2): 2 > 1: 1
test_override_false(2): 2 >= 1: 1
test_override_false(2): 2 < 2: 0
test_override_false(2): 2 <= 2: 1
test_override_false(2): 2 > 2: 0
test_override_false(2): 2 >= 2: 1
```

Changing the values for CONSTANT_TRUE and CONSTANT_FALSE to 4 and 8 fixes it:

```
test_true(4): 4 == 4: 1
test_true(4): 4 < 4: 0
test_true(4): 4 <= 4: 1
test_true(4): 4 > 4: 0
test_true(4): 4 >= 4: 1
test_true(4): 4 < 8: 1
test_true(4): 4 <= 8: 1
test_true(4): 4 > 8: 0
test_true(4): 4 >= 8: 0
test_false(8): 8 == 8: 1
test_false(8): 8 < 8: 0
test_false(8): 8 <= 8: 1
test_false(8): 8 > 8: 0
test_false(8): 8 >= 8: 1
test_false(8): 8 < 4: 0
test_false(8): 8 <= 4: 0
test_false(8): 8 > 4: 1
test_false(8): 8 >= 4: 1
test_override_true(4): 4 == 4: 1
test_override_true(4): 4 < 4: 0
test_override_true(4): 4 <= 4: 1
test_override_true(4): 4 > 4: 0
test_override_true(4): 4 >= 4: 1
test_override_true(4): 4 < 8: 1
test_override_true(4): 4 <= 8: 1
test_override_true(4): 4 > 8: 0
test_override_true(4): 4 >= 8: 0
test_override_false(8): 8 == 4: 0
test_override_false(8): 8 < 4: 0
test_override_false(8): 8 <= 4: 0
test_override_false(8): 8 > 4: 1
test_override_false(8): 8 >= 4: 1
test_override_false(8): 8 < 8: 0
test_override_false(8): 8 <= 8: 1
test_override_false(8): 8 > 8: 0
test_override_false(8): 8 >= 8: 1
```