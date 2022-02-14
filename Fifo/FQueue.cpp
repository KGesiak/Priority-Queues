#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  QFDel( QFIFO* q );
QFIFO* QFCreate()
{
	if( QFIFO* q = ( QFIFO* )calloc( 1,sizeof( QFIFO ) ) ) return q;
	perror( "ERROR in QFCreate: Queue is not allocated correctly" );
	return 0;
}

int QFEmpty( QFIFO* q )
{
	return !q || !q->pHead;
}

int QFEnqueue( QFIFO* q, QInfo* pInfo )
{
	if( !q )
	{
		perror( "ERROR in QFEnqueue: Queue is not allocated correctly" );
		return 0;
	}
	QFItem* pItem = ( QFItem* )calloc( 1,sizeof( QFItem ) );
	if( !pItem ) 
	{
		perror( "Allocation error in QFEnqueue!" );
		return 0;
	}
	pItem->inf = pInfo;
	if( QFEmpty( q ) )
		q->pHead = pItem;
	else
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
	QInfo* p = q->pHead->inf;
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
	while ( !QFEmpty( q ) )
		free( QFDequeue( q ) );
}

void  QFRemove( QFIFO** q )
{
	if( !q || !*q )
	{
		perror( "ERROR in QFRemove: Queue is not allocated correctly" );
		return;
	}
	QFClear( *q );
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
	QFItem* temp = q->pHead;
	q->pHead = temp->next;
	free( temp );
	if( QFEmpty( q ) )
		q->pTail = NULL;
}