# Group ID and user ID

The use of numeric user IDs and numeric groups IDs for permissions is historical.
With every file on disk, the file system stores both the user ID and the group ID of a file's owner.
Stores those values requires only four bytes.
We can usually find the user id in `/etc/passwd` and the group id inside `/etc/group`.

## Usage

`make main`

```
$ ./main
EACCES: Permission denied
./main: No such file or directory
```