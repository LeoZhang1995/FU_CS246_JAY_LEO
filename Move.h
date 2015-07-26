//
//  Move.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Move__
#define __Chess_Project__Move__

#include <stdio.h>
#include <string>

class Move{
protected:
    bool Check;
public:
    int Rating;
    bool Captured;
    std::string Origin;
    std::string Destination;
    std::string Captures;
    Move(bool Check, string Origin, string Destination, string Captures, bool Captured, int Rating);
};

#endif /* defined(__Chess_Project__Move__) */
