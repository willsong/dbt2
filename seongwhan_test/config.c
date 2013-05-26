#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int rc;
  int sz;
  int N;
  void* pBuf;
  int input;

  printf("SQLITE_CONFIG\n");

  if( argc!=3 ){
    fprintf(stderr, "Usage: %s size number\n", argv[0]);
    return(1);
  }
  sz=atoi(argv[1]);
  N=atoi(argv[2]);
  printf("size:%d, N:%d\n",sz,N);
  pBuf = malloc(sz*N);
//  rc = sqlite3_enable_shared_cache(0);
//  rc = sqlite3_config(SQLITE_CONFIG_PAGECACHE, pBuf, sz, N);
  rc = sqlite3_config(SQLITE_CONFIG_SCRATCH, pBuf, sz, N);
//  rc = sqlite3_config(SQLITE_CONFIG_SINGLETHREAD);
  if( !rc ) {
      printf("SQLITE_OK\n");
  }
  else {
      printf("ERROR\n");
      return(1);
  }
  while(1) {
      printf("enter 999 for exit\n");
      scanf("%d",&input);
      if (input==999)
          break;
  }
  free(pBuf);
  return 0;
}
