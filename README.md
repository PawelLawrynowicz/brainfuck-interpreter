## What is brainfuck?

Brainfuck is a simple Turing-complete language that implements so-called Turing machine - a machine that uses infinite tape as its memory device (it isn't random access memory!).

Brainfuck code consists of only 8 commands. Other characters are treated as comments. Interaction with user is facilitiated with standard i/o.

| command | meaning |
| --- | --- |
| > | Increment data pointer |
| < | Decrement data pointer |
| + | Increment current value |
| - | Decrement current value |
| . | Output current value |
| , | Read one byte from input and save it as current value |
| [ | If current value is zero, jump to command after matching ] |
| ] | If current value is nonzero, jump to command after matching [ |

Current value means value in the tape "cell" that is currently under the pointer.

## Compiling and running

```shell
# clone the repo and cd into main dir, and then:

$ mkdir build; cd build
$ cmake ..
$ make
```
