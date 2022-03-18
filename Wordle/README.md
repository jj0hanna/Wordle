My wordle game:

First i would like to point out that i have a few functions etc that i have made as comments just because i still want to have it in there for
myself for the future. T.ex the "loadWordMap". That's the functions i used for "G" requirements.


Since i got time over i decided to try and make my own container for the words. After a little of research then i decided that i wanted to try and
make my own binary search tree because it sounded like a really nice and fast way of searching for items. I did see a problem with using binary search tree
half way through and that was that my tree would not be balanced because the words in the document is in order. All the nodes would go to the right and make
a linear unbalanced tree. I decided to continue with this anyway just because i really wanted to learn how to make one (even though i knew that maybe this solution
was not the best for this assigment). I made everything work with a unbalanced tree.

I read about that it was possible to balance the tree so i decided the last days to try and balance the tree to make it more effective. I think I managed to
do it but i'm not 100% sure. I also know that when i'm trying to balance the tree then it's also trying to add nodes that have the same data. I fixed this
using an if statment to double check if that word already exist, if so i don't create a new node. I left a comment in my code in wordle.cpp, insert function on line 70.