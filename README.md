This is my version of the **[42](https://www.42.us.org/)** cadet project `push_swap` from the algorithms branch.

# push_swap
A `C` program that sorts a stack of ints.

I use a mix of quick sort and selection sort. They're split into quick sort type partitions. These partitions are then selection sorted.
* If there are more than 28 numbers, they're split into partitions of 25.
* If there are more than 150 numbers, they're split into 6ths, however many that will be.

This gif is of [anyashuka's ruby/python visualizer](https://github.com/anyashuka/Push_Swap) running my push_swap on a set of 100 numbers:

![screen capture of checker and push_swap](./testing/SortingGif.gif)
