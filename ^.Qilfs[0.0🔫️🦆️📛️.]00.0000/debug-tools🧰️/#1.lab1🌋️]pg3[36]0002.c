#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
//
#include <string.h>
///////////////////

char *b_uffer;
  int len_b;
  
  void abAppend(char *b_uffer,int len_b , const char *s, int len) {
  char *new = malloc(b_uffer, len_b + len); // this is supposed 2 be appending.
  					// we actually have a buffer append in old kbd.logger!
  				// u can still use this one , now that u understand it
  				// from taking it apart. 
  				// the only thing i dont want is for it 2 obfuscale LATER!
  if (new == NULL) return;
  memcpy(&new[len_b], s, len);
  b_uffer = new;
  len_b += len;
}
void abFree(struct abuf *ab) {
  free(ab->b);
}

int getWindowSize(int *rows, int *cols) {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    return -1;
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
  }
}

 int screenrows;
  int screencols;
  struct termios orig_termios;
  
  void initEditor() {
  if (getWindowSize(&screenrows, &screencols) == -1) die("getWindowSize");
}
//////
void editorRefreshScreen() {
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);

  editorDrawRows();

  write(STDOUT_FILENO, "\x1b[H", 3);
}
//////

void editorDrawRows() {
  int y;
  for (y = 0; y < screenrows; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}

void die(const char *s) {
printf("machine death");

perror(s);
exit(91);
}

int main(int argc, char* argv[]){
//
 initEditor();
  write(STDOUT_FILENO, "\x1b[2J", 4); // move screen 2 bottom //says it refreshes screen..
  write(STDOUT_FILENO, "\x1b[H", 3); // moves cursor somewhere.
  editorDrawRows();
  while(1){};

/*
 write(STDOUT_FILENO, "one\n", 4);
  write(STDOUT_FILENO, "\x1b[2J", 4); // move screen 2 bottom //says it refreshes screen..
  write(STDOUT_FILENO, "\x1b[H", 3); // moves cursor somewhere.
  */
}
