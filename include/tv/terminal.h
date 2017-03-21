/*
 *      Turbo Vision - Version 2.0
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *

Modified by Robert H�hne to be used for RHIDE.

 *
 *
 */

#if defined( Uses_TTerminal ) && !defined( __TTerminal )
#define __TTerminal

class TRect;
class TScrollBar;

class CLY_EXPORT TTerminal: public TTextDevice
{

public:

    TTerminal( const TRect& bounds,
	       TScrollBar *aHScrollBar,
	       TScrollBar *aVScrollBar,
	       uint32_t aBufSize
	     );
    virtual ~TTerminal();

    virtual int do_sputn( const char *s, int count );

    void bufInc(uint32_t& val) { if (++val>=bufSize) val=0; }
    Boolean canInsert( uint32_t amount );
    short calcWidth();
    virtual void draw();
    uint32_t nextLine( uint32_t pos );
    uint32_t prevLines( uint32_t pos, uint32_t lines );
    Boolean queEmpty();

protected:

    uint32_t bufSize;
    char *buffer;
    uint32_t queFront, queBack;
    void bufDec(uint32_t& val) { if (val==0) val=bufSize - 1; else val--; }
};

#endif  // Uses_TTerminal

