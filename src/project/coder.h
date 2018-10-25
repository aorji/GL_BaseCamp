/*
 * coder.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class header.
 *
 * You have to change this file to fix build errors, and make
 * the unit tests passed.
 *
 */

#ifndef CODER_H
#define CODER_H

/*
 * This function was pre-compiled and is provided as a part of the
 * static library.
 *
 */

void encode( char* buf, int size );

/*
 * Coder class header.
 *
 */
static	char *g_tmp_buf;

#include <iostream>
#include <cstring>
#include <pthread.h>

#include <stdexcept>

class Coder {
public:

	Coder( void );
	Coder( Coder const & rhs );
	void	set( const char* buf, int size );
	char*	buf( void ) const;
	int		size( void ) const;

	void	encode( void );
	void	decode( void );

	Coder & operator=( Coder const & rhs);
private:
	char*	m_buf;
	int		m_size;
};

#endif // CODER_H
