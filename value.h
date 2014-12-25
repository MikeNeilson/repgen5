/*
    Copyright (c) 2014, <copyright holder> <email>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef VALUE_H
#define VALUE_H
#include <string>
#include <vector>
#include <ctime>

using namespace std;


const int STRING_VAL=1;
const int DOUBLE_VAL=2;
const int TIME_VAL=3;


const time_t NULL_TIME = (time_t)(-1);

class Value
{
	public:
		vector<double> double_value;
		vector< time_t > time_value;
		vector< string > string_value;
		
		size_t size;// should need this now
		size_t index; // used by the report
		
		string picture;		
		string rounding;
		string missing;
		
		int    type; // string or int or time
		bool   scalar; // is this a scalar value
		

	public:
		Value( string &picture, string &missing, string rounding, int type ){ this->picture = picture; this->type = type;  this->rounding = rounding, index=0; size=0; this->missing = missing;}
		Value( const char *picture, const char *missing, const char *rounding, int type ){ this->picture = picture; this->type = type;  this->rounding = rounding, index=0; size=0; this->missing = missing;}
		Value(){};
		
		int get_type(){ return type; }		
		bool is_string(){ return type == STRING_VAL; }
		bool is_double(){ return type == DOUBLE_VAL; }		
		bool is_time(){ return type == TIME_VAL; }
		
		
		time_t get_time( size_t i );
		double get_double_val( size_t i );
		string get_string_val( size_t i );
		string get_formatted( size_t i );
				
};

#endif // VALUE_H