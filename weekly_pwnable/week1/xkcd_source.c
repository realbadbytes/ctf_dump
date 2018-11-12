/*
 * Description: might want to read that comic as well ... 1354 
 *
 * XKCD 1354: 
 *
 * HOW THE HEARTBLEED BUG WORKS
 * SERVER, ARE YOU STILL THERE?
 * IF SO, REPLY "POTATO" (6 LETTERS).
 * POTATO
 * SERVER, ARE YOU STILL THERE?
 * IF SO, REPLY "BIRD" (4 LETTERS).
 * BIRD
 * SERVER, ARE YOU STILL THERE?
 * IS SO, REPLY "HAT" (500 LETTERS).
 * HAT + leaked memory
 *
 */

int main(int argc, const char **argv, const char **envp)
{
  FILE *flag;
  int v5;
  int v6;
  int v7;
  unsigned int v8;
  unsigned int v9
  char v10;
  int v11;
  int v12;
  int v13;
  FILE *flag2;

  setvbuf(stdout, 0, 2, 0);
  setvbuf(stdin, 0, 2, 0);

  /* bzero(void *s, size_t n)
   * flag is in .data, initialized data
   * sets 256 bytes of flag to zero.
   */
  bzero(&flag, 256);

  /* fopen(const char *path, const char *mode)
   * mode is 0x72, 'r' read-only (path and 'r' in .rodata since const)
   * load flag contents into memory 
   */
  flag = fopen("flag", 'r'); /*'r' is at &unk_487DE4 */
  flag2 = flag;

  if (flag)
  {
    /* fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
     * is in . bss, uninitialized data
     * this reads in the flag contents to &flag
     */
    fread(&flag, 1, 256, flag2);

    while ( 1 )
    {
      /* fgetln(FILE* stream, size_t *len) returns a pointer to the next line from the stream reference by stdin.
       * This line is not a C string, thus it does not end with a NUL
       */
      input = fgetln(stdin, &v10);
      parsed_input = strtok(input, "?");
      if (!strcmp(parsed_input, "SERVER, ARE YOU STILL THERE"))
        break;
      /* Passing the null here as *s gets the next token, so whatever follows '?' */
      parsed_input = strtok(0, "\"");
      if (!strcmp(parsed_input, " IF SO, REPLY "))
      {
        puts("MALFORMED REQUEST", " IF SO, REPLY ");
        exit(-1);
      }
      /* get the string to echo back */
      /* these next few lines just parse out the number from our input. might be incorrect */
      quoted_string = strtok(0, "\"");
      quoted_strlen = strlen(quoted_string);
      memcpy(globals, quoted_string2, quoted_strlen);
      specified_len = strtok(0, "(");
      specified_len = strtok(0, ")");
      /* if input is (4 LETTERS), move 4 into rax */
      sscanf(specified_len);
      /* write a null byte based on our input. (4 LETTERS) will write a null byte at index 4 of globals. */
      /* specified_len is a signed int */
      globals[specified_len] = 0;
      /* ensure our input length matches the declared length */
      globals_len = strlen(globals);
      /* if our specified length is greater than the actual quoted string length, die */
      /* is this a signed compare? */
      if ( specified_len > globals_len )
      {
        puts("NICE TRY");
        exit(-1);
      }
      /* echo back our input to stdout */
      /* this is where memory would leak */
      puts(globals);
    }
    puts("MALFORMED REQUEST", "SERVER, ARE YOU STILL THERE");
    exit(-1);
  }
  puts("Could not open the flag.", &unk_487DE4);
  return -1;
}
