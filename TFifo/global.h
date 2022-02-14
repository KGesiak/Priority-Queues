#ifndef GLOBAL_DTA
#define GLOBAL_DTA

typedef struct
{ 
  int* pTab;
  int   n_Key;
} QInfo;
void freeItem( const void* );
#define QFITEM QInfo
#endif


