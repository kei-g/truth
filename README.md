# `truth` - No conditional branch

To decrease cyclomatic complexity

### Before

```cpp
if (expression) {
        /* Something you want to do */
}
```

### After

```cpp
#include "truth.hpp"

algorithm::when(expression, []() { /* Something you want to do */ });
```

or

### Before

```cpp
if (!expression) {
        /* Something you want to do */
}
```

### After

```cpp
#include "truth.hpp"

algorithm::unless(expession, []() { /* Something you want to do */ });
```
