# Emacs Notes

Notes from the Emacs tutorial.

<br>

## Terminology

Control key <=> C

Meta key <=> Alt <=> M

<br>

## Command Format

C- [chr]: hold the Ctrl key while typing the character [chr]

M- [chr]: hold the Alt key while typing the character [chr]

<br>

## Failsafe Commands

To close the current file, type C-x C-c.

To quit a partially entered command, type C-g.

<br>

## Viewing Screenfuls

C-v: move forward one screenful

M-v: move backward one screenful

C-l <=> CTRL-L: move the text around the cursor to the center of the screen. You can press te command again to move the text starting at the cursor to the top of the page.

<br>

## Basic cursor control

C-f: move forward a character

C-b: move backward a character

M-f: move forward a word

M-b: move backward a word

C-n: move to next line

C-p: move to previous line

C-a: move to beginning of line

C-e: move to end of line

M-a: move back to beginning of sentence

M-e: move forward to end of sentence

M-<: move to the beginning of the whole text

M->: move to the end of the whole text

<br>

## Repeating commands

C-u 8 C-f: move forward eight characters

C-u 8 C-v: scroll by 8 lines

<br>

## Long List of Notes from Tutorial

To close the other opened windows, use C-x 1

To place the cursor line on the top of the screen, use C-u 0 C-l

To check the documentation of a command, use C-h k [your command]

To insert ******, type C-u 8 *

To kill (i.e. cut it and put it to a clipboard)  from the cursor position to the end of line, type C-k

To kill to the end of the current sentence, type M-k

To select a portion of the text, use C-[SPC]

To kill selected text, use C-w

To yank (i.e. paste) the killed text, use C-y. It will put back the last killed text.

To yank other killed text, use M-y.

To undo changes, use C-/

To save a file, use C-x C-s

To save as a new file, use C-x C-s [filename]

To open another file, use C-x C-f [filename].

To open a list of opened files, use C-x C-b.

To switch another opened file, use C-x b [filename]

To save a modified buffer, type C-x s

To exit Emacs temporarily, use C-z. To resume, type "%emacs" on the terminal

To replace strings after the initial position of the curosr, type M-X repl string[Return]word1[Return]word2[Return].

To recover a file after your computer crashes, go to your file normally and then type M-X recover-file [Return].

Emacs has a mode named auto-fill-mode which automatically breaks the line in between words. To enable it, type M-X auto-fill-mode [Return]. Type the same thing to turn it off. You can also change the margin to a different number (70 by default) by typing C-u [number] C-x f. To re-fill the previous typings, place your cursor inside the paragraph of interest and type M-q.

To do a forward search of a word, type C-s [word] [Return]. To backward search a word, type C-r [word] [Return]. To move forward to the next occurence of the word, type C-s. Type C-g to terminate the search.

To have split windows opened at Emacs. Use C-x 2. To move the cursor to another window, type C-x o. To scoll the other window that you just created, type C-M-v. If you want to splt the window and open another file directly, type C-x 4 C-f [filename].

To get help, type C-h. Command C-h c [command] tells you the name of the [command], whereas C-h k [command] opens its documentation. Command C-h f [function] can display the documentation of a function.
