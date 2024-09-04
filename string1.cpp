#include <stdio.h>
#include <stdlib.h>

const int DEFAULT_SIZE = 12;

struct InputPrint
{
    int  size;
    char **ptr_to_str;
};

void  reset_to_zero( void *array, int size );
void  *my_recalloc( void *array, int size );
void  input( InputPrint *data );
void  print( InputPrint *data );
char*  input_str( );

int main()
{
    InputPrint data = {};

    input( &data );
    print( &data );

    return 0;
}

void reset_to_zero( void* array, int size )
{
    for ( int j = size; j < size * 2; j++ )
    {
        ( ( char * )array )[j] = 0;
    }
}

void *my_recalloc( void* array, int size )
{
    array = ( char * )realloc( array, size * 2 );
    reset_to_zero( array, size );
    return array;
}

void input( InputPrint *data )
{
    int  overall_size_for_ptr = DEFAULT_SIZE;

    data->ptr_to_str = ( char ** )calloc( DEFAULT_SIZE, sizeof( char * ) );

    scanf( "%d ", &data->size );

    for ( int i = 0; i < data->size; i++ )
    {
        int count_input_strings = 0;// TODO: fix this

        *( data->ptr_to_str + i ) = input_str( );

        count_input_strings += 1;

        if ( count_input_strings >= overall_size_for_ptr )
        {
            my_recalloc( data->ptr_to_str, overall_size_for_ptr );
        }

    }
}

void print( InputPrint *data )
{
    for ( int i = 0; i < data->size; i++ )
    {
        printf( "%s\n", *( data->ptr_to_str + i ) );
    }
}

char* input_str( )
{
    int  count_input_symbols = 0;
    int  overall_size_for_str = DEFAULT_SIZE;
    char ch = 0;

    char *str = ( char * )calloc( DEFAULT_SIZE, sizeof( char ) );

    while ( ( ch = getchar() ) != '\n' )
    {
        *( str + count_input_symbols ) = ch;

        count_input_symbols += 1;

        if ( count_input_symbols >= overall_size_for_str )
        {
           my_recalloc( str, overall_size_for_str );
        }
    }

    *( str + count_input_symbols ) = '\0';

    return str;
}

//hhhhaddduurr
//4h1a3d2u2
//
//RLE !!!
