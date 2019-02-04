/* compile with */
/* gcc -o screensaver runscreensaver.c -lXss -lX11 */
/* WSS4XSCREENSAVER*/
/* Author: Alex Terranova */
/* Date: 02/02/2019 */
/* License: Free to distribute and modify */

/* Packages Needed to Compile: build-essential, libx11-dev, libxss-dev
 
/* header files */
#include <X11/extensions/scrnsaver.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/X.h>

/* Location of Windows Screensaver under wine */
/* Replace the screensaver name/path with your screensaver*/
#define SHELLSCRIPT "\
#/bin/bash \n\
./startscreensaver.sh \n\
"
/* Makes sure ScreenSaver is killed on not IDLE */
#define KILLSCREENSAVER "\
#/bin/bash \n\
./killscreensaver.sh \n\
"

int main(void) {
    
  Bool isrunning=0;
  Bool forever=1;
  unsigned int currenttime=0;
  
  FILE *myFile;
  myFile = fopen("time.txt", "r"); // get time from text file for the Windows Screensaver to start
  int getmytime;
  char ch;
  ch = fgetc(myFile);
  getmytime = atoi(&ch);
  
  Display *dpy = XOpenDisplay(NULL);
  
  if (!dpy) { return(1); }
  
  // run program until terminated by user
  
  while (forever==1)
  { 
  
  XScreenSaverInfo *info = XScreenSaverAllocInfo();
  XScreenSaverQueryInfo(dpy, DefaultRootWindow(dpy), info);
  
     if (info->idle)
        currenttime++;

     if (currenttime > getmytime && isrunning==0)
     {
        system(SHELLSCRIPT);
        isrunning=1;
     }

     if (info->idle < 5000)
     { 
         currenttime=0;
         isrunning=0;
         system(KILLSCREENSAVER);
     }
     
     sleep(1);
  }
  return(0);
}
