//-------------------------------------------------------------------
//-------------------------------------------------------------------
//
// Cleaver - A MultiMaterial Conforming Tetrahedral Meshing Library
//
// -- Utilities
//
// Author: Jonathan Bronson (bronson@sci.utah.ed)
//
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//
//  Copyright (C) 2011, 2012, Jonathan Bronson
//  Scientific Computing & Imaging Institute
//  University of Utah
//
//  Permission is  hereby  granted, free  of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files  ( the "Software" ),  to  deal in  the  Software without
//  restriction, including  without limitation the rights to  use,
//  copy, modify,  merge, publish, distribute, sublicense,  and/or
//  sell copies of the Software, and to permit persons to whom the
//  Software is  furnished  to do  so,  subject  to  the following
//  conditions:
//
//  The above  copyright notice  and  this permission notice shall
//  be included  in  all copies  or  substantial  portions  of the
//  Software.
//
//  THE SOFTWARE IS  PROVIDED  "AS IS",  WITHOUT  WARRANTY  OF ANY
//  KIND,  EXPRESS OR IMPLIED, INCLUDING  BUT NOT  LIMITED  TO THE
//  WARRANTIES   OF  MERCHANTABILITY,  FITNESS  FOR  A  PARTICULAR
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT  SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS  BE  LIABLE FOR  ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
//  USE OR OTHER DEALINGS IN THE SOFTWARE.
//-------------------------------------------------------------------
//-------------------------------------------------------------------

#ifndef UTIL_H
#define UTIL_H

#include "TetMesh.h"
#include "vec3.h"
#include "Vertex.h"
#include <json/json.h>

#include <string>
#include <exception>


namespace cleaver
{
    enum ordering { row , col };

    double pow2(int p);

    bool triangle_intersection(Vertex *v1, Vertex *v2, Vertex *v3,
        vec3 origin, vec3 ray, vec3 &pt, float epsilon = 1E-8);

    Json::Value vertex_to_json(Vertex *vertex);
    Json::Value tet_to_json(Tet *tet, TetMesh *mesh, bool includeInterfaces = true);

    class CleaverException : public std::exception
    {
    public:
        CleaverException(std::string s) throw(): msg(s) { }
        ~CleaverException() throw() { }

        virtual const char* what() const throw() { return msg.c_str(); }
    private:
        std::string msg;
    };
}

#endif // UTIL_H
