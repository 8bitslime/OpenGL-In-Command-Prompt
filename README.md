# OpenGL in the Command Prompt
Just a really dumb idea I had one night. What if you made the console an OpenGL context?

Now this is only a proof of concept; there is nothing special to see. It's just a simple trinalge
rendered using immediate mode. I can't even get proper events from the console to make a more exciting
program. Maybe some of you win32 hackers out there may be more fit for that challenge than me.

So far with the tests I've done, it only works on Windows (obviously) if compiled with VC++14.
I tried it with G++ (`g++ ConsoleOGL.cpp -lopengl32 -mwindows`) which did not work but I'm
not a programming master, so I could have done something wrong.

Anyways, here's an image showing off what it looks like because I know you guys don't want download and
compile one single easy to read file.
![OpenGL context in command prompt](http://imgur.com/a/X6Axu)
