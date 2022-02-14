#include "global.h"
#ifndef FQUEUE_DKA
#define FQUEUE_DKA
typedef struct
{
	QFITEM** pFQItems;
	int nHead;
	int nTail;
	int nNoElem;
	int	nMaxElem;
}QFIFO;
                              
QFIFO* QFCreate( int nSize );
int     QFEmpty( QFIFO* q );
int     QFEnqueue( QFIFO* q, QFITEM* pItem );
QFITEM* QFDequeue( QFIFO* q );
void    QFClear( QFIFO* q, void ( __cdecl* freeItem )( const void* ) );
void    QFRemove( QFIFO** q, void ( __cdecl* freeInfo )( const void* ) );
#endif

