# Balanced-Brackets
Type in an input with brackets, and this will check it to see if your program is balanced.


# Context Free Grammar
This program demonstrates a Pushdown Automata (PDA) which is equivalent to the following Context Free Grammar (CFG)

    S → TT
    T → (T) | {T} | <T> | [T] | ε

This program accepts other characters as well, but will only regard (,),<,>,\[,\],{, and } to determine whether or not it is balanced/acceptable.
