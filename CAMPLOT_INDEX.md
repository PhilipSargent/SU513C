# CAMPLOT Library Index (from workspace sources)

This index lists routines whose names begin with `GR` and `GL` and that are referenced in the workspace Fortran sources. Descriptions are taken from in-file comments when present; usage locations point to files and approximate line contexts.

---

## Summary
- **Total unique `GR*` routines found:** 16 (in the scanned files)
- **Files scanned:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `su-austria.PLOT.f`, `SURVEY.SU513C.f`, `DefmMaps-fortran/*`

---

## Routines

### `GRAN5S(X,Y,STRING,LEN,ROT)`
- **Description:** "draw character string" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f` (many places for titles and scale labels)

---

### `GREND`
- **Description:** (no comment present — used to end plotting in `su-austria.PLOT.f`)
- **Used in:** `su-austria.PLOT.f`
- **Used in (also):** `DefmMaps-fortran/Maps.main.#186.f` (end of plot sequence)

---

### `GRFR2S`
- **Description:** "draw linear-linear frame" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`

---

### `GRFT2S(IFRAME,IMARK,IANNOT)`
- **Description:** "set frame type" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`

---

### `GRLM2S(XLOW,XHI,YLOW,YHI)`
- **Description:** "set plotter limits" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`, `DefmMaps-fortran/Maps.main.#186.f`, `DefmMaps-fortran/Source.#1.(186).f`

---

### `GRLM3S(XLOW,XHI,YLOW,YHI)`
- **Description:** "set user limits" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`
- **Note:** Uses `ASPECT` (see **ASPECT** section below).
- **Used in (also):** `DefmMaps-fortran/Maps.main.#186.f`, `DefmMaps-fortran/Source.#1.(186).f`

---

### `GRLM7S(IROT)`
- **Description:** "set rotation" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`, `su-austria.PLOTCAM.f`

---

### `GRMS3S(ASPECT)`
- **Description:** (no explicit comment beyond usage; used as alternative when package already initialised)
- **Used in:** `SURVEY.SUPLOT.f`
- **Note:** Accepts `ASPECT` to preserve plotting aspect ratio (see **ASPECT** section below).
- **Used in (also):** `DefmMaps-fortran/*` (occasional reconfiguration calls)

---

### `GRMS6S(n)`
- **Description:** (no comment present in these files)
- **Used in:** `su-austria.PLOTCAM.f`

---

### `GRPN5S(ICOL)`
- **Description:** "set colour for strings and titles" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f` (multiple places)
- **Used in (also):** `DefmMaps-fortran/Maps.main.#186.f` (colour changes for labels)

---

### `GRST2S(ASPECT)`
- **Description:** (no comment present in these files)
- **Used in:** `su-austria.PLOTCAM.f`
- **Note:** Accepts `ASPECT` to initialise the package with the correct aspect ratio (see **ASPECT** section below).
- **Used in (also):** `DefmMaps-fortran/*`

---

### `GRST3S(ASPECT,WIDTH)`
- **Description:** "initialise package" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f` (initial setup when first called)
- **Note:** Initialises CAMPLOT using `ASPECT` to set X/Y proportions (see **ASPECT** section below).
- **Used in (also):** `DefmMaps-fortran/Maps.main.#186.f` (called as `CALL GRST3S(1.2,300.0)`, i.e., a literal ASPECT is sometimes supplied)

---

### `GRTX2S(N,STYLE)`
- **Description:** (character/font selection helper — seen used to set axis fonts)
- **Used in:** `DefmMaps-fortran/Maps.main.#186.f`, `DefmMaps-fortran/Source.#1.(186).f`

---

### `GRTX4S(N,CHAR)`
- **Description:** (character map/setter; used in forming grids and labels)
- **Used in:** `DefmMaps-fortran/Maps.main.#186.f`

---

### `GRST9S`
- **Description:** "close package" (comment in `SURVEY.SUPLOT.f`).
- **Used in:**
  - `SURVEY.SUPLOT.f` (initial checks / exit path)
  - `su-austria.PLOTCAM.f` (end of plotting)
  - `SURVEY.SU513C.f` (EXIT command handling)

---

### `GRTX3S(N,CT1,CT2,CT3,CT4)`
- **Description:** "set shape and size of characters" (comment in `SURVEY.SUPLOT.f`).
- **Used in:** `SURVEY.SUPLOT.f`

---


## Additional CAMPLOT Routines
## GL* CAMPLOT Routines
## Other CAMPLOT Routines

- **KLCV3S(VALUE, N, D, IOPTS, ITEXT)**  
  Converts a number to a formatted string for annotation or labeling. Used for formatting numbers for plot labels.  
  Example: `IF(KLCV3S(VERSHN,5,2,IOPTS,ITEXT).LE.0) WRITE(6,200)VERSHN`

---

The following routines beginning with GL are also part of the CAMPLOT graphics library:

- **GLDV2S(N)**  
  Selects the plotting colour number.  
  Example: `CALL GLDV2S(2)`

- **GLMT2S(X, Y)**  
  Moves the plotting pen to the specified (X, Y) position without drawing.  
  Example: `CALL GLMT2S(X, Y)`

- **GLDT2S(X, Y)**  
  Draws a line from the current pen position to (X, Y).  
  Example: `CALL GLDT2S(X, Y)`

- **GLDB2S(X, Y)**  
  Draws a line by the vector (X, Y) from the current position.  
  Example: `CALL GLDB2S(0.0, SPACE)`

- **GLMB2S(X, Y)**  
  Moves the pen by the vector (X, Y) from the current position without drawing.  
  Example: `CALL GLMB2S(BAR1, SPACE)`

---


## ASPECT (aspect ratio) 🔧

- **Definition:** **ASPECT** is the aspect ratio of the plotting window, computed as **ASPECT = WXRNGE / WYRNGE** (length-to-width).

- **How it's computed (from `SURVEY.SUPLOT.f`):**

  PSCALE = PWIDTH * 0.001 * SCALE
  WXMIN  = PXR(1) / PSCALE
  WXMAX  = PXR(2) / PSCALE
  WYMIN  = PYR(1) / PSCALE
  WYMAX  = PYR(2) / PSCALE
  WXRNGE = WXMAX - WXMIN
  WYRNGE = WYMAX - WYMIN
  ASPECT = WXRNGE / WYRNGE

- **Used to:** configure CAMPLOT so X and Y scaling preserves proportions. Common usages found in the workspace:
  - `CALL GRST3S(ASPECT, PWIDTH)` — initialise CAMPLOT with aspect and paper width
  - `CALL GRMS3S(ASPECT)` — reconfigure/adjust using the same aspect
  - `CALL GRST2S(ASPECT)` — alternate initialization variant
  - `CALL GRLM3S(0., ASPECT, 0., 1.0)` — sets user limits so X ∈ [0, ASPECT] and Y ∈ [0, 1]

- **Practical meaning / example:** If WXRNGE = 200 and WYRNGE = 100 then ASPECT = 2.0 and the normalized plotting window becomes X ∈ [0, 2], Y ∈ [0, 1], keeping shapes proportionally correct on paper.


## Notes & Next steps
- The actual implementations (source code) of these `GR*` routines were not found in this workspace — they are part of the external CAMPLOT library. Only calls and inline comments were available here.
- If you want, I can:
  - Search other folders / your entire disk for CAMPLOT source implementing these routines.
  - Try to extract more complete signatures or behavior by looking for CAMPLOT docs or header files in nearby repositories or online.
  - Generate a CSV or more compact index for import into other tools.

---

If you'd like I can extend this index (search other paths, add exact line numbers or code snippets, or fetch CAMPLOT reference docs). What would you like me to do next? ✅
