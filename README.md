# WSS4XSCREENSAVER-2.0

A simple program written in C that can run Windows screensavers in Linux via Wine when idle.

With version 2.0 I have included the binary compiled on Kubuntu 18.10

[1] Edit the files (startscreensaver.sh and killscreensaver.sh) (You must modify the name/path with your Windows Screensaver already installed in wine)

[2] Modify (time.txt) (Here you can set the time in seconds for when your Windows Screensaver should start after idle time begins)

--------------------------------------------------------------------

If you still want/need to compile this program:

--------------------------------------------------------------------

-First install: build-essential, libx11-dev, libxss-dev

-Open the file: runscreensaver.c with your text editor.

-Compile with "gcc -o screensaver runscreensaver.c -lXss -lX11" leaving out the quotation marks

--------------------------------------------------------------------

*As far as I know this program doesn't work with multi-monitor setups yet.

*If you would like the program to start when you sign in just add the executable to "Startup Applications" in Linux.
