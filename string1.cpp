#include <stdio.h>
#include <stdlib.h>

const int DEFAULT_SIZE = 12;

int  size_1 = 0;
char **ptr_to_str = NULL;

void reset_to_zero( void *array_, int size );
void *my_recalloc( void *array_, int size );
void input( int *size_1 );
void print( int size_1 );

int main()
{
    void input( );
    void print( int size_1 );
    return 0;
}

void reset_to_zero( void* array_, int size )
{
    for ( int j = size; j < size * 2; j++ )
    {
        ( ( char * )array_ )[j] = 0;
    }
}

void *my_recalloc( void* array_, int size )
{
    array_ = ( char * )realloc( array_, size * 2 );
    reset_to_zero( array_, size );
    return array_;
}

void input( int *size_1 )
{
    char *str = NULL;
    int  overall_size_for_ptr = DEFAULT_SIZE;

    ptr_to_str = ( char ** )calloc( DEFAULT_SIZE, sizeof( char * ) );

    scanf( "%d ", &size_1 );

    for ( int i = 0; i < ( int )size_1; i++ )
    {
        int count_input_symbols = 0;
        int count_input_strings = 0;
        char ch = 0;
        int overall_size_for_str = DEFAULT_SIZE;

        str = ( char * )calloc( DEFAULT_SIZE, sizeof( char ) );

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

        *( ptr_to_str + i ) = str;
        count_input_strings += 1;

        if ( count_input_strings >= overall_size_for_ptr )
        {
            my_recalloc( ptr_to_str, overall_size_for_ptr );
        }

    }
}

void print( int size_1, char **ptr_to_str )
{
    for ( int i = 0; i < size_1; i++ )
    {
        printf( "%s\n", *( ptr_to_str + i ) );
    }
}

