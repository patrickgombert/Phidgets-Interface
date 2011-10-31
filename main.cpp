#include "includes/phidgetcall.h"
#include "includes/fcgi_stdio.h"

using namespace std;

Call *c;
FCGX_Request request;

void initialize() {
  c = new Call();

  FCGX_Init();
  FCGX_InitRequest(&request, 0, 0);
}

int main(int args, char *argv[]) {
  initialize();

  while(FCGX_Accept_r(&request) == 0) {
    char* path;
    path = FCGX_GetParam("PATH", request.envp);

    printf("Content-type: text/html\r\n"
           "\r\n"
           "<h1>FastCGI Hello! (C, fcgi_stdio library)</h1>"
           "<body>Path Given: %s", path, "</body>");

    FCGI_SetExitStatus(200);
    FCGX_Finish_r(&request);
  }

  delete c;
  return 0;
}
