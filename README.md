# periodic-clock

Interface for a monotonic clock and a periodic tick.

Part of [integra-lib](https://gitlab.integrasources.com/internal-projects/integra-lib).
Header-only C++20, no exceptions, no RTTI.

## Use it

```bash
git submodule add ../periodic-clock.git external/integra/periodic-clock
```

```cmake
add_subdirectory(external/integra/periodic-clock)
target_link_libraries(app PRIVATE Integra::periodic_clock)
```

```cpp
#include <integra/periodic_clock.hpp>
```

## Develop it

```bash
cmake -S . -B build && cmake --build build -j && ctest --test-dir build
```

Tests are built only when this repository is the top-level project, so a consumer
never builds them. Style and pipeline come from the `ci-shared` submodule; run
`git submodule update --init` before `pre-commit`.
