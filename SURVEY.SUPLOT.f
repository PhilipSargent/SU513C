C    Updated    19.22    8 December 1984   PMS1
C
      SUBROUTINE SUPLOT(SCALE,PXR,PYR,PX,PY,IF,IT)
C
C Graphics dependent software - subroutine to plot paper coordinates
C
C Version 1.00 for Plan/elev 1.20 A Waddington        1983.08.26
C Version 2.05 for Plan/elev using CAMPLOT, P.Sargent 1984.10.29
C
      INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
      INTEGER IF(NO),IT(NO)
      INTEGER IOPTS(2),IFLAG
C
      CHARACTER*5 ITEXT
      CHARACTER*48 TITLE
C
      REAL    MARK
      REAL    PXR(2),PYR(2),PX(LISTLN),PY(LISTLN)
      REAL    LENGTH,VERSHN,PLANLN,DEC,CLINO
C
      LOGICAL INFEET,UWATER
C
      COMMON /SUBLK/ VERSHN,INFEET,UWATER,LENGTH,PLANLN,DEC,CLINO
      COMMON /TITL / TITLE
      COMMON  /PARMS/ SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
      COMMON  /SIZES/ SIZE,DBSIZE,NO,LISTLN
C
      SAVE IFLAG
C
      DATA IOPTS /0,0/
      DATA IFLAG / 0 /
      DATA PVERSH / 2.05 /
      DATA PWIDTH / 300.0 /
C
C  GRST9S - close package
C
      IF (ABS(SCALE).LE.1.0E-3) THEN
         CALL GRST9S
         RETURN
      ENDIF
C                                          Friday  2 November 1984   |
C          When the program obeys the EXIT command from the          |
C          terminal, the main program calls SUPLOT with SCALE = 0.0  |
C          which means that the plotter package should be wound up.  |
C
      WRITE(6,120)TITLE
      WRITE(SYSOUT,140)PVERSH
      WRITE(SYSOUT,130)SCALE,PWIDTH
C
C         PWIDTH is in mm, all the rest is in metres.
      PSCALE = PWIDTH * 0.001 * SCALE
      WXMIN  = PXR(1) / PSCALE
      WXMAX  = PXR(2) / PSCALE
      WYMIN  = PYR(1) / PSCALE
      WYMAX  = PYR(2) / PSCALE
C
      BAR   =  1.0/(PYR(2)-PYR(1))
C
C         MARK is scaled to be always 1mm on the paper
      MARK   = 0.001  * SCALE
      WXRNGE = WXMAX - WXMIN
      WYRNGE = WYMAX - WYMIN
      ASPECT = WXRNGE/WYRNGE
      IF(WYRNGE.GT.1.) GOTO 100
      IF(WXRNGE.GT.6.) GOTO 110
      WRITE(6,150)PXR(1),PXR(2),PYR(1),PYR(2)
      WRITE(6,160)WXRNGE,WYRNGE
      WRITE(6,170)PSCALE,ASPECT
C                                                                    |
C          IFLAG makes sure that the plotter package is only         |
C          initialised on the first call to SUPLOT and that          |
C          subsequent calls only start a new 'page.                  |
C                                                                    |
C
C Set up the window in paper space, PWIDTH mm wide
C
C  GRST3S(ASPECT,WIDTH) - initialise package
C
      IF (IFLAG.EQ.0) THEN
         CALL GRST3S(ASPECT,PWIDTH)
      ELSE
         CALL GRMS3S(ASPECT)
      ENDIF
      IFLAG = IFLAG + 1
C
C  GRLM2S(XLOW,XHI,YLOW,YHI) - set plotter limits
      CALL GRLM2S(0.,WYRNGE,0.,WXRNGE)
C
C  GRLM7S(IROT) - set rotation
      CALL GRLM7S(1)
C
C  GRLM3S(XLOW,XHI,YLOW,YHI) - set user limits
      CALL GRLM3S(0.,ASPECT,0.,1.0)
C
C  Plot title labels and scale bar
C
      SPCING=0.033
      START = 1.0-SPCING
C
C  GRPN5S(ICOL) - set colour for strings and titles
      CALL GRPN5S(3)
C
C  GRTX3S(N,CT1,CT2,CT3,CT4) - set shape and size of characters
      CALL GRTX3S(1,1.1,0.0,0.0,1.1)
      OFFSET=0.01
C
C  GRAN5S(X,Y,STRING,LEN,ROT) - draw character string
      CALL GRAN5S(OFFSET,START,TITLE,48,0.0)
C
C  GRPN5S(ICOL) - set colour for strings and titles
      CALL GRPN5S(1)
C
      START = START - SPCING
C
C  GRAN5S(X,Y,STRING,LEN,ROT) - draw character string
      CALL GRAN5S(OFFSET,START,'SU   version ',13,0.0)
      IF(KLCV3S(VERSHN,5,2,IOPTS,ITEXT).LE.0) WRITE(6,200)VERSHN
      CALL GRAN5S(0.15,START,ITEXT,5,0.0)
C
      START = START - SPCING
C
C  GRAN5S(X,Y,STRING,LEN,ROT) - draw character string
      CALL GRAN5S(OFFSET,START,'PLOT version ',13,0.0)
C
      IF(KLCV3S(PVERSH,5,2,IOPTS,ITEXT).LE.0) WRITE(6,200)PVERSH
      CALL GRAN5S(0.15,START,ITEXT,5,0.0)
C
      START = START - SPCING
C
C  GRAN5S(X,Y,STRING,LEN,ROT) - draw character string
      CALL GRAN5S(OFFSET,START,'Scale is 1 :',12,0.0)
C
C
      IF(KLCV3S(SCALE,5,0,IOPTS,ITEXT).LE.0) WRITE(6,200)SCALE
      CALL GRAN5S(0.12,START,ITEXT,5,0.0)
C
      START = START - SPCING
C
C  GRPN5S(ICOL) - set colour for strings and titles
      CALL GRPN5S(2)
C
C  GLDV2S(N) - Select colour number
      CALL GLDV2S(2)
C
      START = START - SPCING
C
      IF(WXRNGE*PSCALE.LT.55) THEN
        CALL GRAN5S(OFFSET,START,'5 m scale bar',13,0.0)
        START = START - SPCING
        CALL SCABAR(5,5,BAR,OFFSET,START,0.01)
      ELSE IF(WXRNGE*PSCALE.LT.220.) THEN
        CALL GRAN5S(OFFSET,START,'50m scale bar',13,0.0)
        START = START - SPCING
        CALL SCABAR(50,5,BAR,OFFSET,START,0.01)
      ELSE IF(WXRNGE*PSCALE.LT.550.) THEN
        CALL GRAN5S(OFFSET,START,'200m scale bar',14,0.0)
        START = START - SPCING
        CALL SCABAR(200,20,BAR,OFFSET,START,0.01)
      ELSE IF(WXRNGE*PSCALE.LT.1100.) THEN
        CALL GRAN5S(OFFSET,START,'500m scale bar',14,0.0)
        START = START - SPCING
        CALL SCABAR(500,5,BAR,OFFSET,START,0.01)
      ELSE
        CALL GRAN5S(OFFSET,START,'1 km scale bar',14,0.0)
        START = START - SPCING
        CALL SCABAR(1000,10,BAR,OFFSET,START,0.01)
      ENDIF
C
C Set up window in 'ground metres' and draw the cave
C
C
C  GRLM3S(XLOW,XHI,YLOW,YHI) - set user limits
      CALL GRLM3S(PXR(1),PXR(2),PYR(1),PYR(2))
C
C  GRFT2S(IFRAME,IMARK,IANNOT) - set frame type
      CALL GRFT2S(1,0,0)
C
C  GRFR2S - draw linear-linear frame
      CALL GRFR2S
C
C  GLDV2S(N) - Select colour number
      CALL GLDV2S(1)
C
C                                          Saturday  3 November 1984 |
C          Begin the point plotting loop. This draws a 'x' at the    |
C          beginning of each leg, and a '+' at the end of each leg.  |
C          It checks whether any point will be plotted outside the   |
C          frame and prints a warning message if that is the case.   |
C                                                                    |
      DO 10 K=1,NO
C
      IF (PX(IF(K)).GE.PXR(2)) WRITE (TTYOUT,20)
      IF (PX(IF(K)).LE.PXR(1)) WRITE (TTYOUT,30)
      IF (PY(IF(K)).GE.PYR(2)) WRITE (TTYOUT,40)
      IF (PY(IF(K)).LE.PYR(1)) WRITE (TTYOUT,50)
C
      IF (PX(IT(K)).GE.PXR(2)) WRITE (TTYOUT,60)
      IF (PX(IT(K)).LE.PXR(1)) WRITE (TTYOUT,70)
      IF (PY(IT(K)).GE.PYR(2)) WRITE (TTYOUT,80)
      IF (PY(IT(K)).LE.PYR(1)) WRITE (TTYOUT,90)
C
C
C  GLMT2S(X,Y) - Move to
         CALL GLMT2S( PX(IF(K)) , PY(IF(K)) )
C
         CALL CROSS(MARK,1)
C
C  GLDT2S(X,Y) - Draw to
         CALL GLDT2S( PX(IT(K)) , PY(IT(K)) )
C
         CALL CROSS(MARK,0)
   10 CONTINUE
C
   20 FORMAT(' First  end of leg is greater than X range.')
   30 FORMAT(' First  end of leg is less    than X range.')
   40 FORMAT(' First  end of leg is greater than Y range.')
   50 FORMAT(' First  end of leg is less    than Y range.')
C
   60 FORMAT(' Second end of leg is greater than X frame range.')
   70 FORMAT(' Second end of leg is less    than X frame range.')
   80 FORMAT(' Second end of leg is greater than Y frame range.')
   90 FORMAT(' Second end of leg is less    than Y frame range.')
C
      RETURN
  100 WRITE(TTYOUT,180)WYRNGE
      RETURN
  110 WRITE(TTYOUT,190)WXRNGE
      RETURN
C
  120 FORMAT(1X,A48/)
  130 FORMAT(' Plotting scale is 1 :',F8.2,
     1'  assuming plotter width of ',F8.3,'mm'/)
  140 FORMAT(' Implementation-dependent SUPLOT version ',F5.2/)
  150 FORMAT(' Plot window in ground metres:'/
     1'   Length axis',2F11.3/
     2'   Width axis ',2F11.3//)
  160 FORMAT(' Window in fractions of paper width:'/
     1'   Length',F11.3/
     2'   Width ',F11.3//)
  170 FORMAT(' Paper width in ground metres is ',F11.3,'m'//
     1' Aspect ratio (length to width) of window is ',F11.3//)
  180 FORMAT('  Coordinate range exceeds paper height :',F6.3)
  190 FORMAT('  X-range exceeds undocumented maximum length:',F6.3)
  200 FORMAT(' ##### Number incorrectly formatted by CAMPLOT: ',F15.4/)
      END
C
C--------------------------------------------------------------------+
C
      SUBROUTINE SCABAR(LBAR,LEN,BAR,START,HEIGHT,SPACE)
C
      BARX = BAR * LBAR
C
C  GLMT2S(X,Y) - Move to
      CALL GLMT2S(START,HEIGHT)
C
C  GLDB2S(X,Y) - Draw by
      CALL GLDB2S(BARX,0.0)
C
C  GLDB2S(X,Y) - Draw by
      CALL GLDB2S(0.0,SPACE)
C
C  GLDB2S(X,Y) - Draw by
      CALL GLDB2S(-BARX,0.0)
      BAR10 = BARX / FLOAT(LEN)
      BAR1  = BAR10/10.
      DO 10 J=1,10
C
C  GLDB2S(X,Y) - Draw by
      CALL GLDB2S(0.0,-SPACE)
C
C  GLMB2S(X,Y) - Move by
      CALL GLMB2S(BAR1,SPACE)
   10 CONTINUE
      IEND = LEN - 1
      DO 20 J=1,IEND
C
C  GLDB2S(X,Y) - Draw by
      CALL GLDB2S(0.0,-SPACE)
C
C  GLMB2S(X,Y) - Move by
      CALL GLMB2S(BAR10,SPACE)
   20 CONTINUE
      RETURN
      END
C
C--------------------------------------------------------------------+
C
      SUBROUTINE CROSS(X,IANG)
      REAL X,X2
C
      X2= X/2.0
      CALL GLDV2S(2)
C
      IF (IANG.EQ.0) THEN
         CALL GLMB2S(-X2,0.)
         CALL GLDB2S(X,0.)
         CALL GLMB2S(-X2,-X2)
         CALL GLDB2S(0.,X)
         CALL GLMB2S(0,-X2)
      ELSE
         CALL GLMB2S(-X2,-X2)
         CALL GLDB2S(X,X)
         CALL GLMB2S(-X,0.)
         CALL GLDB2S(X,-X)
         CALL GLMB2S(-X2,X2)
      ENDIF
C
      CALL GLDV2S(1)
      RETURN
      END
