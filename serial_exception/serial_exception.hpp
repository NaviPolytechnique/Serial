//
//  serial_exception.h
//  Serial
//
/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//

#ifndef __Serial__serial_exception__
#define __Serial__serial_exception__

#include <stdio.h>
#include <iostream>
#include <exception>


class serial_exception : public std::exception {
public:
    
    
    serial_exception(int number, std::string const& phrase, int level) throw() : m_number(number), m_phrase(phrase), m_level(level)
    {}
    
    
    const char* what() const throw()
    {
        return m_phrase.c_str();
    }
    
    int getLevel() const throw()
    {
        return m_level;
    }
    
    ~serial_exception() throw()
    {
    }
    
private:
    int m_number;
    std::string m_phrase;
    int m_level;
};








#endif /* defined(__Serial__serial_exception__) */
