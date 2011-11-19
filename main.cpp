#include "includes/phidgetcall.h"
#include "includes/fcgi_stdio.h"

using namespace std;

//Call *c;
FCGX_Request request;

void initialize() {
  //c = new Call();

  FCGX_Init();
  FCGX_InitRequest(&request, 0, 0);
}

int main(int args, char *argv[]) {
  FILE* fp = fopen("/tmp/blah", "w");
  fprintf(fp, "Hello, Server.\n");
  fclose(fp);
  initialize();

  while(FCGX_Accept_r(&request) == 0) {
    printf("Content-type: text/html\r\n"
           "\r\n"
           "<h1>FastCGI Hello! (C, fcgi_stdio library)</h1>");

    FCGI_SetExitStatus(200);
    FCGX_Finish_r(&request);
  }

  //delete c;
  return 0;
}
