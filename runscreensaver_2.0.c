/* compile with */
/* gcc -o screensaver runscreensaver.c -lXss -lX11 */
/* SCREENSAVER4WINE*/
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

#define SHELLSCRIPT "\
#/bin/bash \n\
./startscreensaver.sh \n\
"

#define KILLSCREENSAVER "\
#/bin/bash \n\
./killscreensaver.sh \n\
"

int main(void) {
    
  Bool isrunning=0;
  Bool forever=1;
  unsigned int currenttime=0;
  
  FILE *myFile;
  myFile = fopen("time.txt", "r"); 
  int getmytime;
  fscanf(myFile, "%d", &getmytime);
  
  Display *dpy = XOpenDisplay(NULL);
  
  if (!dpy) { return(1); }
  
  
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
