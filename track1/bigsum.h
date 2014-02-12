/*
 * bigsum.h
 * Copyright (C) 2014-02-02 
 * Author:      keira 
 * Email:       %MAIL%
 * Function:    
 */

#ifndef __bigsum_h__
#define __bigsum_h__

#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>

std::string bigsum(const std::string&, const std::string&);
std::string rbigsum(const std::string&, const std::string&);

std::string bigprod(const std::string&, const std::string&);
std::string rbigprod(const std::string&, const std::string&);

std::vector<uint32_t> primes_generator(uint32_t);


#endif /* !__bigsum_h__ */

