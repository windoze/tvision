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

/* ---------------------------------------------------------------------- */
/*      class TScrollBar                                                  */
/*                                                                        */
/*      Palette layout                                                    */
/*        1 = Page areas                                                  */
/*        2 = Arrows                                                      */
/*        3 = Indicator                                                   */
/* ---------------------------------------------------------------------- */

#if defined( Uses_TScrollBar ) && !defined( __TScrollBar )
#define __TScrollBar

class TRect;
struct TEvent;

typedef char TScrollChars[5];

class CLY_EXPORT TScrollBar : public TView
{

public:

    TScrollBar( const TRect& bounds );

    virtual void draw();
    virtual TPalette& getPalette() const;
    virtual void handleEvent( TEvent& event );
    virtual void scrollDraw();
    virtual int scrollStep( int part );
    void setParams( int32_t aValue, int32_t aMin, int32_t aMax,
                    int aPgStep, int aArStep );
    void setRange( int32_t aMin, int32_t aMax );
    void setStep( int aPgStep, int aArStep );
    void setValue( int32_t aValue );

    void drawPos( int pos );
    int32_t getPos();
    int getSize();

    int32_t value;

    TScrollChars chars;
    int32_t minVal;
    int32_t maxVal;
    int pgStep;
    int arStep;

    static TScrollChars vChars;
    static TScrollChars hChars;
    static TScrollChars ovChars;
    static TScrollChars ohChars;

private:

    int getPartCode(void);

#if !defined( NO_STREAM )
    virtual const char *streamableName() const
     { return name; }

protected:

    TScrollBar( StreamableInit );
    virtual void write( opstream& );
    virtual void *read( ipstream& );

public:

    static const char * const name;
    static TStreamable *build();
#endif // NO_STREAM
};

#if !defined( NO_STREAM )
inline ipstream& operator >> ( ipstream& is, TScrollBar& cl )
    { return is >> (TStreamable&)cl; }
inline ipstream& operator >> ( ipstream& is, TScrollBar*& cl )
    { return is >> (void *&)cl; }

inline opstream& operator << ( opstream& os, TScrollBar& cl )
    { return os << (TStreamable&)cl; }
inline opstream& operator << ( opstream& os, TScrollBar* cl )
    { return os << (TStreamable *)cl; }
#endif // NO_STREAM
#endif  // Uses_TScrollBar

