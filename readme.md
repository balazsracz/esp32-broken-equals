# 1 == 1 is broken!

When declaring a constant using the DECLARE_CONST(var) and DEFAULT_CONST_TRUE(var) in different files the test of
```
if (config_var() == CONSTANT_TRUE) {
  // do something
}
```
will not enter the if block when the value is actually equal!

## default output with CONSTANT_TRUE = 1 and CONSTANT_FALSE = 2

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

# Workaround

As one possible fix for this odd issue the CONSTANT_TRUE value can change from 1 to 4 and CONSTANT_FALSE from 2 to 8. The DEFAULT_CONST_TRUE, DEFAULT_CONST_FALSE, OVERRIDE_CONST_TRUE and OVERRIDE_CONST_FALSE would also need similar updates.

## After workaround output

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