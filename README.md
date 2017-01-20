# OpenGL in the Command Prompt
I thought to myself one night, "what if I added hardware accelerated rendering to the console?" And then I did.

Now this is only a proof of concept; there is nothing special to see. It's just a simple trinalge rendered using immediate mode. I can't even get proper events from the console to make a more exciting program. Maybe some of you win32 hackers out there may be more fit for that challenge than me.

Obviously it only works on Windows, but I have managed to get it working on VC++14 in Visual Studio and on MingW/GCC with `g++ ConsoleOGL.cpp -lopengl32 -mwindows -mconsole`.

Anyways, here's an image showing off what it looks like because I know you guys don't want download and compile one single easy to read file.
![OpenGL context in command prompt](/images/screenshot.png)
