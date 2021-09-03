# Greedy Snake

Achieved version:

greedy snack in python

greedy snack in c++

The current goal -- greedy snack in c

### Greedy Snake in Python

Using 2 classes to initial snake and point
Using the global variable to track point and point_status
Using pygame.draw.rect to make a white border and change the determing situation (add 10 since the border is 10 pix)

### Greedy Snake in C++

For c++, when using mac, we need to use ncurses-5.9 to imply the input and window. Using ncurses-5.9, we can capture the input keys and show in a seperated board.

In addition, to make sure the ncurses works, need to followed guird from here: [install ncurses on macosx](https://gist.github.com/cnruby/960344)

After install everything, using this compile line:

> g++ -Wall -Wextra main.cpp -lncurses

> ./a.out

Then you can see the game map

If using window/Linux, can try to use window.h instead
