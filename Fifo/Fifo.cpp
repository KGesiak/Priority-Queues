#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	QFIFO* Q = QFCreate();
	QInfo* F1 = ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F1->n_Key = 1;
	QInfo* F2= ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F2->n_Key = 2;
	QInfo* F3= ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F3->n_Key = 3;
	QInfo* F4= ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F4->n_Key = 4;
	QInfo* F5= ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F5->n_Key = 5;
	QInfo* F6= ( QInfo* )calloc( 1,sizeof( QInfo ) );
	F6->n_Key = 6;
	QFEnqueue( Q,F1 );
	QFEnqueue( Q,F2 );
	QFEnqueue( Q,F3 );
	QFEnqueue( Q,F4 );
	printf( "%d ",QFDequeue( Q )->n_Key );
	printf( "%d ",QFDequeue( Q )->n_Key );
	printf( "%d ",QFDequeue( Q )->n_Key );
	printf( "%d ",QFDequeue( Q )->n_Key );
	QFEnqueue( Q,F1 );
	QFEnqueue( Q,F2 );
	QFClear( Q );
	QFEnqueue( Q,F4 );
	QFEnqueue( Q,F5 );
	QFEnqueue( Q,F6 );
	printf( "%d ",QFDequeue( Q )->n_Key );
	QFRemove( &Q );
	return 1;
}
