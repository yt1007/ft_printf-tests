# ft_printf-tests
A set of tests written to test the ft_printf function against printf from stdio.h

## Installation
Clone the repository to your computer. Then, edit the `LIB_DIRS` and `INC_DIRS` variables in the `Makefile` to point to the directory containing your ft_printf project files.

## Running the Tests
In the repository, type:
1. `make` to run tests on mandatory functions. The tester will build your ft_printf with `make`.
2. `make bonus` to run tests on bonus functions. The tester will build your ft_printf with `make bonus`.
3. `make all` to run tests on all functions. The tester will build your ft_printf with `make bonus`.

## Notes
1. This test does not explicitly test for the presense of `Makefile` and `ft_printf.h` in your ft_printf submission. Tests will, however, fail if your submission does not contain these files.
2. This test also does not check for norm errors.
3. If you don't want the tests to stop on error (but proceed with other tests for an overview of which tests will fail), it is recommended to run the test with a `-i` flag.
4. Tests are run with `-Wno-integer-overflow` to silence the warnings related to passing numbers beyond data type limits to printf.

## More horrible truths about the test
This test bundle is written to run the same parameters using stdio.h printf and your ft_printf submission, then compare the differences between the output (stdin) and returned values. If there are differences, the differences can be found in the `diffs` folder: `<` represents stdio.h printf outputs and `>` represents output from your submitted ft_printf. The mandatory tests include passing multiple values to printf/ft_printf, while the bonus tests include running printf/ft_printf with only one values but various combination of conversion flags. The bonus_test_misc.c contains tests borrowed from other 42 network test builders.
