# errno

Two functions are defined by the C standard to help with printing error messages.

Returns: pointer to message string
```
#include <string.h>

char *strerror(int errnum);
```

---

Produces an error message on the standard error, based on the current value of errno, and returns
```
#include <stdio.h>

void perror(const char *msg);
```

## Usage

`make main`

```
$ ./main
EACCES: Permission denied
./main: No such file or directory
```