# CAMPLOT Library Index (from workspace sources)

This index lists routines whose names begin with `GR` and `GL` and that are referenced in the workspace Fortran sources. Descriptions are taken from in-file comments when present; usage locations point to files and approximate line contexts.

---

## Summary

* **Total unique `GR*` routines found:** 24
* **Files scanned:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `su-austria.PLOT.f`, `SURVEY.SU513C.f`, `DefmMaps-fortran/*`, `LRDA.SUBTRACT.f`, `LRDA.INTERP.f`

---

## Routines

### `GRAN5S(X,Y,STRING,LEN,ROT)`

* **Description:** "draw character string" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `LRDA.SUBTRACT.f`

### `GRAN6S(TITLE, LEN1, XLAB, LEN2, YLAB, LEN3)`

* **Description:** Draws a linear-linear plot frame including a main title, X-axis label, and Y-axis label.
* **Example:** `CALL GRAN6S(' ',1,'TIME/S',6,'GRADIENT',8)`

### `GREND`

* **Description:** (no comment present — used to end plotting).
* **Used in:** `su-austria.PLOT.f`, `DefmMaps-fortran/Maps.main.#186.f`

### `GRFR2S`

* **Description:** "draw linear-linear frame" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`, `LRDA.SUBTRACT.f`

### `GRFR6S(N)`

* **Description:** Draws a frame or grid; used with `1` or `-1` to initialize the plotting area for data points.
* **Example:** `CALL GRFR6S(1)`

### `GRFT2S(IFRAME,IMARK,IANNOT)`

* **Description:** "set frame type" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`, `LRDA.INTERP.f`

### `GRFT3S(X1,X2,N1,N2,X3,N3)`

* **Description:** Sets formatting or tick mark parameters for the X-axis.
* **Example:** `CALL GRFT3S(-3.,-1.5,4,8,0.,0)`

### `GRFT4S(X1,X2,N1,N2,X3,N3)`

* **Description:** Sets formatting or tick mark parameters for the Y-axis.
* **Example:** `CALL GRFT4S(-3.,-1.5,4,8,0.,0)`

### `GRGR6S(X_ARRAY, Y_ARRAY, N)`

* **Description:** Plots a data series (lines or points) using the provided X and Y arrays of length N.
* **Example:** `CALL GRGR6S(LTIMES,SREL,NTIMES)`

### `GRLM2S(XLOW,XHI,YLOW,YHI)`

* **Description:** "set plotter limits" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`, `LRDA.SUBTRACT.f`, `LRDA.INTERP.f`

### `GRLM3S(XLOW,XHI,YLOW,YHI)`

* **Description:** "set user limits" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `LRDA.SUBTRACT.f`, `LRDA.INTERP.f`

### `GRLM7S(IROT)`

* **Description:** "set rotation" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`

### `GRMS3S(ASPECT)`

* **Description:** Used as an alternative when the package is already initialised.
* **Used in:** `SURVEY.SUPLOT.f`

### `GRMS6S(n)`

* **Description:** (no comment present in these files).
* **Used in:** `su-austria.PLOTCAM.f`

### `GRPN3S(ICOL)`

* **Description:** Sets the pen or color index for frame-related plotting elements.
* **Example:** `CALL GRPN3S(2)`

### `GRPN4S(ICOL)`

* **Description:** Sets the pen or color index specifically for data curves or line segments.
* **Example:** `CALL GRPN4S(2)`

### `GRPN5S(ICOL)`

* **Description:** "set colour for strings and titles" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `LRDA.SUBTRACT.f`, `LRDA.INTERP.f`

### `GRST2S(ASPECT)`

* **Description:** Alternate initialization variant.
* **Used in:** `su-austria.PLOTCAM.f`, `DefmMaps-fortran/*`

### `GRST3S(ASPECT,WIDTH)`

* **Description:** "initialise package" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `DefmMaps-fortran/Maps.main.#186.f`

### `GRST9S`

* **Description:** "close package" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `SURVEY.SU513C.f`

### `GRTX2S(N,STYLE)`

* **Description:** Character/font selection helper.
* **Used in:** `DefmMaps-fortran/Maps.main.#186.f`

### `GRTX3S(N,CT1,CT2,CT3,CT4)`

* **Description:** "set shape and size of characters" (comment in `SURVEY.SUPLOT.f`).
* **Used in:** `SURVEY.SUPLOT.f`

### `GRTX4S(N,CHAR)`

* **Description:** Character map/setter used in forming grids and labels.
* **Used in:** `DefmMaps-fortran/Maps.main.#186.f`

### `GRTY5S(N, CHAR)`

* **Description:** Defines the character or symbol type used for plotting points.
* **Example:** `CALL GRTY5S(0,'*')`

---

## GL* CAMPLOT Routines

* **GLDV2S(N)**: Selects the plotting colour number.
* Example: `CALL GLDV2S(2)`


* **GLMT2S(X, Y)**: Moves the plotting pen to (X, Y) without drawing.
* Example: `CALL GLMT2S(X, Y)`


* **GLDT2S(X, Y)**: Draws a line from the current pen position to (X, Y).
* Example: `CALL GLDT2S(X, Y)`


* **GLDB2S(X, Y)**: Draws a line by the vector (X, Y) from the current position.
* Example: `CALL GLDB2S(0.0, SPACE)`


* **GLMB2S(X, Y)**: Moves the pen by the vector (X, Y) without drawing.
* Example: `CALL GLMB2S(BAR1, SPACE)`



---

## Other CAMPLOT Routines

* **BRKPLT(N)**
* **Description:** "Break Plot"; terminates current plot and advances to next page.
* **Example:** `CALL BRKPLT(8)`


* **DRAWTO(X, Y)**
* **Description:** Draws a line from the current position to the specified coordinates.
* **Example:** `CALL DRAWTO(8000.,ENDPT)`


* **KLCV3S(VALUE, N, D, IOPTS, ITEXT)**
* **Description:** Converts a number to a formatted string for labeling.
* **Example:** `IF(KLCV3S(VERSHN,5,2,IOPTS,ITEXT).LE.0) WRITE(6,200)VERSHN`


* **LOCCHR(X, Y)**
* **Description:** "Locate Character"; sets the coordinates for text output.
* **Example:** `CALL LOCCHR(130.,65.)`


* **MOVETO(X, Y)**
* **Description:** Moves the pen to coordinates (X, Y) without drawing.
* **Example:** `CALL MOVETO(190.,3.)`


* **PEN(N)**
* **Description:** Selects a specific pen/color number.
* **Example:** `CALL PEN(1)`


* **PLTCHR(N)**
* **Description:** Plots a specific symbol (e.g., 78 for a cross).
* **Example:** `CALL PLTCHR(78)`


* **TRMCHR(A, B, C, D)**
* **Description:** "Terminal Character"; sets character height, orientation, and size.
* **Example:** `CALL TRMCHR(2.4,0.,0.,4.)`



---

## ASPECT (aspect ratio) 🔧

* **Definition:** **ASPECT** is the aspect ratio of the window, computed as **WXRNGE / WYRNGE**.
* **How it's computed (from `SURVEY.SUPLOT.f`):**
```fortran
PSCALE = PWIDTH * 0.001 * SCALE
WXMIN  = PXR(1) / PSCALE
WXMAX  = PXR(2) / PSCALE
WYMIN  = PYR(1) / PSCALE
WYMAX  = PYR(2) / PSCALE
WXRNGE = WXMAX - WXMIN
WYRNGE = WYMAX - WYMIN
ASPECT = WXRNGE / WYRNGE

```


* **Common usages:**
* `CALL GRST3S(ASPECT, PWIDTH)`
* `CALL GRMS3S(ASPECT)`
* `CALL GRLM3S(0., ASPECT, 0., 1.0)`
