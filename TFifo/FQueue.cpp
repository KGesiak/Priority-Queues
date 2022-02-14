#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void  QFDel( QFIFO* q );
QFIFO*  QFCreate( int nSize )
{
	QFIFO* Queue = ( QFIFO* )calloc( 1,sizeof( QFIFO ) );
	if( !Queue )
	{
		perror( "Allocation error in QFCreate - Queue" );
		return 0;
	}
	Queue->pFQItems = ( QFITEM** )calloc( nSize,sizeof( QFITEM* ) );
	if( !Queue->pFQItems )
	{
		perror( "Allocation error in QFCreate" );
		return 0;
	}
	Queue->nMaxElem = nSize;
	return Queue;
}

int QFEmpty( QFIFO* q )
{
	return !q || !q->nNoElem;
}

int QFEnqueue( QFIFO* q, QFITEM* pItem )
{
	if( !q )
	{
		perror( "ERROR in QFEnqueue: Queue is not allocated" );
		return 0;
	}
	if( q->nNoElem == q->nMaxElem )
	{
		printf( "The queue is full!" );
		return 0;
	}
	q->nNoElem++; //increasing the number of elements in queue
	q->pFQItems[q->nTail]= pItem; //finding the right spot for the new element 
	q->nTail = ( q->nTail + 1 ) % q->nMaxElem;
	return 1;
}

QFITEM* QFDequeue( QFIFO* q )
{
	if( !q || QFEmpty( q ) )
	{
		perror( "ERROR in QFDequeue. Allocation error or the queue is empty" );
		return 0;
	}
	QFITEM* p = q->pFQItems[q->nHead];
	QFDel( q );
	return p;
}

void QFClear( QFIFO* q, void( __cdecl* freeItem )( const void* ) )
{
	if( !q )
	{
		perror( "ERROR in QFClear: Queue is not allocated correctly" );
		return;
	}

	while( !QFEmpty( q ) )
		freeItem( QFDequeue( q ) );
	q->nHead = 0;
	q->nTail = 0;
}

void QFRemove( QFIFO** q, void( __cdecl* freeItem )( const void* ) )
{
	if( !q || !*q )
	{
		perror( "ERROR in QFClear: Queue is not allocated correctly" );
		return;
	}
	QFClear( *q, freeItem );
	free( (*q)->pFQItems );
	free( *q );
	*q= NULL;
}

void  QFDel( QFIFO* q )
{
	if( !q || QFEmpty( q ) )
	{
		printf( "ERROR in QFDel: Queue is not allocated or there are no items in the queue" );
		return;
	}
	q->nNoElem--;
	q->pFQItems[q->nHead] = NULL;
	q->nHead = (q->nHead +1) % q->nMaxElem;
}