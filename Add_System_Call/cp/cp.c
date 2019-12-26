#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  char buf[1024];
  int src, dest, r, w;

  if(argc != 3){
    printf(2, "Correct Format: cp __src__ __destination__\n");
    exit();
  }

  if ((src = open(argv[1], O_RDONLY)) < 0) {
    printf(2, "Error: Cannot open source file.%s\n", src);
    exit();
  }
  if ((dest = open(argv[2], O_CREATE|O_WRONLY)) < 0) {
    printf(2, "Error: Cannot open destination file.%s\n", dest);
    exit();
  }
  
  while ((r = read(src, buf, sizeof(buf))) > 0) {
    w = write(dest, buf, r);
    if (w != r || w < 0) 
      break;
  }
  close(src);
  close(dest);

  exit();
}