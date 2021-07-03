# `truth` - No conditional branch

To decrease cyclomatic complexity

## Positive Case, Before

```cpp
if (expression) {
        /* Something you want to do */
}
```

## Positive Case, After

```cpp
#include "truth.hpp"

algorithm::when(expression, []() { /* Something you want to do */ });
```

or

## Negative Case, Before

```cpp
if (!expression) {
        /* Something you want to do */
}
```

## Negative Case, After

```cpp
#include "truth.hpp"

algorithm::unless(expession, []() { /* Something you want to do */ });
```

[![License](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause)
