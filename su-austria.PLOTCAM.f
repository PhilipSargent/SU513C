      SUBROUTINE PLOT(SCALE,PXR,PYR,PX,PY,IF,IT)
C
C Graphics dependent software - subroutine to plot paper coordinates
C
C Version 1.00 for Plan/elev 1.20 A Waddington 1983.08.26
C Version 2.01 for Plan/elev using CAMPLOT, P.Sargent 1984.04.03
C
      INTEGER SIZE,DBSIZE,SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
      INTEGER IF(NO),IT(NO)
      REAL    PXR(2),PYR(2),PX(LISTLN),PY(LISTLN)
      COMMON  /PARMS/ SYSIN,PCIN,TTYIN,DBASE,TTYOUT,SYSOUT
      COMMON  /SIZES/ SIZE,DBSIZE,NO,LISTLN
      DATA PWIDTH / 0.31 /
      WRITE(SYSOUT,2000)SCALE,PWIDTH
      PSCALE = PWIDTH * SCALE
      WXMIN  = PXR(1) / PSCALE
      WXMAX  = PXR(2) / PSCALE
      WYMIN  = PYR(1) / PSCALE
      WYMAX  = PYR(2) / PSCALE
      WXRNGE = WXMAX - WXMIN
      WYRNGE = WYMAX - WYMIN
      ASPECT = WXRNGE/WYRNGE
      IF(WYRNGE.GT.1.) GOTO 900
      IF(WXRNGE.GT.6.) GOTO 901
C
C Plot the data into the required window area:
C
      CALL GRST2S(ASPECT)
      CALL GRMS6S(2)
      CALL GRLM2S(0.,WYRNGE,0.,WXRNGE)
      CALL GRLM7S(1)
      CALL GRLM3S(PXR(1),PXR(2),PYR(1),PYR(2))
      CALL GRFT2S(1,0,0)
      CALL GRFR2S
      CALL GLDV2S(1)
      DO 250 K=1,NO
         CALL GLMT2S( PX(IF(K)) , PY(IF(K)) )
         CALL GLDT2S( PX(IT(K)) , PY(IT(K)) )
  250 CONTINUE
      CALL GRST9S
      RETURN
  900 WRITE(TTYOUT,2090)WYRNGE
      RETURN
  901 WRITE(TTYOUT,2091)WXRNGE
      RETURN
 2000 FORMAT('0 Plotting scale is 1 :',I5,'  assuming plotter width of'
     &,F5.3,'m')
 2090 FORMAT('  Coordinate range exceeds paper height :',F6.3)
 2091 FORMAT('  X-range exceeds undocumented maximum length:',F6.3)
      END

