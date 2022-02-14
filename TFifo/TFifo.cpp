#include "FQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NSIZE 4
int main()
{
    QFIFO* Q = QFCreate( NSIZE );
	QFITEM* F1 = ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F1->pTab = ( int* )calloc( 2,sizeof( int ) );
	F1->n_Key = 1;
	F1->pTab[0] = 1;
	QFITEM* F2= ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F2->pTab = ( int* )calloc( 2,sizeof( int ) );
	F2->n_Key = 2;
	F2->pTab[0] = 2;
	QFITEM* F3= ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F3->pTab = ( int* )calloc( 2,sizeof( int ) );
	F3->n_Key = 3;
	F3->pTab[0] = 3;
	QFITEM* F4= ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F4->pTab = ( int* )calloc( 2,sizeof( int ) );
	F4->n_Key = 4;
	F4->pTab[0] = 4;
	QFITEM* F5= ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F5->pTab = ( int* )calloc( 2,sizeof( int ) );
	F5->n_Key = 5;
	F5->pTab[0] = 5;
	QFITEM* F6= ( QFITEM* )calloc( 1,sizeof( QFITEM ) );
	F6->pTab = ( int* )calloc( 2,sizeof( int ) );
	F6->n_Key = 6;
	F6->pTab[0] = 6;
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
	QFClear( Q,freeItem );
	QFEnqueue( Q,F4 );
	QFEnqueue( Q,F5 );
	QFEnqueue( Q,F6 );
	printf( "%d ",QFDequeue( Q )->n_Key );
	QFRemove( &Q,freeItem );
}
void freeItem( const void* item )
{
	free( ( (QFITEM*) item)->pTab );
	free( ( (QFITEM*) item) );
}
