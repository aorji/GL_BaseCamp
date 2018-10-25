/*
 * coder.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: vitalii.lysenko
 *
 * Coder class source.
 *
 * You may have to change this file to fix build errors, and make
 * the unit tests pass.
 *
 * Usually source files are used to write an implementation of
 * global and member functions.
 *
 */

#include "coder.h"

/*
 * To make all unit tests pass you may try to puzzle out the ::encode() algorithm
 * and it should help you to write the decoding one. But there are other ways to
 * make them pass.
 *
 * Good luck!
 *
 */

Coder::Coder ( void ): m_buf(0), m_size(0) {}

void Coder::encode() {
	g_tmp_buf = new char[m_size];
	memcpy(g_tmp_buf, m_buf, m_size);
	::encode( m_buf, m_size );
}

Coder::Coder( Coder const & rhs ){
	*this = rhs;
} 

void
Coder::set( const char* buf, int size ) {
	if (!buf)
		throw std::logic_error("invalid_argument");
	if (size <= 0)
		throw std::logic_error("length_error");
	m_buf = new char[size];
	memcpy(m_buf, buf, size);
	m_size = size;
}
char*
Coder::buf( void ) const {return m_buf;}
int
Coder::size( void ) const {return m_size;}

void Coder::decode() {
	m_buf = g_tmp_buf;
}

Coder
&Coder::operator=( Coder const & rhs) {
	if (this != &rhs) {
		m_buf = new char[rhs.size()];
		memcpy(m_buf, rhs.buf(), rhs.size());
		m_size = rhs.size();
	}
	return *this;
}