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
  int flag_ptr;
  int v5;
  int v6;
  int v7;
  unsigned int v8;
  unsigned int v9
  char v10;
  int v11;
  int v12;
  int v13;
  int flag_ptr_2;

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
  flag_file_ptr = fopen("flag", 'r'); /*'r' is at &unk_487DE4 */
  flag_file_ptr2 = flag_file_ptr;

  if (flag_file_ptr)
  {
    /* fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
     * is in . bss, uninitialized data
     * this reads in the flag contents to &flag
     */
    fread(&flag, 1, 256, flag_ptr_2);
    while ( 1 )
    {
      v13 = fgetln(stdin, &v10);
      v12 = strtok(v13, "?");
      if ( sub_4002D0(v12, "SERVER, ARE YOU STILL THERE") )
        break;
      v12 = strtok(0LL, "\"");
      if ( sub_4002D0(v12, " IF SO, REPLY ") )
      {
        puts("MALFORMED REQUEST", " IF SO, REPLY ");
        exit(0xFFFFFFFFLL);
      }
      v5 = strtok(0LL, "\"");
      v12 = v5;
      LODWORD(v6) = strlen(v5);
      memcpy(globals, v12, v6);
      v12 = strtok(0LL, "(");
      v7 = strtok(0LL, ")");
      v12 = v7;
      _isoc99_sscanf(v7);
      globals[(signed __int64)v11] = 0;
      v8 = v11;
      LODWORD(v9) = strlen(globals);
      if ( v8 > v9 )
      {
        puts("NICE TRY", "%d LETTERS");
        exit(0xFFFFFFFFLL);
      }
      puts(globals, "%d LETTERS");
    }
    puts("MALFORMED REQUEST", "SERVER, ARE YOU STILL THERE");
    exit(0xFFFFFFFFLL);
  }
  puts("Could not open the flag.", &unk_487DE4);
  return -1;
}
