# echo

Takes advantage of `getc` and `putc` for avoid defining a convenient BUFFER_SIZE.

The function `getc` read ibe character at a time, and this charater is written by `putc`.
After the last byte has been read, `getc` returns the constant `EOF` defined in <stdio.h>
The constant `stdin` and `stdout` are also defined in <stdio.h>

## Usage

`make main`

```
$ ./main 
hi
hi
hello
hello
```

```
$ echo Hi there | ./main
Hi there
```


Copy infile to outfile
```
$ ./main < infile > outfile
```