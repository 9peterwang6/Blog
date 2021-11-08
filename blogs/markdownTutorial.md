# Markdown tutorial
Notes from https://www.markdowntutorial.com/


## Lesson 1 Bolds and Italics  
Use "_" to make things italic. Usage: _make it italic_

Use "**" to make things bold. Usage: **make it bold**

Use "**_" to make things bold and italic. Usage: **_make it bold and italic_**


## Lesson 2 Headers  
There are six levels of headers in Markdown, Level 1 ~ 6.

Usage:
# Header Level One  
## Header Level Two  
### Header Level Three  
#### Header Level Four  
##### Header Level Five  
###### Header Level Six  


## Lesson 3 Links  
There are two type of links you can write using Markdown:

The first type is called "inline link": [link title](the web link)

An example: [Let me google that for you](www.google.com)

The second type is called "reference link": 
[this is a referenced material][reference link]
[this is another referenced material but uses the same reference link][reference link]

[reference link]: https://your.reference.link

The "[reference link]" here is formally called a "reference tag".


## Lesson 4 Images  
Adding images is similar to adding links. There are also two styles:
![image alt text](https://your.image.link)

![image alt text][image tag]
[image tag]: https://your.image.link


## Lesson 5 Blockquotes  
>"Put your blockquotes here"

If your blockquotes span multiple paragraphs:
>Paragraph one
>
>Paragraph two
>
>End


## Lesson 6 Lists  
unordered list:
* item one
* item two
* item three

order list:
1. step one
2. step two
3. step three

sub lists:
* item one
 * pay attention to sub item one.

if you want to put on some other notes but you don't want to use sub lists:
1. Step one

 Reference this page for help.

2. Step two

 Remember to add a new line.


## Lesson 7 Paragraph  
Insert two spaces at the end <=> puting a "\n" at the end of the current line. This is called a "soft break".

Insert a new line after one line <=> inserting a new line between paragraphs. This is called a "hard break".


#### Additional notes from [wikipedia](https://en.wikipedia.org/wiki/Markdown) and from [mahua.jser.me](mahua.jser.me)
horizontal rule: ---  
strikethrough: ~~something~~  
hightlight: `highlighted context`  
computer code:  
```php
   print("hello world");
```
