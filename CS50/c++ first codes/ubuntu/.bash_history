Height: 50
Height: 4
Stored: 4
Hints
Building the Opposite
It turns out it’s a bit easier to build a left-aligned pyramid than right-, a la the below.
#
##
###
####
#####
######
#######
########
So let’s build a left-aligned pyramid first and then, once that’s working, right-align it instead!
Modify mario.c at right such that it no longer simply prints the user’s input but instead prints a left-aligned pyramid of that height.
Hints
Keep in mind that a hash is just a character like any other, so you can print it with printf.
Just as Scratch has a Repeat block, so does C have a for loop, via which you can iterate some number times. Perhaps on each iteration, i, you could print that many hashes?
You can actually “nest” loops, iterating with one variable (e.g., i) in the “outer” loop and another (e.g., j) in the “inner” loop. For instance, here’s how you might print a square of height and width n, below. Of course, it’s not a square that you want to print!
Right-Aligning with Dots
Let’s now right-align that pyramid by pushing its hashes to the right by prefixing them with dots (i.e., periods), a la the below.
.......#
......##
.....###
....####
...#####
..######
.#######
########
Modify mario.c in such a way that it does exactly that!
Hint
Notice how the number of dots needed on each line is the “opposite” of the number of that line’s hashes. For a pyramid of height 8, like the above, the first line has but 1 hash and thus 7 dots. The bottom line, meanwhile, has 8 hashes and thus 0 dots. Via what formula (or arithmetic, really) could you print that many dots?
How to Test Your Code
Does your code work as prescribed when you input
-1 (or other negative numbers)?
0?
1 through 8?
9 or other positive numbers?
letters or words?
no input at all, when you only hit Enter?
Removing the Dots
All that remains now is a finishing flourish! Modify mario.c in such a way that it prints spaces instead of those dots!
How to Test Your Code
Execute the below to evaluate the correctness of your code using check50. But be sure to compile and test it yourself as well!
check50 cs50/problems/2021/x/mario/less
cd ~/pset1/mario
submit50 cs50/problems/2021/x/mario/less
cd ..
mkdir ~/pset1/cash
cd ~/pset1/cash
make cash
./cash
make cash
./cash
make cash
./cash
make cash
./cash
make cash
./cash
make cash
./cas
./cash
make cash
./cash
make cash
./cash
make cash
./cash
make cash
./cash
make cash
./cash
style50 cash.c
check50 cs50/problems/2021/x/cash
submit50 cs50/problems/2021/x/cash
wget https://cdn.cs50.net/2020/fall/labs/2/scrabble.c
make scrabble
help50 make scrabble
make scrabble
help50 make scrabble
make scrabble
help50 make scrabble
make scrabble
./scrabble
make scrabble
./scrabble
make scrabble
help50 make scrabble
make scrabble
help50 make scrabble
make scrabble
make scrabble\
make scrabble
help50 make scrabble
make scrabble
help50 make scrabble
make scrabble
help50 make scrabble
make scrabble
./scrabble
help50 make scrabble
make scrabble
./scrabble
make scrabble
./scrabble
help50 make scrabble
make scrabble
./scrabble
make scrabble
./scrabble
check50 cs50/labs/2021/x/scrabble
style50 scrabble.c
submit50 cs50/labs/2021/x/scrabble
mv ceasar.c ~/ceasar
cd ~/ceasar
make ceasar
./ceasar
./ceasar 1
make ceasar
./ceasar
./ceasar 2
make ceasar
./ceasar 2
make ceasar
./ceasar 2
./ceasar 20
make ceasar
./ceasar 20
make ceasar
./ceasar 20
~/ceasar
make ceasar
cd ~/ceasar
make ceasar
./ceasar 2
~/ceasar
cd ~?ceasar
cd ~/ceasar
make ceasar
./ceasar 2
cd ~/ceasar
make ceasar
./ceasar 2
make ceasar
./ceasar 2
make ceasar
./ceasar 2
./ceasar 20
make ceasar
./ceasar 20
make ceasar
./ceasar 20
check50 cs50/problems/2021/x/caesar
cd ~/pset1/ceasar
make ceasar
./ceasar 2
check50 cs50/problems/2021/x/caesar
cd ..
make ceasar
check50 cs50/problems/2021/x/caesar
check50 cs50/labs/2021/x/ceasar
cd ~/ceasar
make ceasar
check50 cs50/problems/2021/x/ceasar
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
./ceasar
./caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
./caesar
make caesar
./caesar
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
./caesar
./caesar hello
./caesar 2x
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
./caesar 2x
make caesar
./caesar 2x
make caesar
./caesar 2x
make caesar
./caesar 2x
make caesar
./caesar 2x
make caesar
./caesar 2x
make caesar
./caesar 2x
./caesar 2
make caesar
./caesar 2
./caesar 2x
make caesar
./caesar 2x
./caesar 2
make caesar_test
./ceasar 20
./caesar_test 20
make caesar_test
./caesar_test 20
./caesar_test 20x
make caesar_test
./caesar_test 20
./caesar_test 20x
make caesar_test
./caesar_test 20x
make caesar_test
./caesar_test 20x
make caesar_test
./caesar_test 20x
make caesar
./caesar 20
check50 cs50/problems/2021/x/caesar
make caesar
./caesar 65
make caesar
./caesar 65
barfoo
./caesar 65
check50 cs50/problems/2021/x/caesar
make caesar
check50 cs50/problems/2021/x/caesar
make caesar
style50 caesar.c
make caesar_test
./caesar_test 20x
make caesar_test
./caesar_test 20x
./caesar_test 20
make caesar_test
./caesar_test 20
./caesar_test 20x
make caesar_test
make test_num
./test_num 20
./test_num 20x
make test_num
./test_num 20x
make test_num
./test_num 20x
./test_num 20
make test_num
./test_num 20
./test_num 20x
cd ~/ceasar
make test_num
./test_num
./test_num 20
./test_num 20x
make test_num
./test_num 20x
./test_num 20
./test_num bar
./test_num
make test_num
make caesar
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, string argv[])
{   if (argc != 2);   {     printf("Usage: ./caesar key\n");
./caesar
./caesar 20
check50 cs50/problems/2021/x/caesar
style50 caesar.c
submit50 cs50/problems/2021/x/caesar
cd ~/readability
make readability
./readability
make readability
./readability
{     // Let's define the number of letters (L) and the number of sentences (S) per 100 words in the text
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (t[i] >= 'a' && t[i] <= 'z')
        {
            count += 1;
        }
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            count += 1;
        }
        else
        {
            count += 0;
        }
    }
    return count;

./readability
make readability
./readability
make readability
./readability
make readability
./readability
make readability
./readability
make readability
./readability
make readability
help50 make readability
make readability
./readability
make readability
./readability
check50 cs50/problems/2021/x/readability
style50 readability.c
submit50 cs50/problems/2021/x/readability
get https://cdn.cs50.net/2020/fall/labs/3/lab3.zip
wget https://cdn.cs50.net/2020/fall/labs/3/lab3.zip
unzip lab3.zip
cd lab3
./sort1 random5000.txt
time ./sort1 random5000.txt
time ./sort21 random5000.txt
time ./sort2 random5000.txt
time ./sort3 random5000.txt
time ./sort3 sorted5000.txt
time ./sort2 sorted5000.txt
time ./sort1 sorted5000.txt
time ./sort1 reversed5000.txt
time ./sort2 reversed5000.txt
time ./sort3 reversed5000.txt
check50 cs50/labs/2021/x/sort
submit50 cs50/labs/2021/x/sort
cd
mkdir pset3
cd pset3
mkdir plurality
cd plurality
wget https://cdn.cs50.net/2020/fall/psets/3/plurality/plurality.c
ls
make plurality
./plurality Renate Thijs Noa
make plurality
./plurality Renate Thijs Noa
./plurality Alice Bob
make plurality
./plurality Alice Bob
make plurality
help50 make plurality
make plurality
./plurality Alice Bob
make plurality
./plurality Alice Bob
make plurality
./plurality Alice Bob
make plurality
./plurality Alice Bob
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
cd ~/pset3/plurality
// Print the winner (or winners) of the election
void print_winner(void)
{     // Find the biggest number of votes     // First look at the total votes for the array;     int total_votes = 0;     for (int c = 0; c < candidate_count; c++)
}
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
check50 cs50/problems/2021/x/plurality
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
check50 cs50/problems/2021/x/plurality
make plurality
check50 cs50/problems/2021/x/plurality
cd ~/pset3/plurality
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
cd ~/pset3/plurality
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
make plurality
./plurality Alice Bob Charlie
check50 cs50/problems/2021/x/plurality
make plurality
check50 cs50/problems/2021/x/plurality
style50 plurality.c
submit50 cs50/problems/2021/x/plurality
