 #include<stdio.h>
 int main(void) {

  FILE *fp1, *fp2;  //file ptr for accessing input & out put files
  int ch;
  char c;
  fp1 = fopen ("input.c", "r"); //inpt c file which is having comment lines
  fp2 = fopen ("output.c", "w"); //out put c file after removing comment line

  while ((ch = fgetc (fp1)) != EOF) { // scaning each char of input file until end of file 
      c = ch;
      if (ch == '/') {

	  ch = fgetc (fp1);
	 
	  if (ch == '*') { //checking /*....*/ type of comments
	      while (fgetc (fp1) != '*');  //skip all charecters between /*....to .....*/
		     ch = fgetc (fp1);
	  }
	  else if (ch == '/') {  	//checking //..... type comment line
	      while (fgetc (fp1) != '\n');
	      fputc ('\n', fp2);
	  }
	  else {
	    fputc (c, fp2);
	    fputc (ch, fp2);
	  }
      }
      else	//copying normal data to output file
	fputc (ch, fp2);
  }
	//closing the files
  fclose (fp1);
  fclose (fp2);
  return 1;
 }
