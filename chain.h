//------------------------------------------------------------------------|
// Copyright (c) 2018-2019 by Raymond M. Foulk IV
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//------------------------------------------------------------------------|

#pragma once

#include <stddef.h>


//------------------------------------------------------------------------|
typedef struct link_t
{
    struct link_t * next;    // pointer to next node
    struct link_t * prev;    // pointer to previous node
    void * data;             // pointer to node's contents,
                             // caller is responsible for data size

    // consider adding data dtor fptr for heterogeneous link payloads
}
link_t;

typedef struct
{
    link_t * link;          // current link in chain
    link_t * orig;          // origin link in chain
    size_t length;          // list length
}
chain_t;

//------------------------------------------------------------------------|
typedef int (*link_compare_func_t) (const void *, const void *);
typedef void * (*link_copy_func_t) (void *);

//------------------------------------------------------------------------|
chain_t * chain_create();
void chain_destroy(chain_t * chain);
void chain_clear(chain_t * chain);          // remove all links (no data dtor!!)
void chain_insert(chain_t * chain);         // insert new link after & go to it
void chain_delete(chain_t * chain);         // delete current link & go back

int chain_move (chain_t *, long);		// rewind/forward a list
int chain_reset (chain_t *);			// reset to origin node

int chain_sort (chain_t *, _vpfunc2);		// sort using comparator
int chain_part (chain_t *, chain_t *, long, long); // partition list into 2

