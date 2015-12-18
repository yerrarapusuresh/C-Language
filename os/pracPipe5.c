#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
     FILE *fp1, *fp2;
     char line[81];
     int lineno = 1, nchars;

     if ((fp1 = popen(argv[1], "r")) == NULL) {
	  fprintf(stderr, "popen failed for read\n");
	  exit(1);
     }
     
     if ((fp2 = popen(argv[2], "w")) == NULL) {
	  fprintf(stderr, "popen failed for write\n");
	  exit(1);
     }
     while (fgets(line, 81, fp1) != NULL) {
	  fprintf(fp2, "%s", line);
     }

     pclose(fp1);
     pclose(fp2);

     exit(0);
}