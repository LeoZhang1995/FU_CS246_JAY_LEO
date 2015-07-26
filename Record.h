//
//  Record.h
//  Chess_Project
//
//  Created by JiaJun Zhou on 2015-07-16.
//  Copyright (c) 2015 JiaJun Zhou. All rights reserved.
//

#ifndef __Chess_Project__Record__
#define __Chess_Project__Record__

#include <stdio.h>
#include "Board.h"

class Record{
protected:
    Board *Board_Status;
    Record *Next;
    Record *Previous;
    Record *Tail;
};

#endif /* defined(__Chess_Project__Record__) */
