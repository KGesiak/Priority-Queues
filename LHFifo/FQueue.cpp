#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  QFDel( QFIFO* q );
                           
QFIFO* QFCreate()
{
	QFIFO* Queue = ( QFIFO* )calloc( 1,sizeof( QFIFO ) );
	QFItem* Header = ( QFItem* )calloc( 1,sizeof( QFItem ) );
	if( !Queue || !Header )
	{
		perror( "Allocation error in QFCreate" );
		return 0;
	}
	Queue->pHead = Queue->pTail = Header;
	return Queue;
}

int QFEmpty( QFIFO* q )
{
	return !q || !q->pHead->next;
}

int QFEnqueue( QFIFO* q, QInfo* pInfo )
{
	if( !q )
	{
		perror( "ERROR in QFEnqueue: Queue is not allocated" );
		return 0;
	}
	QFItem* pItem = ( QFItem* )calloc( 1,sizeof( QFItem ) );
	if( !pItem )
	{
		perror( "Allocation error in QFEnqueue!" );
		return 0;
	}
	pItem->inf = pInfo;
	q->pTail->next = pItem;
	q->pTail = pItem;
	return 1;
}

QInfo* QFDequeue( QFIFO* q )
{
	if( !q || QFEmpty( q ) )
	{
		perror( "ERROR in QFDequeue. Allocation error or the queue is empty" );
		return 0;
	}
	QInfo* p = q->pHead->next->inf;
	QFDel( q );
	return p;
}

void  QFClear( QFIFO* q )
{
	if( !q )
	{
		perror( "ERROR in QFClear: Queue is not allocated correctly" );
		return;
	}
	while( !QFEmpty( q ) )
		free( QFDequeue( q ) );
}

void  QFRemove( QFIFO** q )
{
	if( !q || !*q )
	{
		perror( "ERROR in QFClear: Queue is not allocated correctly" );
		return;
	}
	QFClear( *q );
	free( (*q)->pHead );
	free( *q );
	*q = NULL;
}

void  QFDel( QFIFO* q )
{

	if( !q || QFEmpty( q ) )
	{
		printf( "ERROR in QFDel: Queue is not allocated or there are no items in the queue" );
		return;
	}
	QFItem* p = q->pHead->next;
	q->pHead->next = p->next;
	free( p );
	if( QFEmpty( q ) )
		q->pTail = q->pHead;
}