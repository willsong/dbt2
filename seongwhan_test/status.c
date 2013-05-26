#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **argv){
  sqlite3 *db;
  int rc;
  int *pCurrent;
  int *pHighwater;

  printf("SQLITE_STATUS\n");
  if( argc!=2 ){
    fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
    return(1);
  }
  rc = sqlite3_open(argv[1], &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }

  printf("memory:%d\n",(int)sqlite3_memory_used());
  printf("high:%d\n",(int)sqlite3_memory_highwater(0));
  rc = sqlite3_status(SQLITE_STATUS_MEMORY_USED,pCurrent,pHighwater,0);
//  rc = sqlite3_status(0,pCurrent,pHighwater,0);
  if( !rc ) {
      printf("SQLITE_OK\n");
      printf("current:%d, highest:%d\n",*pCurrent,*pHighwater);
  }
  else {
      printf("ERROR\n");
      return(1);
  }
  return 0;
}
